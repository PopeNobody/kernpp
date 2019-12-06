	.text
.Ltext0:
#APP
	.global _start
_start:
   xorl %ebp,%ebp
   movq 0(%rsp),%rdi
   lea 8(%rsp),%rsi
   call main
   movq %rax,%rdi
   movl $60,%eax
   syscall
   int3


