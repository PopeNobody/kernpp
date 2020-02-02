#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <errno.h>
#include "c_str.hh"
namespace sys {
  void perror(const c_str &msg);
  void pexit(const c_str &msg);
  void pexit(const c_str &msg1, const c_str &msg2);
  void perror(const c_str &msg1, const c_str &msg2);
};
#include <vector>
#include "write_buf.hh"
#include "debug.hh"

extern "C" {
  char *strerror(int errnum);
};

using std::vector;
using std::map;

#define SIGALRM 14

ssize_t sys::set_errno(ssize_t val)
{
  if(val<0) {
    *::__errno_location()=-val;
    return -1;
  } else {
    return val;
  };
};
int write(int fd, const c_str &str){
  return sys::write(fd,str.beg,str.len());
};
//   typedef void (*sighandler_t)(int);
//   sighandler_t signal(int signum, sighandler_t handler);

#define L(x) x,sizeof(x)-1

static write_buf<> err(2);
bool show_stats() {
  static time_t last=sys::time(0);
  time_t curr=sys::time(0);
  if(last == curr)
    return false;
  last=curr;
  return true;
};
using sys::pexit;

template<typename cont_t>
void save_joins(const char *name, const cont_t &cont) {
  size_t len=strlen(name);
  char temp[len+5];
  memcpy(temp,name,len);
  memcpy(temp+len,".new",5);  
  int db = open(temp,sys::o_wronly|sys::o_creat,sys::o_default);
  if(db<0)
    pexit("open:",name);
  write_buf<> buf(db);
  for(int i=0;i<cont.size();i++){
    buf.fmt(cont[i].pkg);
    buf.put(" ");
    buf.fmt(cont[i].name);
    buf.put(" ");
    buf.fmtln(cont[i].path);
  };
//     if(sys::close(db)<0)
//       pexit("close",name);
  if(sys::rename(temp,name)<0)
    pexit("rename");
};

struct str_tab {
  vector<c_str> strs;
  vector<int> idxs;
  int last_idx;
  int rep;
  int tot;
  str_tab()
    : last_idx(0), rep(0), tot(0)
  {
  };
  // Return the index where the value is, or if it is not present,
  // the index where it would be inserted.
  int insert_idx(const c_str &val)
  {
    int pos;
    for(pos=0; pos<size(); pos++) {
      if(c_str::cmp(strs[idxs[pos]],val)>=0)
        break;
    };
    return pos;
  };
  int btree_idx(const c_str &val)
  {
    int beg(0), end(size());
    while(beg!=end) {
      int mid=beg+(end-beg)/2;
      int res=c_str::cmp(strs[idxs[mid]],val);
      if(res<0) {
        beg=mid+1;
      } else if ( res > 0 ) {
        end=mid;
      } else {
        return mid;
      };
    };
    return beg;
  };
  int idx(const c_str &val) {
    assert(val.len()<256);
    return btree_idx(val);
  };
  const c_str &operator[](int idx) const
  {
    if(idx>=size()){
      debug(idx);
      debug(size());
      assert(idx<size());
    };
    return strs[idx];
  };
  int size()const {
    return strs.size();
  };
  int add(c_str val)
  {
    ++tot;
    assert(val.len()<256);
    size_t len=val.len();
    if(last_idx < size() && strs[idxs[last_idx]]==val)
    {
      ++rep;
      return last_idx;
    };
    int pos=idx(val);
    
    if(pos==size()){
      // Insert at end.  Of physical strings, and at end
      // of sorted range.  this is the case where the list
      // is empty, so below cases can assume there is an
      // object at strs[pos]
      strs.push_back(val);
      idxs.push_back(pos);
    } else if (strs[idxs[pos]]!=val) {
      // this will be at least zero, or the first case would
      // have caught.
      int tgt=strs.size();
      strs.push_back(val);
      idxs.push_back(-1);
      for(int i=pos;i<idxs.size();i++){
        int tmp=idxs[i];
        idxs[i]=tgt;
        tgt=tmp;
      };
    };
    last_idx=pos;
    return pos;
  };
};
size_t save_dat(const char *name, const str_tab &cont) {
  {
    err.put("saving '");
    err.put(name);
    err.put("' with ");
    err.fmt(cont.size());
    err.putln(" strings");
    err.flush();
  };
  char temp[strlen(name)+5];
  int db;
  {
    int i;
    for(i=0;name[i];i++)
      temp[i]=name[i];
    temp[i++]='.';
    temp[i++]='n';
    temp[i++]='e';
    temp[i++]='w';
    db = open(temp,sys::o_wronly|sys::o_creat,sys::open_mode(0644));
  };
  if(db<0)
    sys::pexit("open:",name);
  write_buf<> buf(db);
  size_t lines=0;
  for(size_t b(1), e(cont.size()); b!=e; b++) {
    buf.putln(cont[b]);
    ++lines;
  };
  buf.flush();
  err.putln("done saving");
  err.put("wrote ");
  err.fmt(buf.tot);
  err.putln(" bytes");
  err.flush();
//     if(sys::close(db)<0)
//       pexit("close:",name);
  if(sys::rename(temp,name)<0)
    pexit("rename");
};

