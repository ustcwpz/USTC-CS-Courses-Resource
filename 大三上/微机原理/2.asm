    .model  small
    .stack  200h
    .data
file    db  'Sample.txt',0
handle  dw  0
buffer  db  0
originData  db 1024 dup(0) 
RESULT  db  16 dup(0)
sixnum  db  6 dup(0)
scale   dw  0
ten     db  10
hundred db  100
digit   db  0
    .code  
    .startup
    call readFile

finish_readFile:
    call    printCRLF
    lea     si, originData
    dec     si
newSixNum:
    lea     bx, sixnum
    mov     cl, 0               ;记录位数

nextChar:
    inc     si

    mov     al, [si]
    call    chartoDigit
    cmp     al, 100
    jz      nextChar
    cmp     al, 13
    jz      lineFinished
    cmp     al, 0
    jz      EOF
    cmp     al, '-'
    jz      minus
    ;else   num
    cmp     cl, 6               ; 超出6位,舍弃
    jz      nextChar
    mov     [bx], al
    inc     cl
    inc     bx
    jmp     nextChar

minus:
    cmp     cl, 0
    jz      nextChar
    dec     cl
    dec     bx
    jmp     nextChar

lineFinished:
    inc     si
    mov     digit, cl
    call    processSixNum
    call    printCRLF
    jmp     newSixNum
EOF:



    jmp     quit






; input al - char
; output al -   if digit 0-35
;               '-' -> '-'
;               '\n' -> '\n'
;               '\r' -> '\r'
;               EOF -> 0
;               else not digit 100
chartoDigit proc
    cmp     al, '9'
    jng     digit_chartoDigit
    cmp     al, 'Z'
    jng     upper_chartoDigit
    cmp     al, 'a'
    js      not_digit_chartoDigit
    sub     al, 'a'-10
    jmp     return_chartoDigit

digit_chartoDigit:
    cmp     al, '0'
    js      not_digit_chartoDigit
    sub     al, '0'
    jmp     return_chartoDigit

upper_chartoDigit:
    cmp     al, 'A'
    js      not_digit_chartoDigit
    sub     al, 'A'-10
    jmp     return_chartoDigit
not_digit_chartoDigit:
    cmp     al, '-'
    jz      return_chartoDigit
    cmp     al, 13
    jz      return_chartoDigit
    cmp     al, 10
    jz      return_chartoDigit
    cmp     al, 0
    jz      return_chartoDigit    
    mov     al, 100
return_chartoDigit:
    ret
chartoDigit endp


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

;   file - "Sample.txt"
;   handle - handle
;   buffer - buffer
;   originData - store
;   scale - num of chars
readFile proc 
openFile:
    pusha
    mov     ah, 3dh         ;openFile
    mov     al, 0
    lea     dx, file
    int     21h
    mov     handle, ax      ;save handle
    mov     cx, 0
    lea     dx, buffer
    lea     di, originData
readByte:
    mov     scale, cx
    mov     cx, 1
    mov     bx, handle
    mov     ah, 3fh
    int     21h
    test    al, al
    jz      return_readFile
    mov     cx, scale
    inc     cx
    mov     al, buffer
    mov     [di], al
    inc     di
    call    printAl    
    jmp     readByte
return_readFile:
    popa
    ret
readFile endp


;  digit - 位数
; sixnum - 处理的三十六进制
processSixNum proc
    pusha
    mov     al, 0
    cmp     al, digit
    jz      ret_processSixNum
    call    printSixNum
ret_processSixNum:
    popa
    ret
processSixNum endp

; digit - 位数
; sixnum - 输出的三十六进制
printSixNum proc
    pusha
init_loop_printSixNum:
    mov     cl, 0
    lea     bx, sixnum
pred_loop_printSixNum:
    cmp     cl, digit
    jz      ret_printSixNum
    mov     al, [bx]
    cmp     al, 10
    js      print_digit_printSixNum
    add     al, 'A'-10
    call    printAl
    jmp     inc_loop_printSixNum

print_digit_printSixNum:
    add     al, '0'
    call    printAl
    jmp     inc_loop_printSixNum
inc_loop_printSixNum:
    inc     cl
    inc     bx
    jmp     pred_loop_printSixNum
ret_printSixNum:
    mov     al, ' '
    call    printAl
    mov     al, '='
    call    printAl    
    mov     al, ' '
    call    printAl 
    popa
    ret

printSixNum endp


quit:
    .exit
    end