#ifndef HEAPLIST_H
#define HEAPLIST_H

typedef struct HeapBlock{
	size_t size;
	//size_t 
	int mark;
	void * heapPtr;
	struct HeapBlock * next;
	struct HeapBlock * prev;
} HeapBlock;
/*
size_t:
int小于等于数据线宽度，size_t大于等于地址线宽度。size_t存在的最大原因可能是因为：地址线宽度历史中经常都是大于数据线宽度的。在数据只有8位的年代，地址率先进入10位，12位，在数据16位的年代，地址也已经进入了20位，24位。目前的int普遍是32位，而size_t在主流平台中都是64位。
这个网站解释的很好，我看完就明白了:
http://jeremybai.github.io/blog/2014/09/10/size-t
*/

typedef struct HeapBlockList {
	int listSize;
	HeapBlock * first;
	HeapBlock * last;
}HeapBlockList;

HeapBlockList * initHeapList(void);
void addNewHeapBlock(HeapBlockList *list, size_t size, void * heapPtr);
void freeHeapBlockList(HeapBlockList *list);

#endif