#if 0
#include <syscall.hh>
using sys::write;
#endif

int main(int argc, char*argv[]) {
#if 0
  ++argv;
  if(*argv)
    write(1, *argv++);
  while(*argv) {
    write(1,L(" "));
    write(1, *argv++);
  };
  write(1, L("\n"));
#endif
  return 0;
};
