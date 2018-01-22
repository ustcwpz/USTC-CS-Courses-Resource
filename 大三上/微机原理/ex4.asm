    .MODEL  SMALL 
    .STACK  3000H
;1:Num,2:+,3:-,4:(,5:),6:$
;先存data,再存type
    .DATA
ERROR_MESSAGE   db  "error!", 0
PRESENT_NUMBER  dw  0
IS_LAST_NUM db 0 
LEGAL_CHARS db  "0123456789+-()$", 0
SYMBOL  db "+-()$", 0
IS_NEGATIVE db  0
EXPRESSION dw 2048 dup(0)
LAST_EXP dw 0
RESULT  db 5 dup(0)
    .CODE
    .STARTUP
    lea     si, EXPRESSION
    mov     [si], '$'
    add     si, 2
    mov     [si], 6
    add     si, 2
    
INPUT:
    
INPUT_AND_CHECK:    
    mov     ah, 1
    int     21h                         ; al = input
    mov     dl, al
    lea     bx, LEGAL_CHARS
CHECK_LOOP:
    mov     al, [bx]
    cmp     al, 0
    jz      ERROR                       ; no matched!
    cmp     dl, al
    jz      LEGAL_CHAR
    inc     bx
    jmp     CHECK_LOOP

LEGAL_CHAR:                             ; dl = char
PROCESS:    
    cmp     dl, 30h
    js      NOT_NUMBER                  ; not a digital char
    sub     dl, 30h
    mov     dh, 0
    mov     cx, dx
    mov     IS_LAST_NUM, 1
    mov     ax, PRESENT_NUMBER          ; exactly a digital char
    mov     bx, 10
    mul     bx                          ; ax *= 10
    add     ax, cx                      ; ax += dx
    mov     PRESENT_NUMBER, ax          ; 不马上入expression数组
    jmp     INPUT
    
NOT_NUMBER:
; 先判断前一个是不是数字，
    mov     al, IS_LAST_NUM
    cmp     al, 0
    jz      LAST_NOT_NUMBER
; 如果前一个是数字，完成前一个的处理。
    mov     ax, PRESENT_NUMBER
    mov     [si], ax
    add     si, 2
    mov     [si], 1
    add     si, 2
    jmp     NOT_UNARY

    
