ASM_FLAGS= -m32 --pipe -Wall -fasm -g -O1 -fno-stack-protector
C_FLAGS = -m32 -fno-stack-protector -g

BOOTSECT=start16
BOOTSECT_OBJS=output/${BOOTSECT}.o
BOOTSECT_BIN=output/${BOOTSECT}.bin

USER_APP_OBJS = output/userApp/main.o output/userApp/init.o
MYOS_OBJS     = output/myOS/start32.o output/myOS/task.o output/myOS/memory.o output/myOS/myprintf.o
OS_OBJS       = ${MYOS_OBJS} ${USER_APP_OBJS}

myOS: ${BOOTSECT_BIN} ${OS_OBJS}
	ld -T myOS/myOS.ld ${OS_OBJS} -o output/myOS.elf
	objcopy -O binary output/myOS.elf output/myOS.bin

output/userApp/init.o: userApp/init.c
	gcc -c ${C_FLAGS} userApp/init.c -o output/userApp/init.o

output/userApp/main.o: userApp/main.c
	gcc -c ${C_FLAGS} userApp/main.c -o output/userApp/main.o

output/myOS/task.o: myOS/task.c
	gcc -c ${C_FLAGS} myOS/task.c -o output/myOS/task.o

output/myOS/memory.o: myOS/memory.c
	gcc -c ${C_FLAGS} myOS/memory.c -o output/myOS/memory.o

output/myOS/myprintf.o: myOS/myprintf.c
	gcc -c ${C_FLAGS} myOS/myprintf.c -o output/myOS/myprintf.o


output/myOS/start32.o: myOS/start32.S
	gcc -c ${ASM_FLAGS} myOS/start32.S -o output/myOS/start32.o

output/${BOOTSECT}.o: myOS/${BOOTSECT}.S
	gcc -c ${ASM_FLAGS} myOS/${BOOTSECT}.S -o output/${BOOTSECT}.o	

output/${BOOTSECT}.bin: ${BOOTSECT_OBJS}
	ld -T myOS/${BOOTSECT}.ld ${BOOTSECT_OBJS} -o output/${BOOTSECT}.elf
	objcopy -O binary output/${BOOTSECT}.elf output/${BOOTSECT}.bin
	
clean:
	rm -f output/myOS/* output/userApp/* output/*
