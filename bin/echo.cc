#include <syscall.hh>
using sys::write;

int main(int argc, char**argv,char **envp) {
  ++argv;
  if(*argv)
    write(1, *argv++);
  while(*argv) {
    write(1,L(" "));
    write(1, *argv++);
  };
  write(1, L("\n"));
  return 0;
};
