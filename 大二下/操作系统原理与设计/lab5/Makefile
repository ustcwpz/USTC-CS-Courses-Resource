all: OS.bin 16.bin

OS.bin: OS.elf
	objcopy -O binary OS.elf OS.bin

16.bin: 16.elf
	objcopy -O binary 16.elf 16.bin

OS.elf: 32.o main.o 32.ld
	ld -T 32.ld 32.o main.o -o OS.elf -g

16.elf: 16.o 16.ld
	ld -T 16.ld 16.o -o 16.elf -g

16.o: 16.s
	gcc -c  16.s -o 16.o  -m32 -g

32.o: 32.s    
	gcc -c  32.s -o 32.o  -m32 -g

main.o: main.c
	gcc -c main.c -o main.o -g -std=c99 -m32

clean: 
	rm *.o *.elf *.bin *.img
    


