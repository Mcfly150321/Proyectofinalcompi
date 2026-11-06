section .data
    fmt_in db "%d", 0
    fmt_out db "%d", 10, 0

section .bss
    a resd 1
    b resd 1

section .text
    global _start
    extern printf
    extern scanf

_start:

    push b
    push fmt_in
    call scanf
    add esp, 8

    mov eax, 1
    add eax, 2
    add eax, [b]
    mov [a], eax
    push dword [a]
    push fmt_out
    call printf
    add esp, 8


    ; Salida del programa
    mov eax, 1 
    xor ebx, ebx 
    int 0x80 
