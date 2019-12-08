	.text
.Ltext0:
	.global hello_msg
hello_msg:
	.string	"Hello, World!\n"
hello_len:
	.quad .-hello_msg
#APP
	.global _start
_start:
   xorl %ebp,%ebp

	 call libc_init
   movq 0(%rsp),%rdi
   lea 8(%rsp),%rsi
   call main
   movq %rax,%rdi
   movl $60,%eax
   syscall
   int3
