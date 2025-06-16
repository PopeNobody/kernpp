#include <errno.hh>
#include <syscall.hh>
#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff00)>>8)
using sys::write;
#include "itoa.hh"
int write_dec(int fd, unsigned long val, bool neg=false){
  return write(fd,sys::itoa(val,neg));
};
int main(int argc, char** argv, char **envp)
{
  if(argc<2) {
    write(2,"usage: ");
    write(2,argv[0]);
    write(2," <command>\n");
    return 2;
  };
  for(int i=0;envp[i];i++){
    write(2,envp[i]);
    write(2,"\n");
  };
  write(2,"(null)\n\n");
  
  write(2,"\n\nargc=");
  write_dec(2,argc);
  write(2,"\n\n");

  pid_t opid=sys::getpid();
  pid_t npid=sys::fork();
  int res;
  if(npid) {
    if(sys::wait(&res)<0)
      sys::pexit("wait");
    write(2,"\n\n");
    write_dec(2,res);
    write(2,"\n");
  } else {
    ++argv;
    sys::execve(argv[0],argv, envp);
    sys::pexit("execve");
  };
  sys::exit(!res);
};
