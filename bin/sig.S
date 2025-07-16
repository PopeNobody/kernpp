.text
.global _start
_start:
  xor %rdi,%rdi
  mov %rsp,%rdi
  call call_main
  call exit
  int3
.section .note.GNU-stack
