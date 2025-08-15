#include "syscall.hh"
#include "syscall.low.hh"

#include "syscall.hh"
#include "syscall.low.hh"

uint64_t sys::syscall5(
    uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
    uint64_t a5
    )
{
  uint64_t r;
  // Declare local register variables for a4 and a5
  register uint64_t r10_arg asm("r10") = a4; // Force a4 into r10
  register uint64_t r8_arg asm("r8") = a5;   // Force a5 into r8

  asm volatile(
      "syscall" // The syscall instruction itself
      : "=a"(r)                     // Output: %rax -> r
      : "0"(n),                     // Input: n -> %rax (syscall number)
        "D"(a1),                    // Input: a1 -> %rdi (arg1)
        "S"(a2),                    // Input: a2 -> %rsi (arg2)
        "d"(a3),                    // Input: a3 -> %rdx (arg3)
        "r"(r10_arg),               // Input: r10_arg (which is a4) -> %r10
        "r"(r8_arg)                 // Input: r8_arg (which is a5) -> %r8
      : "rcx", "r11", "memory"      // Clobber list
      );
  return r;
}
