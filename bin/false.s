	.text
.Ltext0:
#APP
	.global _start
_start:
   movq $1,%rdi
   movl $60,%eax
   syscall
   int3


