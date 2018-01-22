.section .text
.globl _start32
_start32:  
    jmp init_stack

init_stack:

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

new:
    call set_idt
    movl idt_reg, %ebx
    add  $2, %ebx
    movl IDT_ADDRESS, %eax

    movl %eax, (%ebx)
    lidt idt_reg
    call init8259A
    call init8253
call_main:
    call myMain

    .global CTX_SW_e   
CTX_SW_esdf:
    pusha
    pushf
    # movl preStk, %eax
    # movl %esp, (%eax)
    movl %esp, preStk
    movl nextStk, %esp
    popf
    sti
    popa
    ret
    

    .global CTX_SW_s  
CTX_SW_e:
CTX_SW_s:

    pusha
    pushf
    # movl preStk, %eax
    # movl %esp, (%eax)
    movl %esp, preStk

    movl nextStk, %esp
    popf
    popa
    sti
    ret


    .global INTERRUPT
INTERRUPT:
    pusha
    pushf
    cli
    call clock

    #mov $0x20, %al
    #out %al, $0x20 #EOI

    movl xxx, %eax
    subl $1, %eax
    jz  idleidle
    call test_tick
    movl TICK, %eax
    addl $0, %eax
    jnz  IRET

    movl %esp, preStk

    call schedule
IRET:
    popf
    popa
    iret

idleidle:
    popf
    popa
    iret

    .globl init8259A
init8259A:
    mov $0xff, %al
    out %al, $0x21
    out %al, $0xA1
    
    mov $0x11, %al
    out %al, $0x20
    
    mov $0x20, %al
    out %al, $0x21
    
    mov $0x04, %al
    out %al, $0x21
    mov $0x03, %al
    out %al, $0x21

    
  mov $0x11, %al
    out %al, $0xA0
    
    mov $0x28, %al
    out %al, $0xA1
    
    mov $0x02, %al
    out %al, $0xA1

  mov $0x01, %al
    out %al, $0xA1

    ret

    .globl init8253
init8253:
    mov $0x34, %al
    out %al, $0x43
    
  # ?100HZ?
    mov $(11932 & 0xff), %al
    #mov $1, %al
    out %al, $0x40
    
    mov $(11932 >> 8), %al
    #mov $1000, %al
    out %al, $0x40  

    mov $0xFE, %al
    out %al, $0x21
    ret

    .globl enable_interrupt
enable_interrupt:
    sti
    ret

    .globl disable_interrupt
disable_interrupt:
    cli
    ret

idt_reg:
    .word 0x0800
    .long 0x00001000

