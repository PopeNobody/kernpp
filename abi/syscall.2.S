	.globl	_ZN3sys8syscall2Emmm
_ZN3sys8syscall2Emmm:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rsi
	movq	%rdx, %rdi
#APP
# 6 "libsc/syscall.2.cc" 1
	syscall
# 0 "" 2
#NO_APP
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	ret
	.section	.note.GNU-stack,"",@progbits
