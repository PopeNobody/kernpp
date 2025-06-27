#if 0
// kernpp_start_weak.c
// -------------------------------------------------------
// Demonstrates _start + weak aliases for main variants
// for your freestanding kern++ environment
// -------------------------------------------------------
#include "syscall.hh"

// Declare your fallback handler
__attribute__((noreturn))
int __kernpp_main_adapter(int argc, char **argv, char **envp) {
    // Provide a clear diagnostic in debug builds:
    const char *msg = "Error: No valid 'main' function found.\n";
    sys::write(2, msg, 39); // direct syscall usage if desired

    // Exit with error code
    asm volatile (
        "mov $60, %%rax\n\t"   // syscall: exit
        "mov $1, %%rdi\n\t"    // status = 1 (error)
        "syscall\n\t"
        : : : "%rax", "%rdi"
    );

    __builtin_unreachable();
}

// Weak aliases for all valid C main signatures:
__attribute__((weak, alias("__kernpp_main_adapter")))
 int main(int argc,char *const*argv,char *const*envp) ;

__attribute__((weak, alias("__kernpp_main_adapter")))
 int main(int argc,char *const*argv,char *const*envp) ;

__attribute__((weak, alias("__kernpp_main_adapter")))
 int main(int argc,char *const*argv,char *const*envp) ;

// Your freestanding _start implementation
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
#endif
