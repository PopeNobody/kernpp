extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "vpipe.hh"
#include "fmt.hh"
using fmt::fmt_t;
using fmt::atoi;
using namespace sys;

int main(int argc,char *const*argv,char *const*envp) {
  using namespace vpipe;
  if(isatty(0)){
    dup2(0,1);
    dup2(0,2);
  } else if (isatty(1)){
    dup2(1,0);
    dup2(1,2);
  } else if (isatty(2)){
    dup2(2,0);
    dup2(2,1);
  }else{
    write(2,"cannot find term\n");
  };
  term_set_raw(0);
  write(1,"this\nis\na\ntest\n");
  term_set_sane(0);
  write(1,"this\nis\na\ntest\n");
  term_set_sane(0);
  write(1,"this\nis\na\ntest\n");
  term_set_sane(0);
  write(1,"this\nis\na\ntest\n");
  term_set_sane(0);
  write(1,"this\nis\na\ntest\n");
  term_set_sane(0);
  write(1,"this\nis\na\ntest\n");
  term_set_sane(0);
  write(1,"this\nis\na\ntest\n");
  return 0;
};
