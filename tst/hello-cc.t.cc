#include <syscall.hh>

int main() {
  sys::write(1,"Hello, World!");
  return 0;
};
