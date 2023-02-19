#ifdef __ELF__
.section .note.GNU-stack,""
#endif
	.text
	.global _start
_start:
  xorl %ebp,%ebp
	call libc_init
  movq 0(%rsp),%rdi
  lea 8(%rsp),%rsi
  call main
	movq %rax,%rdi
	call exit
	int3
#   movq %rax,%rdi
#   movl $60,%eax
#   syscall
#   int3
