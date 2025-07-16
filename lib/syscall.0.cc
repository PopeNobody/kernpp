#include "syscall.hh"
#include "syscall.low.hh"

uint64_t sys::syscall0(uint64_t n) {
  uint64_t r;
  asm volatile(
      "syscall" 
      : "=a"(r) 
      : "0"(n) 
      : "rcx", "r11", "memory"
      );
  return r;
}