struct str_len_tab {
  str_tab tabs[256];
  int tot;
  int idx(const c_str &val) {
    int len=val.len();
    str_tab &tab=tabs[len];
    int pos=tab.idx(val);
    return len | pos*256;
  };
  const c_str &operator[](int idx) const
  {
    assert(idx<size());
    int len=idx&0xff;
    int pos=idx/256;
    return tabs[len][pos];
  };
  int size()const {
    return tot;
  };
  int add(c_str val)
  {
    int len=val.len();
    assert(len<256);
    int pos=tabs[len].add(val);
    if(pos==tabs[len].size()-1)
      tot++;
    return len+pos*256;
  };
};
size_t save_dat(const char *name, const str_len_tab &cont)
{
  if(true) {
    err.put("saving '");
    err.put(name);
    err.put("' with ");
    err.fmt(cont.size());
    err.putln(" strings");
    err.flush();
  };
  char temp[strlen(name)+5];
  int db;
  {
    int i;
    for(i=0;name[i];i++)
      temp[i]=name[i];
    temp[i++]='.';
    temp[i++]='n';
    temp[i++]='e';
    temp[i++]='w';
    db = open(temp,sys::o_wronly|sys::o_creat,sys::open_mode(0644));
  };
  if(db<0)
    pexit("open:",name);
  write_buf<> buf(db);
  size_t lines=0;
  for(int len=1;len<sizeof(cont.tabs)/sizeof(cont.tabs[0]); len++) {
    for(size_t b(0), e(cont.tabs[len].size()); b!=e; b++) {
      buf.putln(cont.tabs[len][b]);
      ++lines;
    };
  };
  buf.flush();
  err.putln("done saving");
  err.put("wrote ");
  err.fmt(buf.tot);
  err.putln(" bytes");
  err.flush();
  return 0;
};
str_len_tab pkgs;
str_tab paths;
struct join_t {
  size_t pkg;
  size_t path;
  c_str name;
};
vector<join_t> joins;
int proc_file(int fileno,const char *fn);
//   int signal(int sig, typeof(alarm_handler) hand)
//   FIXME!  I want my signal handling back!
//   {
//     sigaction_t o_act;
//     sigaction_t n_act;
//     return sys::rt_sigaction(sig, &n_act, &o_act);  
//   };
void fix_joins() {
//     write_buf<> buf(2);
//     buf.putln("Fixing Joins");
//     buf.putln("  counts:");
//     for( int i = 0; i < joins.size(); i++ )
//     {
//       join_t &join(joins[i]);
//       join.pkg=pkgs.idxs[join.pkg];
//       join.path=paths.idxs[join.path];
//     };
//     for(int i = 0; i < pkgs.size(); i++)
//       pkgs.idxs[i]=i;
//     for(int i = 0; i < paths.size(); i++)
//       paths.idxs[i]=i;
};
int main(int argc, char**argv)
{
  const char * fns[] = {
"data/mirrors.evowise.com_linuxmint_packages_dists_tina_import_Contents-amd64",
"data/mirrors.evowise.com_linuxmint_packages_dists_tina_main_Contents-amd64"
  };
  debug(sys::time(0));
//  signal(SIGALRM,alarm_handler);
 // sys::alarm(1);
  sys::dup2(1,2);
  if(argc>1) {
    for(int i=1;i<argc;i++)
      proc_file(i,argv[i]);
  } else {
    for(int i=0;i<sizeof(fns)/sizeof(fns[0]); i++)
      proc_file(1,fns[i]);
  };
  fix_joins();
  save_dat("pkgs.dat",pkgs);
  save_dat("paths.dat",paths);
  save_joins("joins.dat",joins);
  return 0;
};
using sys::open_mode;
using sys::open_flags;
using sys::o_default;

