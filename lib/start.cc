// Weak aliases for all valid C main signatures:
//   __attribute__((weak, alias("__kernpp_main_adapter")))
//    void (*main)(int argc,char *const*argv,char *const*envp) ;
//   __attribute__((weak, alias("__kernpp_main_adapter")))
//    int main(int argc,char *const*argv,char *const*envp) ;
//   
//   __attribute__((weak, alias("__kernpp_main_adapter")))
//    int main(int argc,char *const*argv,char *const*envp) ;
extern "C" {
  int main(int, char *const *argv, char *const *envp);
  void _start(void);
};
void _start(void) {
    long *sp;
    asm volatile("mov %%rsp, %0" : "=r"(sp));

    int argc = (int)sp[0];
    char **argv = (char **)(&sp[1]);
    char **envp = argv + argc + 1;

    // Call user main
    int ret = main(argc, argv, envp);

    // Exit with the return value
    asm volatile (
        "mov $60, %%rax\n\t"   // syscall: exit
        "mov %0, %%rdi\n\t"    // status = ret
        "syscall\n\t"
        : : "r"((long)ret) : "%rax", "%rdi"
    );

    __builtin_unreachable();
}
