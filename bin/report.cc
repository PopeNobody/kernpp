#include "syscall.hh"
#include <search_path.hh>
#include "fmt.hh"
using shell_ns::search_path;
using namespace sys;
char **envp;
extern istr_t *environ;
static char full[16*1024];
using shell_ns::search_path;
extern "C" {
  int main(int argc, char *const * argv, char *const * envp) {
    char *path=0;
    bool abs=true;
    if(!argv[1]) {
      write(2,"No program provided\n");
      exit(2);
    };
    const char *full=0;
    full=search_path(argv[1],"PATH",false);
    if(!full) {
      write(2,"not found\n");
      exit(97);
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
