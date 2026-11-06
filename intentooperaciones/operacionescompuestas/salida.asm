section .data
    fmt_in db "%d", 0
    fmt_out db "%d", 10, 0

section .bss
    a resd 1
    b resd 1
    total resd 1
    d resd 1

section .text
    global main
    extern printf
    extern scanf

main:
    mov dword [a], 0
    mov dword [i], 1
l1:
    mov eax, [a]
    add eax, 2
    mov [a], eax
    mov eax, [i]
    add eax, 1
    mov [i], eax
    mov eax, [i]
    cmp eax, 2
    setle al
    movzx eax, al
    mov eax, 1
    cmp eax, 0
    setg al
    movzx eax, al
    mov eax, [t3]
    mov ebx, [t4]
    and eax, ebx
    cmp eax, 0
    jne l1
    mov eax, [a]
    mov [total], eax
    mov eax, 3
    add eax, 5
    mov [d], eax
    mov eax, 0
    ret
