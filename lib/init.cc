#include "syscall.hh"

typedef int (*main_t)(int, char **, char **);
extern "C" {
	void libc_init();
	void libc_fini();
  int run_main(void **args);
  int main(int, char**, char**);
  void __cxa_guard_abort() {
  };
};
int run_main(void **args) {
  main_t main_func=main;
  // Yeah, we cheated.
  int argc=*(int*)args++;

  char **argv=(char**)args++;
  char **envp=argv+argc+1;
  libc_init();
  int res=main_func(argc,argv,envp);
  libc_fini();
  sys::exit(0);
};

