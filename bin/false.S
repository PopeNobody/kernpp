	.text
.Ltext0:
#APP
	.global _start
_start:
   movq $1,%rdi
   movl $60,%eax
   syscall
   int3
.LASF1:
	.string	"/home/nn/src/git/kernpp.hub"
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits

