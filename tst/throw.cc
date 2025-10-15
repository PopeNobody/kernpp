#include "syscall.hh"
using namespace sys;
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    try {
      write(1,"Hello, World!\n");
      throw("x");
    } catch ( ... ) {
      write(2,"caught");
    };
    return 0;
  };
}

