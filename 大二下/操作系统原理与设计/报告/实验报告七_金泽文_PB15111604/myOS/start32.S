.code32
.section .text
.globl _start32;
_start32:     

init_stack:
movl $_lalala, %eax
    movl $_end, %eax
    addl $0x1000, %eax
    movl %eax, %esp
    movl %eax, %ebp

init_bss:
    movl __bss_end, %eax
    movl %eax, %ebx         # %ebx = _bss_start
    subl _bss_start, %eax  # %eax = length of bss
    movl $0, %ecx           # %ecx = counter
bss_loop:
    movb $0, 0(%ebx, %ecx, 1) 
    incl %ecx
    cmpl %eax, %ecx
    jz bss_loop


call_main:
    call myMain

    .global CTX_SW   

CTX_SW:
    pusha
    movl %esp, preStk

    movl nextStk, %esp
    popa
    ret
    
