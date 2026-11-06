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
    add eax, 2
    mov [a], eax
    mov eax, [i]
    add eax, 1
    mov [i], eax
    mov eax, [i]
    cmp eax, 2
    setle al
    movzx eax, al
    mov ecx, 1
    cmp ecx, 0
    setg cl
    movzx ecx, cl
    and eax, ecx
    test eax, eax
    jnz l1
    mov eax, [a]
    mov [total], eax

    ; Salida del programa
    mov eax, 1 
    xor ebx, ebx 
    int 0x80 
