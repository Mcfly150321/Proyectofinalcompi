section .bss
    a resd 1
    i resd 1
    total resd 1
    d resd 1

section .text
    global main

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
    mov ecx, 1
    cmp ecx, 0
    setg cl
    movzx ecx, cl
    and eax, ecx
    test eax, eax
    jnz l1
    mov eax, [a]
    mov [total], eax
    mov dword [i], 1
l2:
    mov eax, [i]
    cmp eax, 5
    setle al
    movzx eax, al
    cmp eax, 0
    je l3
    mov eax, [total]
    add eax, 1
    mov [total], eax
    mov eax, [i]
    add eax, 1
    mov [i], eax
    jmp l2
l3:
    xor eax, eax
    ret
