    .model  small
    .stack  200h
    .data

number  db 0
symbol  db 0

    .code  
    .startup
input:
    mov     ah, 1       ; get number
    int     21h
    sub     al, '0'
    mov     number, al
    mov     ah, 1
    int     21h
    mov     symbol, al
    call    printCRLF
print1_1:
    mov     bl, 0
pre_b:
    call    printCRLF
    cmp     bl, number
    jz      finish_1_1
    mov     cl, 0
pre_c:
    cmp     cl, bl
    jg      inc_b
    mov     al, symbol
    call    printAl
    inc     cl    
    jmp     pre_c

inc_b:
    inc     bl
    jmp     pre_b

finish_1_1:
print1_2:
    mov     bl, 0
pre_b1:
    call    printCRLF
    cmp     bl, number
    jz      quit
init_d:
    mov     dl, 0

prec_d:
    mov     al, number
    sub     al, bl
    dec     al
    cmp     dl, al
    jz      init_c
    call    printBlank
    inc     dl
    jmp     prec_d

init_c:
    mov     cl, 0
pre_c1:
    mov     al, bl
    add     al, al
    cmp     cl, al
    jg      inc_b1
    mov     al, symbol
    call    printAl
    inc     cl    
    jmp     pre_c1

inc_b1:
    inc     bl
    jmp     pre_b1

printAl proc            ; print %al
    push    dx
    mov     ah, 2
    mov     dl, al
    int     21h
    pop     dx
    ret
printAl endp

; print '\n'
printCRLF proc
    push ax
    mov     al, 10
    call    printAl
    mov     al, 13
    call    printAl
    pop  ax
    ret
printCRLF endp

; print ' '
printBlank proc
    push ax
    mov     al, ' '
    call    printAl
    pop  ax
    ret
printBlank endp

quit:
    .exit
    end