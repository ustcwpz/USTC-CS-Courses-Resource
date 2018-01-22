#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapList.h"
#include "list.h"
#include "gcLogger.h"
//这里就是一些简单的链表操作，用来记录各个heap块，目的和做法都很清晰。
HeapBlockList * initHeapList(){
	HeapBlockList * list = malloc(sizeof(HeapBlockList));

	list->listSize = 0;
	list->first = list->last = NULL;
	return list;
}

void addNewHeapBlock(HeapBlockList * list, size_t size, void *heapPtr){
	HeapBlock * block = malloc(sizeof(HeapBlock));

	block->size = size;
	block->mark = 0;
	block->heapPtr = heapPtr;
	block->next = block->prev = NULL;

	if(list->listSize == 0){
		list->first = block;
		list->last = block;
	}else{
		list-last->next = block;
		block->prev = list->last;
		list->last = block;
	}
	list->listSize++;
}

void freeHeapBlockList(HeapBlockList * list){
	HeapBlock * ptr;
	HeapBlock * next;
	if(list->listSize == 0){
		free(list);
	} else{
		for(ptr = list->first; ptr; ptr = next){
			next = ptr->next;
			free(ptr);
		}
		free(list);
	}
}