.global _start
.intel_syntax noprefix

_start:
read:
    mov rdi, 6
    lea rsi, [rip+buf]
    mov rdx, 60
    mov rax, 0
    syscall

check:
    mov al, [rip+buf+24]
    cmp al, 70
    jne crash

match:
    mov rdi, 0
    mov rax, 60
    syscall

crash:
    ud2

buf:
    .zero 256
