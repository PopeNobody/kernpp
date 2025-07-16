	.globl	_ZN3sys8syscall4Emmmmm          # -- Begin function _ZN3sys8syscall4Emmmmm
_ZN3sys8syscall4Emmmmm:
	pushq	%rbp
	movq	%rsp, %rbp
  movq  %r8,  %r10
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%r8, -40(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %r8
	syscall
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	popq	%rbp
	retq
                                        # -- End function
.section	".note.GNU-stack","",@progbits
