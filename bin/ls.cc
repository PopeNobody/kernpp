#include <syscall.hh>
#include <new.hh>
#include <fmt.hh>
#include <getopt.hh>

using sys::write;
using sys::errno;

template<typename obj_t>
void swap(obj_t &lhs, obj_t rhs)
{
  obj_t tmp(lhs);
  lhs=rhs;
  rhs=tmp;
};
struct dirents_t {
  struct ent_t {
    bool dir;
    char name[256];
    ent_t()
      :dir(false)
    {
    };
    ent_t(const char *_name, bool _dir)
      :dir(_dir)
    {
      strncpy(name,_name,sizeof(name));
    };
  };
  size_t cap;
  size_t cnt;
  ent_t **lst;
  dirents_t()
    : lst(0), cap(0), cnt(0)
  {
  };
  int cmp(ent_t &lhs, ent_t&rhs) {
    return strcmp(rhs.name,lhs.name);
  };
  void sort() {
    size_t n=size();
    for(int i=0;i<n-2;i++) {
      int m=i;
      for(int j=i+1;j<n;j++) {
        if(cmp(*lst[m],*lst[j])<0)
          m=j;
      };
      if(i!=m)
        swap(lst[i],lst[m]);
    };
  };
  ~dirents_t() {
    for(int i=0;i<cnt;i++)
      delete lst[i];
    delete[] lst;
  };
  void push_back(const char *name, bool isdir)
  {
    if(cnt==cap) {
      if(cap) {
        ent_t **nlst = new ent_t*[cap+16];
        memcpy(nlst,lst,sizeof(ent_t*)*cap);
        delete[] lst;
        lst=nlst;
      } else {
        lst = new ent_t*[16];
      };
      cap+=16;
    };
    ent_t *new_ent=new ent_t(name,isdir);
    lst[cnt++]=new_ent;
  };
  ent_t &get(size_t pos)
  {
    return *lst[pos];
  };
  size_t size() const {
    return cnt;
  };
};
enum ignore_t {
  normal,
  minimal,
  dot_dot,
} ignore;
extern "C" {
  void mm_show();
};
static void *ptrs[4096];
static size_t nptr=0;
using namespace sys;
void lsdir(int fd) {
  enum { size = 4096 };
  dirents_t ents;
  char buf[size];
  for(;;){
    int nread=getdents(fd,(linux_dirent*)(char*)buf,size);
    if(nread<0)
      pexit("getdents");
    else if (nread==0)
      break;
    auto beg = reinterpret_cast<linux_dirent*>(&buf[0]);
    auto end = reinterpret_cast<linux_dirent*>(&buf[nread]);
    while(beg!=end) {
      ents.push_back(beg->d_name,beg->d_type == DT_DIR);
      beg=beg->next();
    };
    //mm_show();
  };
  ents.sort();
  for(size_t i=0;i<ents.size();i++)
  {
    auto ent=ents.get(i);
    if(ignore==dot_dot) {
      if(!strcmp(ent.name,"."))
        continue;
      if(!strcmp(ent.name,".."))
        continue;
    } else if ( ignore != minimal ) {
      if(ent.name[0]=='.')
        continue;
    };
    write(1,ent.name);
    write(1,L("\n"));
  };
};
void lsarg(const char *path)
{
  int fd = open(path,open_flags(o_directory|o_rdonly));
  if(fd>=0)
  {
    lsdir(fd);
  } else if ( errno == ENOTDIR ) {
    write(1,path);
    write(1,"\n",1);
  } else {
    write(2,"open: ");
    write(2,path);
    write(2," failed (");
    char buf[32];
    char *end=&buf[sizeof(buf)-1];
    char *str=fmt::fmt_dec(errno,buf,end);
    write(2,str,end);
    write(2,")\n");
  };
  close(fd);
};

static option longopts[]={
  { "version", 0, 0, 1 },
  { "help",    0, 0, 2 },
  { 0, 0, 0, 0}
};
const char help_msg[]=
"Usage: /bin/ls [OPTION]... [FILE]...\n"
"List information about the FILEs (the current directory by default).\n"
"Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.\n"
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"  -a, --all                  do not ignore entries starting with .\n"
"  -A, --almost-all           do not list implied . and ..\n"
"  -b, --escape               print C-style escapes for nongraphic characters\n"
"  -d, --directory            list directories themselves, not their contents\n"
"      --help     display this help and exit\n"
"      --version  output version information and exit\n"
"\n"
"Exit status:\n"
" 0  if OK,\n"
" 1  if minor problems (e.g., cannot access subdirectory),\n"
" 2  if serious trouble (e.g., cannot access command-line argument).\n"
;
int help(int res)
{
  write((res?2:1),L(help_msg));
  return 0;
};
int version() {
  write(1,L("ls (kernpp) 1.0\n"));
  return 0;
};
extern "C" {
  int main(int argc, char**argv, char**envp) ;
};
int main(int argc, char**argv,char**envp) 
{
  int ch;
  int longidx=0;
  signed long u=1;
  signed long lu=0;
  // show directory contents
  bool dir_cont=true;
  if(dup2(1,2)<0)
    pexit("dup2");
  while((ch=getopt_long(argc,argv,"aA",longopts,&longidx))!=-1)
  {
    switch(ch) {
      case 1: return version();
      case 2: return help(0);
      case 'a': ignore=minimal; break;
      case 'A': ignore=dot_dot; break;
      case 'd': dir_cont=false; break;
      default: return help(1);
    };
  };
  if(optind<argc) {
    for(int i=optind;i<argc;i++){
      lsarg(argv[i]);
    };
  } else {
    lsarg(".");
  };
  for(int i=0;i<nptr;i++) {
    if(ptrs[i]){
      fmt::write_ptr(2,ptrs[i]);
      write(2,L("\n"));
      free(ptrs[i]);
      ptrs[i]=0;
    };
  };
  return 0;
};
