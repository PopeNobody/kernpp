#include <syscall.hh>
#include <fmt.hh>


using sys::write;
using sys::nanosleep;
using sys::exit;
using namespace fmt;

void too_many() {
  write(2,L("too many!\n\n"));
  exit(1);
};
const static int million=1000000;
const static int billion=1000*million;
extern "C" {
int main(int argc,char *const*argv,char *const*envp) {
  timespec tm;
  if(*++argv) {
    tm.tv_sec=atoi(*argv);
  } else {
    sys::die("no time specified");
  };
  write(2,fmt::fmt_t(tm));
  nanosleep(&tm,0);
  return 0;
};
};
