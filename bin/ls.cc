#include <syscall.hh>
#include <new.hh>
#include <fmt.hh>
#include <getopt.hh>

using sys::write;
using sys::errno;

template<typename obj_t>
void swap(obj_t &lhs, obj_t &rhs)
{
  obj_t tmp(lhs);
  lhs=rhs;
  rhs=tmp;
};
enum ignore_t {
  normal,
  minimal,
  dot_dot,
} ignore;
extern "C" {
  void mm_show();
};
bool dotfiles=false;
static void *ptrs[4096];
static size_t nptr=0;
using namespace sys;

int sign(int lhs){
  if(lhs<0)
    return -1;
  else if (lhs>0)
    return 1;
  else
    return 0;
};
int cmp(const char *lhs, const char *rhs){
  while(*lhs == *rhs && *lhs)
    ++lhs, ++rhs;
  return sign(*lhs-*rhs);
};
void sort(linux_dirent **beg, linux_dirent**end)
{
  if(beg==end)
    return;
  linux_dirent** pos=beg;
  while(pos<end){
    while(++beg<end){
      if(cmp((*beg)->d_name,(*pos)->d_name)<0)
        swap(*beg,*pos);
    }
    pos++;
    beg=pos;
  }
};
void lsdir(int fd) {
  int n=0;
  linux_dirent*ents[8192];
  enum { size = 4096 };
  char buf[size];
  for(;;){
    int nread=getdents(fd,(linux_dirent*)(char*)buf,size);
    if(nread<0)
      pexit("getdents");
    else if (nread==0)
      break;
    auto beg = reinterpret_cast<linux_dirent*>(&buf[0]);
    auto end = reinterpret_cast<linux_dirent*>(&buf[nread]);
    while(beg!=end){
      if(dotfiles || beg->d_name[0] != '.') {
        ents[n++]=beg;
      };
      beg=beg->next();
    }
  };
  sort(ents,ents+n);
  for(int i=0;i<n;i++){
    write(1,ents[i]->d_name);
    write(1,"\n");
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
    bool neg = (errno<0);
    unsigned long num=(neg?-1:1)*errno; 
    char *str=fmt::fmt_dec(neg,num,buf,end);
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
  using fmt::write_dec;
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
