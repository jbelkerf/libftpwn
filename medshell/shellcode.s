.global _start
.intel_syntax noprefix

_start:#["read", "exit"]
       #["read:3","write:4", "open:5", "close:6"]

read:
    mov rdi, 6
    lea rsi, [rip+buf]
    mov rdx, 60
    mov rax, 0
    syscall
exit:
    mov dil, [rip+buf+0]
    mov rax, 60
    syscall

buf:
    .zero 256

