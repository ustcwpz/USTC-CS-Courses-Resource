		.ORIG x3000
;registers are allocated as below:

;0 store current node address &pn
;1 store current node address &mn
;2 store last node address &pn_1
;3 store last node address &mn_1
;4 store current node license pn
;5 store current node license mn
;6 store current node address pmn
;7 store temp values

;initial
		LD  R2, PH 		;read the head address
		BRZ	FINISH
		LDR R0, R2, #0 	;read the first node paddr
		LD  R3, MH 		;read the head address
		BRZ FINISH
		LDR R1, R3, #0  ;read the first node maddr
		LD  R6, PMH

LOOP   	LDR R4, R0, #1  ;read the node plicense
		LDR R5, R1, #1  ;read the node mlicense
		NOT R5, R5
		ADD R5, R5, #1  ;R5 = -m_license
		ADD R7, R5, R4  ;R7 = R4 - R5
		BRZ SAME
		BRN LESS

		LDR R3, R3, #0  ;&mn_1 = &mn
		LDR R1, R1, #0  ;&mn = &mn_next
		BRZ FINISH
		BRNZP LOOP

SAME	STR R0, R6, #0  ;add &pn to pm list
		ADD R6, R0, #0  ;&pmn = &pn
		
		LDR R0, R0, #0  ;&pn = &pn_next
		STR R0, R2, #0  ;&pn_1 = &pn

		LDR R1, R1, #0  ;&mn = &mn_next
		STR R1, R3, #0  ;&mn_1 = &mn
		
		AND R7, R7, #0  ;set R7 = 0
		STR R7, R6, #0  ;set pmn_next = x0000
		
		ADD R0, R0, #0  ;&pn == 0?
		BRZ FINISH
		ADD R1, R1, #0  ;&mn == 0?
		BRZ FINISH
		BRNZP LOOP

LESS    LDR R2, R2, #0  ;&pn_1 = &pn
		LDR R0, R0, #0  ;&pn = &pn_next
		
		ADD R0, R0, #0  ;&pn == 0?
		BRZ FINISH
		BRNZP LOOP




PH		.FILL x4000
MH		.FILL x4001
PMH  	.FILL x4002

FINISH	HALT
.END