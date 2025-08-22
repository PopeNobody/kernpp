extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "vpipe.hh"
#include "fmt.hh"
using fmt::fmt_t;
using fmt::atoi;
using namespace sys;

int main(int argc,char *const*argv,char *const*envp) {
  using namespace vpipe;
  if(!isatty(0)){
    write(2,"cannot find term\n");
  };
  system("stty -g > stty.log");
  write(2,"set_sane\n");
  term_set_sane(0);
  system("stty -g >>stty.log");
  write(2,"set_raw\n");
  term_set_raw(0);
  system("stty -g >>stty.log");
  write(2,"set_raw\n");
  term_set_sane(0);
  system("stty -g >>stty.log");
  return 0;
};
