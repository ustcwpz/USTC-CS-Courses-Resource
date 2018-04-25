.ORIG           X3000
;initialize the stack pointer
        LD      R6, STACK

;set up the keyboard interrupt vector table entry
        LD      R0, INTADD
        STI     R0, KEYINT

;set the IE bit of the keyboard
        LDI     R0, KBSR
        LD      R1, MASKIE
        AND     R0, R1, R0
        BRNP    USER        ;if NP, then IE bit is 
        LDI     R0, KBSR    ;already 1.
        ADD     R0, R1, R0
        STI     R0, KBSR

;start of the user program to print
    
;I'll delay  once after one word

USER    AND     R3, R3, #0
HEL     LEA     R1, HELLO
        AND     R2, R2, #0          ;R2 is the counter of the chars       
        

HEL1    LDR     R0, R1, #0
        OUT   
        ADD     R1, R1, #1          ;R1++
        ADD     R2, R2, #1
        ADD     R4, R2, #-12        ;R4 = R2-12
        BRN     HEL1
        JSR     DELAY 
        ADD     R3, R3, #1          ;R3++
        ADD     R0, R3, #-5
        BRNP    HEL
        AND     R0, R0, #0
        ADD     R0, R0, #10
        OUT                         ;'\n'

WOR     LEA     R1, WORLD
        AND     R2, R2, #0        

WOR1    LDR     R0, R1, #0
        OUT   
        ADD     R1, R1, #1          ;R1++
        ADD     R2, R2, #1
        ADD     R4, R2, #-12        ;R4 = R2-12
        BRN     WOR1 
        JSR     DELAY 
        ADD     R3, R3, #1          ;R3++
        ADD     R0, R3, #-9
        BRNP    WOR
        AND     R0, R0, #0
        ADD     R0, R0, #10
        OUT                         ;'\n'

        BRNZP   USER

DELAY   ST      R1, SAVER1
        LD      R1, COUNT       
REP     ADD     R1, R1, #-1      
        BRP     REP             
        LD      R1, SAVER1
        RET

STACK   .FILL   X3000
KEYINT  .FILL   X0180
INTADD  .FILL   X1500
COUNT   .FILL   X7FFF
MASKIE  .FILL   X4000
KBSR    .FILL   XFE00

SAVER1  .BLKW   1
HELLO   .STRINGZ "HELLO       "
WORLD   .STRINGZ "       WOLRD"
.END