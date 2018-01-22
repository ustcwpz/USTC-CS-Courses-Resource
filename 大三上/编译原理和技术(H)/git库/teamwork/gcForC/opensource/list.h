#ifndef LIST_H
#define LIST_H

typedef struct ProgramPtr{
	void ** varAddr;
	HeapBlock * heapBlock;
	HeapBlock * heapParent;
	struct ProgramPtr * next;
	struct ProgramPtr * prev;
} ProgramPtr;

typedef struct ProgramPtrList
{
	int size;
	ProgramPtr * first;
	ProgramPtr * last;
} ProgramPtrList;

ProgramPtrList* init(void);
void freeList(ProgramPtrList* list);
void push(ProgramPtrList* list, void** value, HeapBlock* heapBlock);
void pop(ProgramPtrList* list);

#endif