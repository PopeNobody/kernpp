#include <syscall.hh>
#include "hex.hh"
using namespace sys;
union magic_t {
  char  b[2];
  short s;
  const char* decomp() {
    switch(s) {
      case 0x1f8b:       
        return "gzip";
      case 'B'+256*'Z':  
        return "bzip2";
      case 0x28b5:       
        return "zstd";
      case 0x0422:       
        return "lz4";
      default:
        return 0;
    };
  }
  magic_t(const fd_t &fd)
    :s(0)
  {
    ssize_t n=sys::read(fd,&b[0],2,err_fatal);
    write(2,"read ");
    write(2,fmt::fmt_t(n));
    write(2," bytes\n");
    switch(n){
      case 2:
        return;
      case 1:
        write(1,&b[0],1);
      case 0:
        exit(0);
    };
  };
};

ssize_t read2(char*buf){
  buf[0]=buf[1]=0;
  if(!read(0,&buf[0],1,err_fatal))
    return 0;
  if(!read(0,&buf[1],1,err_fatal))
    return 1;
  return 2;
};

namespace sys {
  void open2(fd_t fd0,const char *fn,int flags,errhand_t hand){
    close(fd0);
    fd_t fd1=open(fn,flags,0,hand);
    if(fd0!=fd1) {
      dup2(fd1,fd0);
      close(fd1);
    };
  };
};
void do_files(char **beg, char **end){
  if(end==beg)
    return;
  do {
    char *fn=*beg++;
    open2(0,fn,o_rdonly,err_fatal);
    if(beg==end)
      return;
    pid_t pid=fork();
    int status;
    wait4(pid,&status,0,0);
  } while(beg!=end);
};

int main(int argc, char**argv, char**envp) {
  if(argc==1)
    return 0;
  if(argc<2)
    return 0;
  close(0);
  fd_t fd=open(argv[1],o_rdonly,0,err_fatal);
  magic_t magic(fd);
  fd_t pipefd[2];
  pipe(pipefd);
  while (true) {
    ssize_t spliced = splice(0, nullptr, pipefd[1], nullptr, 65536, 0,err_fatal);
    if (spliced == 0) break; // EOF
  }
  close(pipefd[1]); // finished writing to pipe
  dup2(pipefd[0], 0);
  close(pipefd[0]);


  const char * const cmd[]={ "/bin/bash", "-c",magic.decomp(), 0 };
  sys::execve(cmd[0], (char*const*)cmd, envp);
  perror("execlp"); // should not return
  return 127;
}
