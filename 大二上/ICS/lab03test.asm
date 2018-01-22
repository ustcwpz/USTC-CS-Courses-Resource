;Note that this test case is not comprehensive and 
;you are responsible to test your program using other 
;test cases.
.ORIG x4000

; fill these values starting from address x4000
.FILL x4050
.FILL x4100
.FILL x0000

.BLKW x4D ; skip x4D memory locations

; fill these values starting from address x4050
.FILL x4150
.FILL x4567

.BLKW xAE ; skip xAE memory locations

; fill these values starting from address x4100
.FILL x5000
.FILL x0123

.BLKW x4E ; skip x4E memory locations

; fill these values starting from address x4150
.FILL x4550
.FILL x89AB

.BLKW x3FC ; skip x3FC memory locations

; fill these values starting from address x454E
.FILL x0000
.FILL xCDEF
.FILL x0000
.FILL xCDEF

.BLKW xAAE ; skip xAAE memory locations

; fill these values starting from address x5000
.FILL x454E
.FILL x4567

.END