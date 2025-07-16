#pragma once

namespace sys {

  uint64_t syscall0(uint64_t n) ;

  uint64_t syscall1(uint64_t n, uint64_t a1) ;

  uint64_t syscall2(uint64_t n, uint64_t a1, uint64_t a2) ;

  uint64_t syscall3(uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3) ;

  uint64_t syscall4(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4
      );

  uint64_t syscall5(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
      uint64_t a5
      );

  uint64_t syscall6(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
      uint64_t a5, uint64_t a6
      );
}
