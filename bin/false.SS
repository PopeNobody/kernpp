	.text
.Ltext0:
#APP
	.global _start
_start:
   movq $1,%rdi
   movq $60,%rax
   syscall
   int3


