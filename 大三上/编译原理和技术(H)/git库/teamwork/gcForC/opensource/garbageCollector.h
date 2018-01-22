#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H 
#include "heapList.h"
#include "list.h"
#include "gcLogger.h"

void gcReg(void** addr, HeapBlock* heapBlock, void** heapParentAddr, int isAlloc);
void* gcAlloc(size_t ptrSize, void** addr, void** heapParent);
void gcInit(size_t size, int log);
void gcDestroy(void);
HeapBlock* getHeapBlockPtr(void** addr);
HeapBlock* setParent(void **addr);
int isReachable(ProgramPtr* ptr);
void garbageCollect(void);
void initHeap(size_t size);
void checkPrgPtrExist(void** addr);
void printProgramPointers(char* msg);


#endif