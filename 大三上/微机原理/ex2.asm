
    .MODEL SMALL
    .STACK 100H
    .DATA 
BUFFER  db  0
FILE    db  "2.txt", 0
HANDLE  dw  0
NUM     db  50  DUP(0)
SCALE   db  0
TEN     db  10
HUNDRED db  100

    .CODE
    .STARTUP
OPEN_FILE:
    mov     ah, 3dh             ; 打开文件
    mov     al, 0               ; 0-read only
    lea     dx, FILE            ; 文件名称地址
    int     21h             
    jc      QUIT                ; if err
    mov     HANDLE, ax          ; 句柄存储
    lea     bx, NUM             ; bx记录字节存储地址
    mov     cx, 0               ; cx记录已存储个数

START_NEW_NUM:                  ; 新的数字  
    mov     dx, 0               ; 每个数字已读字符
START_NEW_DIG:                  ; 新的位数
    push    bx  
    push    cx
    push    dx

    mov     bx, HANDLE        
    mov     ah, 3fh             ; 读取字符
    lea     dx, BUFFER          ; 缓冲区
    mov     cx, 1               ; 只读1个字符
    int     21h

    pop     dx
    pop     cx
    pop     bx

    test    ax, ax              ; 查看是否EOF-0
    jz      FINISH_READ 

    mov     dh, BUFFER
    sub     dh, 30h
    js      SKIP_ADD_DIG        ; 不是数字
    mov     al, 10
    mul     dl
    mov     dl, al              ; dl = dl * 10,保存高位
    add     dl, dh 
    jmp     START_NEW_DIG

SKIP_ADD_DIG:
    mov     ah, BUFFER
    sub     ah, 20h
    jnz     FINISH_READ
    inc     cx
    mov     [bx], dl            ; 存储数字到NUM数组
    inc     bx
    jmp     START_NEW_NUM

FINISH_READ:

    mov     SCALE, cl    

SORT:                           ; 一共 SCALE-1趟
    dec     cl                  
    jz      FINISH_SORT
    mov     bl, 1

BUBBLE_SORT:
    cmp     bl, SCALE
    jz      SORT
    mov     dl, NUM[bx-1]
    mov     dh, 0
    mov     al, NUM[bx]
    mov     ah, 0
    cmp     ax, dx
    jns     SKIP_SWAP
    mov     NUM[bx-1], al
    mov     NUM[bx], dl

SKIP_SWAP:                      ; swap
    inc     bl
    jmp     BUBBLE_SORT

FINISH_SORT:    
    mov     bx, 0

OUTPUT:                         ; OUTPUT
    cmp     bl, SCALE
    jz      QUIT
    jmp     PRINT

RTN:
    inc     bx
    jmp     OUTPUT

PRINT:
    mov     al, NUM[bx]
    mov     ah, 0
    div     HUNDRED             ; 百位
    mov     dx, ax
    add     dl, 30h
    mov     ah, 2
    int     21h

    mov     ah, 0
    mov     al, dh
    div     TEN                 ; 十位
    mov     dx, ax
    add     dl, 30h
    mov     ah, 2
    int     21h

    mov     dl, dh
    add     dl, 30h             ; 个位
    mov     ah, 2
    int     21h

    mov     dl, 20h             ; 空格
    mov     ah, 2
    int     21h
    jmp     RTN

QUIT:
    .EXIT
    end