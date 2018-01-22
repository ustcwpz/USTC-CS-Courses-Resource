        .ORIG x3000
INITIAL     LEA     R0, PROMPT
            PUTS
            LEA     R6, NAME        ;R6 saves the address of name
            LD      R1, NEWLINE

INPUT       GETC                    ;input the name
            OUT
            ADD     R2, R0, R1 
            BRz     SEARCH
            STR     R0, R6, #0      ;saves the char in R6
            ADD     R6, R6, #1 
            BRNZP   INPUT

SEARCH      LD      R5, FIRST_NODE
            LEA     R6, NAME  
AGAIN       LDR     R5, R5, #0      ;R5 saves the current node addr
            BRZ     NOTFOUND
            ADD     R4, R5, #1      ;R4 points to the last name
            LDR     R4, R4, #0
COMP        LDR     R2, R6, #0      ;R2 saves [R6]
            BRZ     NULL_R2
            LDR     R3, R4, #0      ;R3 saves [R4]
            NOT     R3, R3
            ADD     R3, R3, #1
            ADD     R2, R2, R3
            BRNP    NEXT
            ADD     R6, R6, #1
            ADD     R4, R4, #1
            BRNZP   COMP
NULL_R2     LDR     R3, R4, #0      
            BRZ     FOUND
            BRNZP   NEXT
NEXT        LEA     R6, NAME
            BRNZP   AGAIN

NOTFOUND    LEA     R0, NOENTRY
            PUTS
            HALT

FOUND       ADD     R0, R5, #2
            LDR     R0, R0, #0
            PUTS
            HALT

NAME        .BLKW   16

FIRST_NODE  .FILL   X3300
NEWLINE     .FILL   #-10
PROMPT      .STRINGZ    "Type a last name and press Enter:"
NOENTRY     .STRINGZ    "No Entry"
.END