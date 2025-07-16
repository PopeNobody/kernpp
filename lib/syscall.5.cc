#include "syscall.hh"
#include "syscall.low.hh"
uint64_t sys::syscall5(
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