inline bool isspace(unsigned char ch)
{
  static bool res[256];
  if(!res[' ']){
    res[' ']=res['\t']=res['\n']=res['\v']=res['\f']=true;
  };
  return res[ch];
};
int xopen(const char *pathname, open_flags flags, open_mode mode=o_default)
{
  int res=sys::open(pathname,flags,mode);
  if(res<0)
    pexit("open",pathname);
  return res;
};
size_t xcnt=0;
void handle_line( const c_str &l ) {
  join_t join;
    // Because there may be whitespace in the filenames, we attack this
    // from the rear. The pkg is the last thing on the line.  We will
    // tolerate trailing whitespace.  And a plague on the houses of those
    // who put spaces in filenames!
    c_str pkg(l.end,l.end);
    while(isspace(pkg.end[-1]))
      --pkg.end;
    pkg.beg=pkg.end;
    // now we skip until the first whitespace.  There is no whitespace in
    // a package name.
    while(!isspace(pkg.beg[-1]))
      --pkg.beg;

    // Build up the c_str object that will become the path.
    // When we're done, wrap it in one.
    c_str path(l.beg,pkg.beg);
    while(path.end!=path.beg && isspace(path.end[-1]))
      *--path.end=0;
    c_str name(path.end,path.end);
    while(path.end!=path.beg && path.end[-1]!='/')
      --path.end;
    name.beg=path.end;
    while(path.end!=path.beg && path.end[-1]=='/')
      --path.end;
    *path.end=0;
    if(path.len()>256)
      return;
    if(pkg.len()>256)
      return;
    if(name.len()>256)
      return;

    join.pkg=pkgs.add(pkg);
    join.path=paths.add(path);
    join.name=name;
    joins.push_back(join);
    if(joins.size()%100000)
      return;
    time_t curr=sys::time(0);
    debug(sys::time(0));
    err.put("joins.size=");
    err.fmtln(joins.size());
    err.flush();
    if(joins.size()%1000000)
      return;
    err.putln("pkgs");
    for( int i = 0; i < 256; i++ ) {
      if(pkgs.tabs[i].size()) {
        err.put("  ");
        err.fmt(i);
        err.put(" => ");
        err.fmtln(pkgs.tabs[i].size());
      };
    };
    err.put(" pkgs.tot=");
    err.fmt(pkgs.tot);
    err.put(" .size=");
    err.fmtln(pkgs.size());
    err.put(" paths.tot=");
    err.fmt(paths.tot);
    err.put(" .rep=");
    err.fmt(paths.rep);
    err.put(" .size=");
    err.fmtln(paths.size());
    err.putln("\n\n");
    err.flush();
  };
  int proc_file(int fileno, const char *fn)
  {
    fd_t fd = xopen(fn,sys::o_rdonly);
    ++fileno;
    ssize_t len=lseek(fd,0,sys::end);
  char *data=(char*)mmap(
      0, len, sys::prot_read|sys::prot_write, sys::map_private, fd, 0
      );
  time_t stime=sys::time(0);
  // This is just an index.
  char *beg=data;
  char *pos=beg;
  char *end=data+len;
  size_t lines;
  while(pos!=end && *pos!='\n')
    ++pos;
  while(++pos!=end) {
    char *str=pos;
    while(*pos!='\n')
      ++pos;
    *pos=0;
    ++lines;
    handle_line(c_str(str,pos));
  };

  return 0;
};
void sys::perror(const c_str &msg)
{
  static c_str null;
  perror(null,msg);
};
void sys::pexit(const c_str &msg)
{
  perror(msg);
  exit(1);
};
void sys::perror(const c_str &msg1, const c_str &msg2)
{
  write_buf<> buf(2);
  if(msg1) {
    buf.put(msg1);
    buf.put(":");
  };
  if(msg2) {
    buf.put(msg2);
    buf.put(":");
  };
  buf.putln(strerror(*::__errno_location()));
};
void sys::pexit(const c_str &msg1, const c_str &msg2) {
  sys::perror(msg1,msg2);
  exit(1);
};
using fmt::fmt_t;
void _debug(const char *file, unsigned line, const char *name, c_str val) 
{
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.fmt(line);
  buf.put(":");
  buf.put(name);
  buf.put("=\"");
  buf.put(val);
  buf.putln("\"");
};
void _debug(const char *file, unsigned line, const char *name, const char * val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=\"");
  buf.put(val);
  buf.putln("\"");
};
void _debug(const char *file, unsigned line, const char *name, void *val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=");
  buf.putln(fmt_t(val));
};
void _debug(const char *file, unsigned line, const char *name, int val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=");
  buf.putln(fmt_t(val));
};
void _debug(const char *file, unsigned line, const char *name, size_t val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=");
  buf.putln(fmt_t(val));
};
static time_t first=sys::time(0);
static time_t last=first;
void _debug(const char *file, unsigned line, const char *name, time_t val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt.get());
  buf.put(":");
  buf.put(c_str(name));
  buf.put("=");
  buf.fmt(val-first);
  buf.put(" -- ");
  buf.fmtln(val-last);
  last=val;
};

const char c_str::null_str[1]="";
int c_str::cmp(size_t lhs, size_t rhs) {
  return lhs-rhs;
};
int c_str::cmp(const c_str &lhs, const c_str &rhs)
{
  int res = cmp(lhs.len(),rhs.len());
  if(!res)
    res=strncmp(lhs.beg,rhs.beg,lhs.len());
  return res;
};


using namespace fmt;
bool fatal=true;
static c_str colon(L(":"));
void do_assert_fail(const char *file, unsigned line, const char *msg)
{
  write_buf<> buf(2);
  buf.put(c_str(file));
  buf.put(colon);
  buf.fmt(line);
  buf.put(colon);
  buf.putln(msg);
  if(fatal)
    abort();
};
void do_warn_fail(
    const char *file, unsigned line, const char *msg, bool getbetter
    )
{
  write_buf<> buf(2);
  buf.put(c_str(file));
  buf.put(colon);
  buf.fmt(line);
  buf.put(colon);
  buf.putln(msg);

  if(!getbetter)
    abort();
};


