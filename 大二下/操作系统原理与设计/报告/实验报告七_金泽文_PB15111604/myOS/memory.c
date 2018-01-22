#include "myOS.h"
#include "myprintf.h"
unsigned long pMemHandler = 0x100000;

unsigned long align(unsigned long size){
    if(size % 4 == 0)
        return size;
    else 
        return ((size >> 2) << 2) + 4;
}

unsigned long dPartitionInit(unsigned long start, unsigned long size){//初始化并返回dPartition句柄
    size = align(size);
    *(long *)start = size;
    int i;
    for(i = 0; i < size / 0x10; i++){
        *(short *)(start + 4 + 4 * i) = 0;//index 
        *(short *)(start + 6 + 4 * i) = 0;//size 
    }//at most size / 0x10 nodes

    unsigned long j = 0;
    while(j < size / 0x10){
        *(long *)(start + j * 4 + 4 * i + 4) = 0;
        j += 1;
    }
    return start;
}

unsigned long dPartitionInsert(unsigned long dp, int index, unsigned long size){
    unsigned long max_size = *(unsigned long *)dp;  
    int max_nodes = max_size / 0x10;
    int i = max_nodes - 2;
    for(; i > index; i--){
        *(unsigned long *)(dp + 4 * i + 8) = *(unsigned long *)(dp + 4 * i + 4);
    }
    *(short *)(dp + 4 * index + 6) = size;
    if(i == 0){
        *(short *)(dp + 4 * index + 4) = max_nodes * 4 + 4;
        return *(short *)(dp + 4 * index + 4) + dp;
    }
    else{
        *(short *)(dp + 4 * index + 4) = *(short *)(dp + 4 * index) + *(short *)(dp + 4 * index + 2);
        return *(short *)(dp + 4 * index + 4) + dp;
    }
}

unsigned long dPartitionAlloc(unsigned long dp, unsigned long size){//0失败；其他：所分配到的内存块起始地址
    size = align(size);
    unsigned long max_size = *(unsigned long *)dp;  
    int max_nodes = max_size / 0x10;
    int i = 0;
    int available;
    for(; i < max_nodes - 1; i++){
        if(*(short *)(dp + 4 * i + 4) == 0){
            if(i == 0){//none malloced
                if(size <= max_size){
                    return dPartitionInsert(dp, 0, size);
                }
                else 
                    return 0;
            }
            else{
                unsigned long left = max_size - *(short *)(dp + 4 * i) - *(short *)(dp + 4 * i + 2);
                if(size <= left){
                    return dPartitionInsert(dp, i, size);
                }
                else 
                    return 0;
            }
        }
        else if(i < max_nodes - 2){
            if(*(short *)(dp + 4 * i + 8) == 0){
                unsigned long left = max_size + 4 * max_nodes + 4- *(short *)(dp + 4 * i + 4) - *(short *)(dp + 4 * i + 6);
                if(size <= left){
                    return dPartitionInsert(dp, i + 1, size);
                }
                else 
                    return 0;
            }
            else{
                unsigned long available = *(short *)(dp + 4 * i + 8) - *(short *)(dp + 4 * i + 4) - *(short *)(dp + 4 * i + 6);
                if(size <= available)
                    return dPartitionInsert(dp, i + 1, size);
                else return 0;
            }
        }
    }    
    return 0;
}
void dPartitionDelete(unsigned long dp, int inode){
    unsigned long max_size = *(unsigned long *)dp;  
    int max_nodes = max_size / 0x10;
    int i = inode;
    for(; i < max_nodes - 1; i++){
        *(unsigned long *)(dp + 4 * i + 4) = *(unsigned long *)(dp + 4 * i + 8);
    }
}

unsigned long dPartitionFree( unsigned long dp, unsigned long start){ //0失败；1成功
    unsigned long max_size = *(unsigned long *)dp;  
    int max_nodes = max_size / 0x10;
    int i = 0;
    short shift = start - dp;
    for(; i < max_nodes; i ++){
        if(shift == *(short *)(dp + 4 * i + 4)){
            dPartitionDelete(dp, i);
            return 1;
        }
    }
    return 0;
}

unsigned long eFPartitionInit(unsigned long start, unsigned long perSize, unsigned long n){ //初始化并返回eFPartition句柄
    *(unsigned long*)start = n;
    *(unsigned long*)(start + 4) = perSize;
    for(int i = 0; i < n * (perSize + 4); i += 4){
        *(unsigned long*)(start + 8 + i) = (unsigned long)0;
    }
    return start;
}
unsigned long eFPartitionTotalSize(unsigned long perSize, unsigned long n){ //根据单位大小和单位个数，计算出eFPartition所需内存大小
    perSize = align(perSize);
    return n * (perSize + 4) + 8;
    // since each page needs a head and we need a general head.
}
unsigned long eFPartitionAlloc(unsigned long EFPHandler){ //0失败；其他：所分配到的内存块起始地址
    unsigned long n = *(unsigned long*)EFPHandler;
    unsigned long perSize = *(unsigned long*)(EFPHandler + 4);
    int i = 0;
    for(; i < n; i++){
        unsigned long *head = (unsigned long*)(EFPHandler + 8 + perSize * i);
        if(*head == 0){
            *head = 1;
            return head + 4;
        }
    }
    return 0;
}
unsigned long eFPartitionFree(unsigned long EFPHandler,unsigned long mbStart){ //0失败；1成功
    unsigned long n = *(unsigned long*)EFPHandler;
    unsigned long perSize = *(unsigned long*)(EFPHandler + 4);
    int i = 0;
    for(; i < n; i++){
        unsigned long *head = (unsigned long*)(EFPHandler + 8 + perSize * i);
        if(*head == 1 && head + 4 == mbStart){
            *head = 0;
            return 1;
        }
    }
    return 0;
}
void pMemInit(void){ //内存检测并采用dPartition初始化malloc机制
    unsigned long *i = 0x100000;
    while(1){
        *i = 1;
        if(*i != 1){
            myprintf(0x7, "\nmemory available:0x%x\n", i);
            return;
        }
        *i = 2;
        if(*i != 2){
            myprintf(0x7, "\nmemory available:0x%x\n", i);
            return;
        }
        *i = 0; 
        i += 0x1000;
    }
}
