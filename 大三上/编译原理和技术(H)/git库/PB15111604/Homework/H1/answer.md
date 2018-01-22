**源代码** 

```
include <stdio.h>

int main(){

for(long i=0; i<40000;i++);
    puts("test!\n");
FILE* f=fopen("test.txt","w");
fputs("test!!!!!!\n\n",f);
return 0;

}
```

-S -m32

```
	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"test!\n"
.LC1:
	.string	"w"
.LC2:
	.string	"test.txt"
.LC3:
	.string	"test!!!!!!\n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
#循环体【
	movl	$0, -16(%ebp)
	jmp	.L2
.L3:
	addl	$1, -16(%ebp)
.L2:
	cmpl	$39999, -16(%ebp)
	jle	.L3
#】
	subl	$12, %esp
	pushl	$.LC0
	call	puts
	addl	$16, %esp
	subl	$8, %esp
#fopen
	pushl	$.LC1
	pushl	$.LC2
	call	fopen
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	pushl	-12(%ebp)
#fwrite
	pushl	$12
	pushl	$1
	pushl	$.LC3
	call	fwrite
#返回
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 6.3.0-18ubuntu2~14.04) 6.3.0 20170519"
	.section	.note.GNU-stack,"",@progbits
```

-S -m64

```
	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"test!\n"
.LC1:
	.string	"w"
.LC2:
	.string	"test.txt"
.LC3:
	.string	"test!!!!!!\n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
#循环体【
	movq	$0, -16(%rbp)
	jmp	.L2
.L3:
	addq	$1, -16(%rbp)
.L2:
	cmpq	$39999, -16(%rbp)
	jle	.L3

#】
	movl	$.LC0, %edi
	call	puts
#fopen
	movl	$.LC1, %esi
	movl	$.LC2, %edi
	call	fopen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
#fwrite
	movl	$12, %edx
	movl	$1, %esi
	movl	$.LC3, %edi
	call	fwrite
#返回
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 6.3.0-18ubuntu2~14.04) 6.3.0 20170519"
	.section	.note.GNU-stack,"",@progbits
```

