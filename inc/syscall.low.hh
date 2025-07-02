#pragma once
namespace sys {
  inline uint64_t syscall0(uint64_t n) {
    uint64_t r;
    asm volatile(
        "syscall" 
        : "=a"(r) 
        : "0"(n) 
        : "rcx", "r11", "memory"
        );
    return r;
  }
  inline uint64_t syscall1(uint64_t n, uint64_t a1) {
    uint64_t r;
    asm volatile(
        "syscall" 
        : "=a"(r) : "0"(n), "D"(a1) 
        : "rcx", "r11", "memory"
        ); 
    return r;
  }
  inline uint64_t syscall2(uint64_t n, uint64_t a1, uint64_t a2) {
    uint64_t r;
    asm volatile("syscall" 
        : "=a"(r) 
        : "0"(n), "D"(a1), "S"(a2) 
        : "rcx", "r11", "memory"
        );
    return r;
  }
  inline uint64_t syscall3(uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3) 
  {
    uint64_t r;
    asm volatile(
        "syscall" 
        : "=a"(r) 
        : "0"(n), "D"(a1), "S"(a2), "d"(a3) 
        : "rcx", "r11", "memory"
        );
    return r;
  }
  inline uint64_t syscall4(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4
      )
  {
    uint64_t r;
    asm volatile(
          "movq %4, %%r10\n"
          "syscall" 
        : "=a"(r) 
        : "0"(n), "D"(a1), "S"(a2), "d"(a3), "r"(a4) 
        : "rcx", "r11", "r10", "memory");
    return r;
  }
  inline uint64_t syscall5(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
      uint64_t a5
      )
  {
    uint64_t r;
    asm volatile(
        "movq %4, %%r10\n"
        "movq %5, %%r8\n"
        "syscall" 
        : "=a"(r) 
        : "0"(n), "D"(a1), "S"(a2), "d"(a3), "r"(a4), "r"(a5) 
        : "rcx", "r11", "r8", "memory"
        );
    return r;
  }
  inline uint64_t syscall6(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
      uint64_t a5, uint64_t a6
      )
  {
    uint64_t r;
    asm volatile(
        "movq %4, %%r10\n"
        "movq %5, %%r8\n"
        "movq %6, %%r9\n"
        "syscall"
        : "=a"(r)
        : "0"(n), "D"(a1), "S"(a2), "d"(a3), "r"(a4), "r"(a5), "r"(a6)
        : "rcx", "r11", "r10", "r8", "r9", "memory");
    return r;
  }
}
