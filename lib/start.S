.text
.global _start
_start:
  movq %rsp,%rdi 
  call run_main


.section .note.GNU-stack
