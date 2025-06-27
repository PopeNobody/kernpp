extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "vpipe.hh"
#include "fmt.hh"
using fmt::fmt_t;
using namespace sys;
uint64_t atoi(const char *pos){
  uint64_t res=0;
  while(*pos>='0' && *pos<='9') {
    res*=10;
    res+=(*pos-'0');
    ++pos;
  };
  return res;
};
 int main(int argc,char *const*argv,char *const*envp) {
  using namespace vpipe;
  if(isatty(0)){
    dup2(0,1);
    dup2(0,2);
  } else if ( isatty(1)){
    dup2(1,0);
    dup2(1,2);
  } else {
    dup2(2,0);
    dup2(2,1);
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
