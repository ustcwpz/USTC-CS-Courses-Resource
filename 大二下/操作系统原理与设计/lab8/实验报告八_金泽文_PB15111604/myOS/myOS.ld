/*
 * myOS.ld
 *
 * Linker script for the i386 bootsect code
 */
OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(_start32)

SECTIONS
{
	. = 0x7E00;
	_text_start = .;
	.text		: { *(.text*) }
	__lalala = .;
	
	. = ALIGN(16);
	.data		: { *(.data*) }
	
	. = ALIGN(16);
_lalala = .;
	.bss		:
	{
		__bss_start = .;
		_bss_start = .;
		*(.bss)
		__bss_end = .;
	}
	. = ALIGN(16);
	_end = .;
	. = ALIGN(512);	
    . = 0xa000;
    . = 0xc000;
}

