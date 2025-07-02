#include "syscall.hh"
#include "fmt.hh"
using namespace sys;
istr_t *environ;

istr_t get_env(char const * name){
  for(istr_t *p=environ; *p; p++){
    write(2,*p);
    write(2,"\n");
  };
  return 0;
};


extern "C" {
int main(int argc,char *const*argv,char *const*envp) {
    char *path=0;
    bool abs=true;
    if(!argv[1]) {
      write(2,"No program provided\n");
      exit(2);
    };
    argv++;
    pid_t pid=fork();
    pid_t res;
    if(pid) {
      int ret;
      do {
        using fmt::fmt_t;
        fd_t efd(2);
        res=waitpid(0,&ret,0);
        write(efd,"pid ");
        write(efd,fmt_t(res));
        write(efd,"  returned ");
        write(efd,fmt_t(ret));
        exit(ret/256);
      } while(res>0);
    } else {
      execve(argv[0],argv,envp);
      write(2,"execve:argv[0]");
      exit(1);
    }
    return 0;
  };
}
