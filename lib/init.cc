#include "syscall.hh"

typedef int (*main_t)(int, char **, char **);
extern "C" {
  int run_main(void **args);
  int main(int, char**, char**);
};
int run_main(void **args) {
  main_t main_func=main;
  // Yeah, we cheated.
  int argc=*(int*)args++;

  char **argv=(char**)args++;
  char **envp=argv+argc+1;
#if 0
  using sys::write;
  write(1,fmt::fmt_t(argc));
  write(1,"\n");
  write(1,fmt::fmt_t((void*)argv));
  write(1,"\n");
  write(1,*argv);
  write(1,"\n");
  write(1,"\n");
  write(1,fmt::fmt_t((void*)envp));
  write(1,"\n");
  write(1,*envp);
  write(1,"\n");
  write(1,"\n");
#endif
  int res=main_func(argc,argv,envp);
  sys::exit(0);
};

