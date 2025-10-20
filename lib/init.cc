#include "syscall.hh"

typedef int (*main_t)(int, char **, char **);
extern "C" {
  int run_main(void **args);
  int main(int, char**, char**);
  int libc_init();
};
int run_main(void **args) {
  main_t main_func=main;
  // Yeah, we cheated.
  int argc=*(int*)args++;
  char **argv=(char**)args++;
  char **envp=argv+argc+1;
  libc_init();
  int res=main_func(argc,argv,envp);
  sys::exit(0);
};

