	.text
.Ltext0:
#APP
	.global _start
_start:
   movq $0,%rdi
   movl $60,%rax
   syscall
   int3


