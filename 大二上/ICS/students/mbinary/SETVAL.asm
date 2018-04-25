                .ORIG    x3000 

CHECK           LD R0,HI
		TRAP X22
		LD R0,NEWLINE
		TRAP X21
		LDI R1, KBSR
		BRzp  CHECK
		
l2		LDI R3, DSR
		BRzp   l2
		LDI R4,KBDR		
		STI R4, DDR 
		BRnzp  CHECK

KBSR       	.FILL xFE00 
KBDR		.FILL XFE02
DSR		.FILL XFE04
DDR		.FILL XFE06
NEWLINE		.FILL X000A
HI		.STRINGZ "INPUT SOMETHING "
                .END 