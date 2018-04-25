                .ORIG    x3000 

CHECK           LDI R1, KBSR
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
                .END 