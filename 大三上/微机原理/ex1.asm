
        .MODEL SMALL
        .DATA
ARRAY   DB  36 DUP(0)       ; 数组元素存储区域
TEN     DB  10              ; 十进制的基数
SIX     DB  6               ; 二维数组的基数
        
        .CODE
        .STARTUP
        LEA     BX, ARRAY   
        MOV     CX, 36
        MOV     DL, 1

FILL:   MOV     [BX], DL    ; 按照要求填充数组
        INC     BX
        INC     DL
        DEC     CX
        JNZ     FILL
        
        LEA     BX, ARRAY   ; 数组指针
        MOV     CH, 0       ; 记录行号
        MOV     CL, 0       ; 记录列号
        
LOOP:   MOV     AL, CH      ; 判断是否需要打印数字
        SUB     AL, CL
        JGE     PRINT_NUM   ; 行号大于等于列号，打印数字

RTN1:   MOV     AL, CL      ; 判断是否需要打印回车 
        SUB     AL, 5
        JZ      PRINT_CRLF  ; 列号等于5，打印回车
        
RTN2:   MOV     AL, CL      ; 更新行列
        MOV     AH, 0
        INC     AL
        DIV     SIX
        MOV     CL, AH      ; AH 余数，CL-列
        ADD     CH, AL      ; AL 商，CH-行
        INC     BX

        MOV     AL, CH      ; 判断程序是否应该结束
        SUB     AL, 6       
        JZ      OVER        ; 行号为6时，结束程序

        JMP     LOOP


PRINT_NUM: 
        MOV     AL, [BX]    ; AX 中为待打印的数字     
        MOV     AH, 0
        DIV     TEN         ; AL 商，AH 
                            ; 余数，除以10之后就是十位数和个位数
        ADD     AL, 48      ; 48 '0'
        ADD     AH, 48
        MOV     DX, AX
        MOV     AH, 2
        INT     21H         ; 打印十位
        MOV     DL, DH
        INT     21H         ; 打印个位
        MOV     DL, 32
        INT     21H         ; 打印空格              
        JMP     RTN1

PRINT_CRLF: 
        MOV     AH, 2       ; 打印回车
        MOV     DL, 13
        INT     21H
        MOV     DL, 10
        INT     21H
        JMP     RTN2 

OVER:        
        .EXIT        
        END
