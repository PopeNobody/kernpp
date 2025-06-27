extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
using namespace sys;


int main(int argc,char *const*argv,char *const*envp){
  int fd=open(".",o_directory|o_rdonly);
  if(fd<0)
    pexit(3,"open:.");
  ssize_t size;
  char buf[16*1024];
  while((size=getdents(fd,(linux_dirent64*)buf,sizeof(buf)))>0){
    if(size<0)
      pexit(1,"getdents");

  };
  return 0;
};
