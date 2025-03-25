.text
.global _start
_start:
  xorq %rbp,%rbp
  movq 0(%rsp),%rdi
  lea 8(%rsp),%rsi
  mov %rsi, %rdx      # Copy argv pointer to rdx (envp)
loop_check:
    mov (%rdx), %rax    # Load the current argv element
    test %rax, %rax    # Check if it's null
    jz envp_found      # Jump if null (end of argv)
    add $8, %rdx       # Increment rdx (move to next argv element)
    jmp loop_check     # Continue the loop

envp_found:
  add $8, %rdx       # Increment rdx (now points to envp)
  push %rbp;
  push %rsi;
  push %rdi
  push %rdx;
  push %rax;
  call libc_init
  pop %rax;
  pop %rdx;
  pop %rdi
  pop %rsi;
  pop %rbp;
  call main
  movq %rax,%rdi
  call exit
  int3
#   movq %rax,%rdi
#   movl $60,%eax
#   syscall
#   int3
.section .note.GNU-stack 
