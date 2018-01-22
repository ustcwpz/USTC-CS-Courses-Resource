.code16
.section .text
.globl _start16;
_start16:     
    cli                     # 关中断

init1:
# 关中断后的初始化

    mov $0xb800, %eax       # 赋值es，由于段基址稍后会左移4位，故只需b800
    mov %eax, %es
    mov $4000, %edx         # 由于vga有25行80列，每处2个字节，故赋值4000
    mov $0, %edi

clear_loop:
# 清屏循环    
    movb $0, %es:(%di)      # 清屏
    inc %di                 # 低字节存输出字符
    inc %di                 
    cmp %dx, %di
    jne clear_loop          # 跟4000比较

init_hello:
# 清屏后的初始化    
    lea hello, %si          # si存hello偏移地址
    mov $0, %di             # di置零

    mov $0, %cx             # 作为计数器，与后面的字符串长度进行比较用

print_hello:
    cld                     # 设置movsb中di，si自动变化方向
    movsb                   # 从ds:si传字符到es:di
    movb $0x2f, %es:(%di)   # 设置背景、字符颜色

    inc %di
    inc %cx
    cmp $15, %cx            # 比较
    jz init_wait              
    jmp print_hello

init_wait:
    lea wait, %si          # si存hello偏移地址
    mov $160, %di            # 换行
    mov $0, %cx             

print_wait:
    cld                     # 设置movsb中di，si自动变化方向
    movsb                   # 从ds:si传字符到es:di
    movb $0x2f, %es:(%di)   # 设置背景、字符颜色
    inc %di
    inc %cx
    cmp $14, %cx            # 比较
    jz polling              
    jmp print_wait

polling:                    # 轮询
    movb $0x10, %ah
    int $0x16
    cmp $0, %al
    jz  polling
    # movb $'a', %es:(%di)     # 测试

init_switch:
    lea start_switch, %si          # si存hello偏移地址
    mov $320, %di            # 换行
    mov $0, %cx             # 作为计数器，与后面的字符串长度进行比较用


print_start_switch:
    cld                     # 设置movsb中di，si自动变化方向
    movsb                   # 从ds:si传字符到es:di
    movb $0x2f, %es:(%di)   # 设置背景、字符颜色
    inc %di
    inc %cx
    cmp $18, %cx            # 比较
    jz load_OS              
    jmp print_start_switch


load_OS:
    # 在这里用bios int13h加载os

    # 加载之前先重置
    movb $0, %dl
    movb $0, %ah
    int $0x13

    # 开始加载到内存
    movw $0, %dx
    movb $0, %ch
    movb $2, %cl
    movw %cs, %ax
    movw %ax, %es
    movw $0x7e00, %bx
    movb $2, %ah
    movb $7, %al
    int $0x13

switch:
    movl $0x00000000, 0x000 # 第0个descriptor保留
    movl $0x00000000, 0x004
    movl $0x0000FFFF, 0x008 # Data segment descriptor
    movl $0x00CF9800, 0x00C # 读/写
    movl $0x0000FFFF, 0x010 # Code segment descriptor
    movl $0x00CF9200, 0x014 # 执行/读
    lgdt gdt_reg


A20:
    in $0x92, %al
    or $2, %al
    out %al, $0x92

cr0:
    movl %cr0, %eax
    or $0x01, %al
    movl %eax, %cr0
    ljmp $0x08, $pmode # 跳转到相对于cs描述符

gdt_reg:
    .word 0x0800
    .long 0x00000000

.code32 # This part is compiled in 32 bits mode
pmode:
    xorl %eax, %eax
    movw $0x10, %ax # 让%ds指向Data segment 
    movw %ax, %ds
    movw %ax, %es
    movw %di, %ax
    movl $0xb8000, %edi
    addl %eax, %edi
    #movw $0x2f42, %es:(%edi)  # 检查是否成功
    #jmp . 

init_ok:
    leal ok, %esi          # esi存hello偏移地址
    mov $0, %cx             

print_ok:
    cld                     # 设置movsb中di，si自动变化方向
    movsb                   # 从ds:si传字符到es:di
    movb $0x2f, %es:(%edi)  # 设置背景、字符颜色
    inc %edi
    inc %cx
    cmp $3, %cx            # 比较
    jz init_done              
    jmp print_ok

init_done:
    leal done, %esi
    mov $0, %cx             
    movl $0xb8000, %edi
    addl $480, %edi

print_done:
    movw $0x2f44, %es:(%edi)  # 检查是否成功
    cld                     # 设置movsb中di，si自动变化方向
    movsb                   # 从ds:si传字符到es:di
    movb $0x2f, %es:(%edi)   # 设置背景、字符颜色
    inc %edi
    inc %cx
    cmp $30, %cx            # 比较
    jz jump_to_32              
    jmp print_done


jump_to_32:
    ljmp $0x08, $0x7e00

hello:
    .asciz "HelloPB15111604"
wait:
    .asciz "Press any key."
start_switch:
    .asciz "Start to switch..."
ok:
    .asciz "OK!"
done:
    .asciz "Now, we are in PROTECTED MODE!"

    . = _start16 + 510       # 在_start后面510字节处
    .byte 0x55             # 即最后在两位设置aa55
    .byte 0xaa  
