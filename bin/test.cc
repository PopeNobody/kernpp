#include "syscall.hh"

pid_t child;
static void child_reap(int) {
  pid_t pid;
  while(true) {
    int status=0;
    pid=sys::waitpid(0,&status,0);
    using sys::write;
    write(2,"dead pid: ");
    write(2,fmt::fmt_t(pid));
    write(2,"\n");
    if(pid==child) {
      write(2,"child died\n");
//      write(spty,"\004",1);
    };
    if(pid==-1) {
      write(2,"waitpid: ");
      write(2,fmt::fmt_t(pid));
      write(2,", errno: ");
      write(2,fmt::fmt_t(sys::errno));
    } else {
      write(2,"waitpid: ");
      write(2,fmt::fmt_t(pid));
      write(2,", status: ");
      write(2,fmt::fmt_t(status));
    };
  };
};
using sys::write;
extern "C" {
  int main(int, char**) {
    struct sigaction_t act;
    memset(&act,0,sizeof(act));
//    act.sa_handler=child_reap;
    act.sa_flags=0;
    auto res = sys::rt_sigaction(17,&act,0,16);
    write(2,"res=");
    write(2,fmt::fmt_t(res));
    write(2,"\n");
    return res!=0;
  }
};
