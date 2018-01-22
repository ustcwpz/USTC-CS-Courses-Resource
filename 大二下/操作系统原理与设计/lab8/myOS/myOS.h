#ifndef __MYOS_H__
#define __MYOS_H__

#define MAX_TASK 4
#include "myprintf.h"
// #include "memory.h"


unsigned long align(unsigned long size);
unsigned long dPartitionInsert(unsigned long dp, int index, unsigned long size);
void dPartitionDelete(unsigned long dp, int inode);

unsigned long dPartitionInit(unsigned long start, unsigned long size);//初始化并返回dPartition句柄
unsigned long dPartitionAlloc(unsigned long dp, unsigned long size);//0失败；其他：所分配到的内存块起始地址
unsigned long dPartitionFree( unsigned long dp, unsigned long start); //0失败；1成功

unsigned long eFPartitionInit(unsigned long start, unsigned long perSize, unsigned long n); //初始化并返回eFPartition句柄
unsigned long eFPartitionTotalSize(unsigned long perSize, unsigned long n); //根据单位大小和单位个数，计算出eFPartition所需内存大小
unsigned long eFPartitionAlloc(unsigned long EFPHandler); //0失败；其他：所分配到的内存块起始地址
unsigned long eFPartitionFree(unsigned long EFPHandler,unsigned long mbStart); //0失败；1成功

void pMemInit(void); //内存检测并采用dPartition初始化malloc机制

unsigned long pMemHandler; //动态内存的dPartition句柄
#define malloc(size)  dPartitionAlloc(pMemHandler,size)
#define free(start)   dPartitionFree(pMemHandler,start)

void osStart();
void createTsk(void (*tskBody)(void));
void tskEnd(void);
void myprintf(int color,const char *format, ...);
void clear_screen(void);

void initTskBody(void);

#endif
