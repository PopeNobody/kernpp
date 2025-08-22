extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
using namespace sys;

template<size_t n>
struct dirent_buf_t {
  char buf[n]={};
  size_t pos=0;
  size_t size=0;
  fd_t fd;
  dirent_buf_t(fd_t fd)
    : fd(fd)
  {
    read();
  };
  bool read() {
    pos=0;
    size=1;
    size=getdents(fd,*this,sizeof(buf));
    return !!size;
  }; 
  linux_dirent*ent(){
    if(pos>=size || pos<0) {
      return 0;
    } else {
      return (linux_dirent*)(buf+pos);
    }
  };
  operator linux_dirent*() {
    return ent();
  };
  dirent_buf_t &operator++(int) {
    pos+=ent()->reclen();
    if(pos==size) {
      read();
    };
    return *this;
  }
  dirent_buf_t &operator++() {
    pos+=(*this)->d_reclen;
    if(pos==size) {
      read();
    };
    return *this;
  };
};
int main(int argc,char *const*argv,char *const*envp) {
  int fd=open(".",o_directory|o_rdonly);
  if(fd<0)
    pexit(3,"open:.");
  ssize_t size;
  dirent_buf_t<512> buf(fd);
  linux_dirent *ent=buf;
  while(ent=buf) {
    write(1,fmt::fmt_t((void*)ent));
    write(1,"  ");
    write(1,fmt::fmt_t(ent->type()));
    write(1," ");
    write(1,ent->name());
    write(1,"\n");
    buf++;
  };
  return 0;
};
