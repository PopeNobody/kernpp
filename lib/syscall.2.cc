#include "syscall.hh"
#include "syscall.low.hh"

uint64_t sys::syscall2(uint64_t n, uint64_t a1, uint64_t a2) {
  uint64_t r;
  asm volatile("syscall" 
      : "=a"(r) 
      : "0"(n), "D"(a1), "S"(a2) 
      : "rcx", "r11", "memory"
      );
  return r;
}
