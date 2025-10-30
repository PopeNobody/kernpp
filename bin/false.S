.text
.global _start
_start:
  mov $1,%rdi
  call exit
  int3
.section .note.GNU-stack
