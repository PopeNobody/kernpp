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
  timespec_t tm;
  if(*++argv) {
    tm.tv_sec=atoi(*argv);
  } else {
    sys::die("no time specified");
  };
  fmt_t tm_fmt(tm);
  tm_fmt.push_back('\n');
  write(2,tm_fmt);
  nanosleep(&tm,0);
  return 0;
};
};
