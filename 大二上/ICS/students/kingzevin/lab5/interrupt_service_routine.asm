.ORIG       X1500
        ;.FILL   #0
;save the registers
INT     ST      R0, SAVER0
        ST      R1, SAVER1
        ST      R2, SAVER2
        ST      R3, SAVER3
        ST      R4, SAVER4
        ST      R5, SAVER5
        ST      R7, SAVER7

        JSR     NEWLINE

        LDI     R0, KBDR
        LD      R1, M
        ADD     R0, R1, R0      ;R0=R0-M
        BRZ     MER
        BRNP    HAR

MER     LD      R5, NUM_M
        LEA     R1, MERRY
        BRNZP   PRINT

HAR     LD      R5, NUM_H
        LEA     R1, HARD

PRINT   AND     R2, R2, #0          ;R2 is the counter of the chars       
        
LOOP    LDR     R0, R1, #0
        JSR     OUTPUT   
        ;OUT
        ADD     R1, R1, #1          ;R1++
        ADD     R2, R2, #1          ;R2++
        ADD     R4, R2, R5          ;R4 = R2-12
        BRN     LOOP

        JSR     NEWLINE

;restore the registers        
        LD      R0, SAVER0
        LD      R1, SAVER1
        LD      R2, SAVER2
        LD      R3, SAVER3
        LD      R4, SAVER4
        LD      R5, SAVER5
        LD      R7, SAVER7

        RTI

NEWLINE AND     R0, R0, #0
        ADD     R0, R0, #10

OUTPUT  LD      R4, MASK15 

TEST1   LDI     R3, DSR
        AND     R3, R4, R3
        BRZP    TEST1
        STI     R0, DDR
TEST2   LDI     R3, DSR
        AND     R3, R4, R3
        BRZP    TEST2
        RET



SAVER0  .BLKW 1
SAVER1  .BLKW 1
SAVER2  .BLKW 1
SAVER3  .BLKW 1
SAVER4  .BLKW 1
SAVER5  .BLKW 1
SAVER6  .BLKW 1
SAVER7  .BLKW 1


KBDR    .FILL   XFE02
DSR     .FILL   XFE04
DDR     .FILL   XFE06
MASK15  .FILL   X8000

NUM_M   .FILL   #-16
NUM_H   .FILL   #-9
M       .FILL   XFFB3           ;-M
MERRY   .STRINGZ    "MERRY CHRISTMAS!"
HARD    .STRINGZ    "HARD WORK"
.END