#include "fmt.hh"

int sys::system(const char *cmd) {
  char bash[]="/bin/bash";
  char flag[]="-c";
  char *argv[] = {
    bash, flag, (char*)cmd, 0
  };
  int status;
  pid_t pid=sys::fork();
  if(pid) {
    pid_t kid=sys::wait4(pid,&status,0,0,err_log);
    using sys::write;
    write(1,"\r\n");
    write(1,fmt::fmt_t(pid));
    write(1," returned ");
    write(1,fmt::fmt_t(status));
    write(1,"\r\n");
  } else {
    sys::execve(argv[0],(char*const*)argv,0);
    sys::pexit(2,"execve");
  };
  return status;
};
