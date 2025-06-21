.text
.global _start
_start:
  xor %rdi,%rdi
  call exit
  int3
.section .note.GNU-stack
