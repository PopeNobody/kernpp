.section	.rodata
msg:
.string	"Hello, World!\n"
len = . - msg
.text
.global _start
_start:
  movq $1,%rax
  movq $1,%rdi
	movq $msg,%rsi
  movq $len,%rdx
  syscall 
err:
  movq $60,%rax
  movq $0,%rdi
  syscall
  
.section .note.GNU-stack
