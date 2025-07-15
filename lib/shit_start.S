.text
.global _shit_start
_shit_start:
  xorq %rbp,%rbp
  movq 0(%rsp),%rdi
  lea 8(%rsp),%rsi
  mov %rsi, %rdx
loop_check:
  mov (%rdx), %rax
  test %rax, %rax
  jz envp_found
  add $8, %rdx
  jmp loop_check
envp_found:
  add $8, %rdx
  push %rbp
  push %rsi
  push %rdi
  push %rdx
  push %rax
  call libc_init
  pop %rax
  pop %rdx
  pop %rdi
  pop %rsi
  pop %rbp
  call main
  movq %rax,%rdi
  call exit
  int3
.section .note.GNU-stack
