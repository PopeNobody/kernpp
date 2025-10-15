#include "syscall.hh"
using namespace sys;

int main(int argc, char**argv, char **envp) {
  dup2(1,10);
  fd_t fd = memfd_create("buffer", 0);
  write(fd, "Hello, world!\n", 14);
  lseek(fd, 0, seek_set);       // rewind
  if(fd) {
    dup2(fd, 0);                  // memfd becomes stdin
    close(fd);
  };
  close(1);
  unlink("hello.gz");
  fd=open("hello.gz",o_wronly|o_creat|o_excl,0700);
  if(fd!=1) {
    dup2(fd,1);
    close(fd);
  };
  argv[0]=(char*)"/bin/bzip2";
  execve(argv[0],argv,envp);
  std::abort();
};
