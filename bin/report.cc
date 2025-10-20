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
      int ret=-1;
      do {
        using fmt::fmt_t;
        fd_t efd(2);
        int tmp;
        res=wait4(0,&tmp,0,0,err_ignore);
        if(res>1) {
          ret=tmp/256;
          fmt::buf_t<160> err(2);
          err.a_str("pid ").a_int(res,false).a_str(" returned ").a_int(ret,false).a_nl();
        } else {
          break;
        }
      } while(true);
      exit(ret);
    } else {
      execve(argv[0],argv,envp);
      write(2,"a\n",2);
      pexit(2,"execve");
      exit(1);
    }
    return 0;
  };
}
