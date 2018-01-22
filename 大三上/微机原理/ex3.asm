    .MODEL  SMALL
    .DATA      
    BIT     EQU 20              ; 答案的最大位长
    ANS     DB  64 DUP(0)       ; 存放高精度答案
    N       DB  19              ; N 为待计算阶乘的对象
    TEN     DB  10              ; 存放10进制的基数

    .CODE
    .STARTUP
    mov     dl, 0
INPUT:
    mov     ah, 1
    int     21h
    sub     al, 30h
    js      FINISH_INPUT
    push    ax
    mov     al, dl
    mov     dl, 10
    mul     dl
    mov     dl, al
    pop     ax
    add     dl, al
    jmp     INPUT

FINISH_INPUT:
    mov     N, dl
    mov     dl, 10
    mov     ah, 2
    int     21h
    mov     dl, 13
    mov     ah, 2
    int     21h
    MOV     CL, N               ; CL 存放当前乘数
    MOV     ANS, 1              ; 初始化答案的个位为 1
FOR:                            ; 依次处理各个乘数
    CMP     CX, 2
    JS      PRINT               ; 乘数为 1 时停止
    JMP     WORK                ; 否则将该乘数乘进答案数组
RTN:
    DEC     CX                  ; 乘数减 1
    JMP     FOR                 ; 重复以上步骤
    
WORK:          
    MOV     BX, 0               ; BX 跟踪答案数组的偏移量 
TIMES:                          ; 将乘数乘到答案的各个位上
    CMP     BX, BIT             
    JZ      FINISH_TIMES        ; 已乘完各个位，准备进位
    MOV     AL, CL              
    MUL     BYTE PTR ANS[BX]    ; 乘法操作，积在 AL 中
    MOV     ANS[BX], AL         ; 将积存入答案数组的对应位
    INC     BX                  ; 更新偏移量
    JMP     TIMES               ; 继续对剩余的位执行乘法操作
FINISH_TIMES:
    MOV     BX, 0               ; BX 跟踪答案数组的偏移量
CARRY:                          ; 对答案数组执行进位操作
    CMP     BX, BIT
    JZ      RTN                 ; 已完成所有进位，可以返回
    MOV     AX, 0
    MOV     AL, ANS[BX]
    DIV     BYTE PTR TEN       ; 对 10 取余数和商
    MOV     ANS[BX], AH         ; 余数重新放进该位
    ADD     ANS[BX+1], AL       ; 商作为进位累加到下一位
    INC     BX                  ; 更新偏移量
    JMP     CARRY               ; 继续对剩余的位执行进位操作
PRINT:                          ; 打印高精度答案
    MOV     BX, BIT             ; BX 跟踪答案数组的偏移量
    MOV     CL, 0               ; CL 为标识位（为1时0需要输出）
PRINT_DIGIT:                    ; 打印一个数位
    MOV     DL, ANS[BX]         ; DL 为当前待输出的数位
    CMP     DL, 0
    JZ      SKIP_SET            ; DL 不为 0，才设置标志位
    MOV     CL, 1               ; 表明之后的 0 不再是前导 0
SKIP_SET:
    CMP     CL, 0               
    JZ      SKIP_PRINT          ; 还未遇见非 0 的数，不可输出
    ADD     DL, 48
    MOV     AH, 2
    INT     21H                 ; 输出当前数位的值
SKIP_PRINT:
    CMP     BX, 0               
    JZ      FINISH              ; 已打印完所有数位，程序结束
    DEC     BX                  ; 更新偏移量
    JMP     PRINT_DIGIT         ; 继续打印剩余数位

FINISH:
    .EXIT
    END

    
