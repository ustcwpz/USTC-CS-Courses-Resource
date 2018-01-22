;copyright@Jin Zewen of C.S. Schl. of USTC
            .ORIG	x3000          

            AND     R0,R0,#0        ;R0-i=0
LOOP1       ADD     R0,R0,#1        ;i++
            LD      R7, COUNT59
            ADD     R7,R7,R0        ;R7 = R0 - 59
COND1       BRP     SAVE1
            LD      R5, START
            ADD     R5, R5, R0
            ADD     R6, R5, #-1     ;R6=i-1
            AND     R1, R0, #0      ;R1-j=i;R1 = 0

LOOP2       ADD     R1, R1, #1      ;j++
            LD      R7, COUNT60
            ADD     R7, R7, R1      ;R7 = R1 - 60
COND2       BRP     LOOP1
            LDR     R2, R6, #0      ;R2 = [R6]
            ADD     R6, R6, #1      ;R6++
            LDR     R3, R6, #0      ;R3 = [R6]
            NOT     R4, R3
            ADD     R4, R4, #1
            ADD     R4, R4, R2      ;R4 = R2-R3
COND3       BRN     SWAP    
            BRNZP     LOOP2

SWAP        STR     R2, R6, #0      ;[R6] = R2
            STR     R3, R6, #-1     ;[R6-1] = R3
            ADD     R7, R2, #0
            ADD     R2, R3, #0
            ADD     R3, R1, #0
            BRNZP     LOOP2

SAVE1            AND     R0,R0,#0        ;R0-i=0
LOOP13       ADD     R0,R0,#1        ;i++
            LD      R7, COUNT59
            ADD     R7,R7,R0        ;R7 = R0 - 59
COND13       BRP     SAVE
            LD      R5, START
            ADD     R5, R5, R0
            ADD     R6, R5, #-1     ;R6=i-1
            AND     R1, R0, #0      ;R1-j=i;R1 = 0

LOOP23       ADD     R1, R1, #1      ;j++
            LD      R7, COUNT60
            ADD     R7, R7, R1      ;R7 = R1 - 60
COND23       BRP     LOOP13
            LDR     R2, R6, #0      ;R2 = [R6]
            ADD     R6, R6, #1      ;R6++
            LDR     R3, R6, #0      ;R3 = [R6]
            NOT     R4, R3
            ADD     R4, R4, #1
            ADD     R4, R4, R2      ;R4 = R2-R3
COND33       BRN     SWAP    
            BRNZP     LOOP23

SAVE        LD      R1, START       ;save the start_position in R1
            LD      R2, STORE       ;save the store_position in R2
LOOP3       LDR     R0, R1, #0
            BRNZ    STATISTICA 
            STR     R0, R2, #0
            ADD     R1, R1, #1
            ADD     R2, R2, #1
            BRNZP     LOOP3     

STATISTICA  LD      R2, STORE       ;save the store_position in R2
            LD      R3, A           ;R3 = -85
            LD      R4, AP          ;R4 = -18
            AND     R1, R1, #1      ;R1 = 0
LOOP4       LDR     R0, R2, #0      ;R0 = [R2]
            ADD     R0, R0, R3      ;R0 = R0 - 85
            BRN     LOOP5
            ADD     R1, R1, #1      ;R1++
            ADD     R5, R1, R4      ;R5 = R1 - 18
            BRP     LOOP6 
            ADD     R2, R2, #1      ;R2++
            BRNZP     LOOP4
LOOP5       LD      R2, RANKA
            ADD     R0, R1, #0      
            BRN     LOOP5
            STR     R1, R2, #0
            BRNZP     STATISTICB
LOOP6       LD      R2, RANKA
            ADD     R1, R1, #-1
            STR     R1, R2, #0

STATISTICB  NOT     R7, R1
            ADD     R7, R7, #1      ;save the -A in R7
            LD      R2, STORE       ;save the store_position in R2
            LD      R3, B           ;R3 = -75
            LD      R4, BP          ;R4 = -30
            AND     R1, R1, #1      ;R1 = 0
LOOP7       LDR     R0, R2, #0      ;R0 = [R2]
            ADD     R0, R0, R3      ;R0 = R0 - 75
            BRN     LOOP8
            ADD     R1, R1, #1      ;R1++
            ADD     R5, R1, R4      ;R5 = R1 - 30
            BRP     LOOP9 
            ADD     R2, R2, #1      ;R2++
            BRNZP     LOOP7
LOOP8       LD      R2, RANKB
            ADD     R0, R1, #0      
            BRN     LOOP8
            ADD     R1, R1, R7
            STR     R1, R2, #0
            BRNZP     STATISTICD
LOOP9       LD      R2, RANKB
            ADD     R1, R1, #-1
            ADD     R1, R1, R7
            STR     R1, R2, #0

STATISTICD  NOT     R6, R1
            ADD     R6, R6, #1      ;save the -B in R6
            LD      R2, STORE       ;save the store_position in R2
            LD      R4, STORE       ;save the store_position in R4
            NOT     R4, R4
            ADD     R4, R4, #1
            LD      R3, D           ;R3 = -59
            AND     R1, R1, #1      ;R1 = 0
LOOP10      LDR     R0, R2, #0      ;R0 = [R2]
            ADD     R2, R2, #1      ;R2++
            ADD     R0, R0, R3      ;R0 = R0 - 59
            BRP     LOOP10    
            ADD     R5, R2, R4      ;R5 = R2 - STORE
            ADD     R5, R5, R3      ;R5 = (R2-STORE)-59
            ADD     R5, R5, #-2     
            BRZP    LOOP11          ;all pass
            ADD     R5, R2, R4      ;R5 = R2 - STORE
            ADD     R5, R5, #-1
            LD      R4, COUNT60
            ADD     R5, R5, R4
            NOT     R5, R5
            ADD     R5, R5, #1
            LD      R4, RANKD
            STR     R5, R4, #0
 ;           NOT     R5, R5
;            ADD     R5, R5, #1
            LD      R4, RANKC
            LD      R3, COUNT60
            NOT     R3, R3
            ADD     R3, R3, #1
            ADD     R3, R5, R3
            ADD     R3, R6, R3
            ADD     R3, R7, R3
            STR     R3, R4, #0
            HALT     

LOOP11      LD      R5, COUNT60
            NOT     R5, R5
            ADD     R5, R5, #1 
            ADD     R5, R5, R6
            ADD     R5, R5, R7
            LD      R4, RANKC
            STR     R5, R4, #0
            AND     R5, R4, #0
            ADD     R4, R4, #1
            STR     R5, R4, #0
            HALT      


START   .FILL   X3200
STORE   .FILL   X4000    
                                                 
A       .FILL   -85
B       .FILL   -75
D       .FILL   -59

AP      .FILL   -18
BP      .FILL   -30

RANKA   .FILL   X4100
RANKB   .FILL   X4101
RANKC   .FILL   X4102
RANKD   .FILL   X4103

COUNT60 .FILL   -60
COUNT59 .FILL   -59
.END



