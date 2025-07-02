#include "syscall.hh"

extern "C" {
  int main(int, char**,char**) {
    sys::write(1,"Hello, World!\n");     
    return 0;
  };
}
