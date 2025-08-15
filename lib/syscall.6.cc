#include "syscall.hh"
#include "syscall.low.hh"

static uint64_t data[7];

uint64_t sys::syscall6(
    uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
    uint64_t a5, uint64_t a6
    )
{
  uint64_t r;
  register uint64_t r10_arg asm("r10") = a4; // Force a4 into r10
  register uint64_t r8_arg asm("r8") = a5;   // Force a5 into r8
  register uint64_t r9_arg asm("r9") = a6;   // Force a6 into r9

  asm volatile(
      "syscall"
      : "=a"(r)                 // Output: %rax -> r
      : "0"(n),                 // Input: n -> %rax (syscall number)
        "D"(a1),                // Input: a1 -> %rdi (arg1)
        "S"(a2),                // Input: a2 -> %rsi (arg2)
        "d"(a3),                // Input: a3 -> %rdx (arg3)
        "r"(r10_arg),           // Input: r10_arg (which is a4) -> %r10
        "r"(r8_arg),            // Input: r8_arg (which is a5) -> %r8
        "r"(r9_arg)             // Input: r9_arg (which is a6) -> %r9
      : "rcx", "r11", "memory"); // Clobber list
  return r;
}
//     asm volatile(
//         "syscall"
//         : "=a"(r)                 // Output: %rax -> r
//         : "0"(n),                 // Input: n -> %rax (syscall number)
//           "D"(A1),                // Input: a1 -> %rdi (arg1)
//           "S"(A2),                // Input: a2 -> %rsi (arg2)
//           "d"(A3),                // Input: a3 -> %rdx (arg3)
//           "r"(A4),                // Input: a6 -> %r9 (arg6)
//           "r"(A5),                // Input: a5 -> %r8 (arg5)
//           "r"(A6)                 // Input: a4 -> %r10 (arg4)
//         : "rcx", "r11", "memory"); // Clobber list
//   
//     return r;
//   }