LAST_NOT_NUMBER: 
; 如果前一个不是数字，是否需要插入0，之后再入数组。
; 如果这次dl=-+,并且bl是($，那么插入一个0来正确表示正负
    cmp     dl, '-'
    jz      MIGHT_BE_UNARY              ; 判断前一个type
    cmp     dl, '+'
    jz      MIGHT_BE_UNARY              ; 判断前一个type
    jmp     NOT_UNARY

MIGHT_BE_UNARY:
    mov     bl, [si-2]                  ; bl-前一个type
    cmp     bl, 4
    jz      UNARY
    cmp     bl, 6
    jz      UNARY
    jmp     NOT_UNARY

UNARY:
    mov     word ptr[si], 0
    add     si, 2
    mov     word ptr[si], 1
    add     si, 2
    jmp     NOT_UNARY
NOT_UNARY:
    mov     dh, 0
    mov     [si], dl
    add     si, 2
    cmp     dl, '+'
    jz      PLUS
    cmp     dl, '-'
    jz      MINUS
    cmp     dl, '('
    jz      LEFT_BRACKET
    cmp     dl, ')'
    jz      RIGHT_BRACKET
    cmp     dl, '$'
    jz      DOLLAR

PLUS:
    mov     dl, 2
    jmp     RTN
MINUS:
    mov     dl, 3
    jmp     RTN
LEFT_BRACKET:
    mov     dl, 4
    jmp     RTN
RIGHT_BRACKET:
    mov     dl, 5
    jmp     RTN
DOLLAR:
    mov     dx, 6
    mov     [si], dx
    mov     LAST_EXP, si
    jmp     FINISH_INPUT

RTN:
    mov     [si], dx
    add     si, 2
    mov     ax, 0
    mov     IS_LAST_NUM, al
    mov     PRESENT_NUMBER, ax
    jmp     INPUT 

FINISH_INPUT:
; 开始计算
; 没有必要转化为后缀表达式
; 入栈，遇到(开始计算，算到),入栈，循环直到遇到$,最后一轮计算。
    mov     si, LAST_EXP
    push    [si-2]
    push    [si]
    sub     si, 4
PUSH_LOOP:
    mov     dx, [si]
    cmp     dx, 6
    jz      ENCOUNTER_DOLLAR
    cmp     dx, 4
    jz      ENCOUNTER_LEFT_BRACKET
    push    [si-2]
    push    [si]
    sub     si, 4
    jmp     PUSH_LOOP

ENCOUNTER_DOLLAR:
    pop     ax
    cmp     ax, 1
    jnz     ERROR
    pop     dx
    pop     ax
    cmp     ax, 2
    jz      ADD_D
    cmp     ax, 3
    jz      SUB_D
    cmp     ax, 6
    jz      CAL_FINISH
    jmp     ERROR

ADD_D:
    pop     cx
    pop     cx
    pop     cx
    add     dx, cx
    push    dx
    push    1
    jmp     ENCOUNTER_DOLLAR
SUB_D:
    pop     cx
    pop     cx
    pop     cx
    sub     dx, cx
    push    dx
    push    1
    jmp     ENCOUNTER_DOLLAR

ENCOUNTER_LEFT_BRACKET:
    pop     ax
    cmp     ax, 1
    jnz     ERROR
    pop     dx
    pop     ax
    cmp     ax, 2
    jz      ADD_L
    cmp     ax, 3
    jz      SUB_L
    cmp     ax, 5
    jz      RIGHT_L
    jmp     ERROR

ADD_L:
    pop     cx
    pop     cx
    pop     cx
    add     dx, cx
    push    dx
    push    1
    jmp     ENCOUNTER_LEFT_BRACKET
SUB_L:
    pop     cx
    pop     cx
    pop     cx
    sub     dx, cx
    push    dx
    push    1
    jmp     ENCOUNTER_LEFT_BRACKET
RIGHT_L:
    pop     cx
    push    dx
    push    1
    sub     si, 4
    jmp     PUSH_LOOP


CAL_FINISH:                             ; dx=result
    mov     cx, dx
    lea     si, RESULT

PRINT_CRLF:
    MOV     AH, 2                       ; PRINT_CRLF
    MOV     DL, 13
    INT     21H
    MOV     DL, 10
    INT     21H

    cmp     cx, 0
    jz      PRINT0

IF_NEG:
    cmp     cx, 0
    js      PRINT_NEG
NEXT_IF:
    mov     bx, 10000
    mov     ax, cx
    mov     dx, 0
    div     bx
    add     al, 30h
    mov     [si], al
    inc     si
    mov     cx, dx
    mov     bx, 1000
    mov     ax, cx
    mov     dx, 0
    div     bx
    add     al, 30h
    mov     [si], al
    inc     si
    mov     cx, dx
    mov     bx, 100
    mov     ax, cx
    mov     dx, 0
    div     bx
    add     al, 30h
    mov     [si], al
    inc     si
    mov     cx, dx
    mov     bx, 10
    mov     ax, cx
    mov     dx, 0
    div     bx
    add     al, 30h
    mov     [si], al
    inc     si
    add     dl, 30h
    mov     [si], dl
    jmp     PRINT

PRINT:
    mov     cl, 0
    lea     si, RESULT
    mov     ah, 2
LOOP:
    cmp     cl, 6
    jz      QUIT
    mov     dl, [si]
    int     21H
    inc     si
    inc     cl
    jmp     LOOP

PRINT_NEG:
    mov     ah, 2
    mov     dl, '-'
    int     21h
    not     cx
    inc     cx
    jmp     NEXT_IF

PRINT0:
    mov     ah, 2
    add     dl, 30h
    int     21h
    jmp     QUIT

ERROR:
    lea     bx, ERROR_MESSAGE
ERROR_LOOP:
    mov     dl, [bx]
    cmp     dl, 0
    je      QUIT                        ; '\0',quit
    mov     ah, 2
    int     21h
    inc     bx
    jmp     ERROR_LOOP  


QUIT:
    .EXIT
    END