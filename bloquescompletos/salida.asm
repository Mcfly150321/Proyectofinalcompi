section .bss
    a resd 1
    i resd 1
    total resd 1

section .text
    global _start

_start:

    mov dword [a], 0
    mov dword [i], 1

l1:
    mov eax, [a]
    imul eax, [*2]
    mov [a], eax
    mov eax, [i]
    add eax, 1
    mov [i], eax

    ; condicion: i <= 2
    cmp eax, 2
    setle al
    test al, al
    jnz l1    ; salta si se cumple

    mov eax, [a]
    mov [total], eax

    ; Salida del programa
    mov eax, 1 
    xor ebx, ebx 
    int 0x80 
