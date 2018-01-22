#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapList.h"
#include "list.h"
#include "gcLogger.h"

/*
这是一个程序指针list，里面追踪了所有的程序指针。
*/

ProgramPtrList * init(){
  ProgramPtrList* list = malloc(sizeof(ProgramPtrList));
  list->first = list->last = NULL;
  list->size = 0;

  return list;
}

void freeList(ProgramPtrList* list) {
  ProgramPtr* ptr;
  ProgramPtr* next;
  if (list->size == 0) {
    free(list);
  } else {
    for (ptr = list->first; ptr; ptr = next) {
      next = ptr->next;
      free(ptr);
    }
    free(list);
  }
}

void push(ProgramPtrList * list, void **addr, HeapBlock * heapBlock){
	ProgramPtr * ptr = malloc(sizeof(ProgramPtr));
	ptr->varAddr = addr;
	ptr->heapBlock = heapBlock;
	ptr->heapParent = NULL;
	ptr->next = NULL;
	ptr->prev = NULL;

	if(list->size == 0){
		list->first = ptr;
		list->last = ptr;
	}else{
    	list->last->next = ptr;
   		ptr->prev = list->last;
   		list->last = ptr;
  	}
 	list->size++;
}

void pop(ProgramPtrList* list) {
  if (list->size == 0) {
  } else {
    list->last = list->last->prev;
    list->size--;
  }
}