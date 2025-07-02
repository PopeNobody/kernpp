<<<<<<< HEAD
#include "syscall.hh"

extern "C" {
  int main(int, char**,char**) {
    sys::write(1,"Hello, World!\n");     
    return 0;
  };
}
||||||| 2359da4
=======
#include <syscall.hh>

extern "C" {
int main(int argc,char *const*argv,char *const*envp) {
  return 0;
};
};
>>>>>>> limited
