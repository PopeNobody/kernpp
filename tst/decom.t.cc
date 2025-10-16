#include <syscall.hh>

using namespace sys;

int main(int, char**, char**) {
  write(1,"Hello, World!\n");
  return 0;
}
