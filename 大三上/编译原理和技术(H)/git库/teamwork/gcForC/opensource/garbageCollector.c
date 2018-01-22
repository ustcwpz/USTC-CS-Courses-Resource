#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapList.h"
#include "list.h"
#include "gcLogger.h"
#include "garbageCollector.h"

ProgramPtrList * programPtrList;
HeapBlockList* heapBlockList;
void * heap;
void * freeBlockHeapPtr;
size_t heapSize;
size_t spaceUsed;
int logging;

//还在读，没读完。后面的代码先复制过来。:



/*
 *  Returns a given heapBlock pointer
 *  from the given address passed in.
 *
 *  If there are two ProgramPtrs that
 *  point to the same HeapBlock, it is
 *  iterating through the list to retrieve
 *  that HeapBlock
 *
 */
HeapBlock* getHeapBlockPtr(void** addr) {
  ProgramPtr* ptr;
  ProgramPtr* next;

  for (ptr = programPtrList->first; ptr; ptr = next) {
    next = ptr->next;

    if (addr == (ptr->varAddr)) {
      debug("HeapBlock Ptr found in HeapBlockList", logging);
      /*if (ptr->heapBlock == 0x1) {
        printf("heapblock is 1\n");
        exit(1);
      }*/
      return ptr->heapBlock;
    }
  }

  throwError("Something wrong happened. getHeapBlock", logging);
  return NULL;//should this just exit instead??
}

/*
 * Find heapblock parent of given address and return
 * heapBlock to set in ProgramPtr
 *
 * if no parent is found, return NULL
 */
HeapBlock* setParent(void **addr) {
  HeapBlock* ptr;
  HeapBlock* next;

  for (ptr = heapBlockList->first; ptr; ptr = next) {
    next = ptr->next;

    if (ptr->heapPtr == *addr) {
      // this is the heapblock we are looking for
      debug("Found parent heap block", logging);
      return ptr;
    }
  }

  return NULL;
}

/*
 *  checks to see if pointer is being tracked
 *  by ptr list, if so update the reference
 *  otherwise add a new ptr
 */
void gcReg(void** addr, HeapBlock* heapBlock, void** heapParentAddr, int isAlloc) {
  ProgramPtr* ptr;

  debug("gcReg", logging);

  if (programPtrList->size == 0) {
    debug("ProgramPtrList is empty, pushing new programPtr", logging);
    push(programPtrList, addr, heapBlock);
  } else {
    // check to see if addr of ptr already exists
    // within programPtrList
    for (ptr = programPtrList->first; ptr != NULL; ptr = ptr->next) {

      if (addr == ptr->varAddr) {
        debug("Found Ptr in ProgramPtrList", logging);
        // this is the ptr we're looking for
        break;
      }
    }

    // if it doesn't exist, push it onto programPtrList
    debug("ptr doesn't exist", logging);
    if (ptr == NULL) {
      push(programPtrList, addr, heapBlock);
      ptr = programPtrList->last;
    }

    if (heapParentAddr != NULL) {
      ptr->heapParent = setParent(heapParentAddr);
    }

    debug("is alloc?", logging);
    if (isAlloc) {
      ptr->heapBlock = heapBlock;
      if (heapBlock == NULL) {
  throwError("NULL heapBlock from gcAlloc!  This should not happen.", logging);
      }
    } else {
      if (*(ptr->varAddr) == NULL) { // TODO: make sure this line is correct.
        logWarning("var is set to null", logging);
        ptr->heapBlock = NULL;
      } else {
        if (heapBlock == NULL) {
          ptr->heapBlock = getHeapBlockPtr(addr);
        } else {
          ptr->heapBlock = heapBlock;
        }
      }
    }

  }
}

/*
 *  Traverses ptr's heapParent to see
 *  if there is a root and still valid memory
 *
 *  TODO:
 *    does it work ( ͡° ͜ʖ ͡°)
 */
int isReachable(ProgramPtr* ptr) {
  debug("Reachable Call", logging);
  ProgramPtr* progPtr;
  ProgramPtr* next;

  debug("is reachable for loop", logging);
  for (progPtr = programPtrList->first; progPtr; progPtr = next) {
    next = progPtr->next;
    if (ptr->heapParent == progPtr->heapBlock) {
      debug("passed in ptr heapParent is equal to itr progptr heapblock", logging);
      if (progPtr->heapParent && isReachable(progPtr)) {
        debug("Yes reachable", logging);
        return 1;
      }
      else if (!progPtr->heapParent) {
        debug("Yes reachable heapParent null", logging);
        return 1;
      }
    }
  }

  debug("Not reachable", logging);
  return 0;
}

/*
 *  Mark and Sweep
 *
 *  Mark: Starting from root, mark all
 *  reachable objects using DFS pointer traversal
 *
 *  Sweep: Scan the heap from beginning to end
 *  and reclaim unmarked objects memory
 *
 *  Might be calling the defragment
 *  function to shift over memory when GC'ing
 *
 */
void garbageCollect() {
  size_t a;
  ProgramPtr* progPtr = NULL;
  HeapBlock* hPtr = NULL;
  HeapBlock* heapNext = NULL;

  debug("Mark phase of GC", logging);
  // Mark
  for (progPtr = programPtrList->first; progPtr != NULL; progPtr = progPtr->next) {
    debug("mark begin", logging);
    if (progPtr->heapParent != NULL && progPtr->heapBlock != NULL) {
      // traverse parent HeapBlock to make sure
      // nothing is referencing it
      // reachability
      debug("Is reachable?", logging);
      if (isReachable(progPtr)) {
        debug("Mark heapBlock 1", logging);
        progPtr->heapBlock->mark = 1;
      }

      // keep it 0
    } else {
      debug("Can Mark block 1?", logging);
      if (progPtr->heapBlock != NULL) {
        debug("Mark heapBlock 1", logging);
        progPtr->heapBlock->mark = 1;
      }
    }
    debug("mark end", logging);
  }
  debug("Mark Complete", logging);

  debug("Sweep phase of GC", logging);
  // Sweep
  for (hPtr = heapBlockList->first; hPtr != NULL; hPtr = heapNext) {
    if (logging) {
      printf("Start of loop\n");
      printf("Heap Pointer List Size: %d\n", heapBlockList->listSize);
      printf("HeapBlock Addr: %p\n", hPtr);

      /*if (hPtr == 0x1) {
        printf("hPtr->next is 1\n");
      }*/

      if (hPtr->next) {
        printf("HeapBlock->next Addr: %p\n", hPtr->next);
      } else {
        printf("hPtr->next doesn't exist\n");
      }
    }
    heapNext = hPtr->next;

    if (logging) {
      printf("HeapNext: %p\n", heapNext);
      printf("hPtr->next: %p\n", hPtr->next);
    }

    if (hPtr->mark == 0) {
      debug("Mark is 0", logging);
      // unreachable memory from Ptr Program
      //
      // defrag
      //
      // TODO: does this work
      //
      // shift heap
      // printf("freeBlockptr: %d\n",  freeBlockHeapPtr);
      // printf("heapPtr: %d\n",  hPtr->heapPtr);

      if (logging) {
        printf("HeapNext: %p\n", heapNext);
        printf("hPtr->next: %p\n", hPtr->next);
      }
      debug("shift", logging);
      //eliminating void* arithmetic and other warnings.
      long t1 = (char*)freeBlockHeapPtr-(((char*)hPtr->heapPtr) + hPtr->size); 
      size_t shiftSize = (size_t)t1;
      size_t zero = 0;
      if (shiftSize > zero) {
        if (logging) {
          printf("Shift heap by size: %zu\n",  shiftSize);
          printf("heap pointer next: %p\n", hPtr->next->heapPtr);
          //printf("heap pointer next by %zu: %p\n", shiftSize, ((hPtr->next->heapPtr)+shiftSize));
          //printf("end heap ptr: %p\n", (heap+heapSize));
        }
  
        if (((char*)(hPtr->next->heapPtr)) >= (((char*)heap)+heapSize)) {
          throwError("what have you done", 1);
          exit(1);
        }

        if ((((char*)(hPtr->next->heapPtr))+shiftSize) > (((char*)heap)+heapSize)) {
          throwError("Shift will go outside allocated heap", 1);
          exit(1);
        }
        else if ((((char*)(hPtr->next->heapPtr))+shiftSize) == (((char*)heap)+heapSize)) {
          logWarning("Shift size equals end of heap. Maybe error?", logging);
        }

        memmove(hPtr->heapPtr, hPtr->next->heapPtr, shiftSize); // shift entire heap to replace unmarked block


        if (logging) {
          printf("HeapNext: %p\n", heapNext);
          printf("hPtr->next: %p\n", hPtr->next);
        }

        //
        // update all heapBlockList ptrs after heapPtr by heapPtr->size
        debug("update heapblocklist", logging);
        HeapBlock* tmp = hPtr->next;
        debug("About to enter while", logging);
        while (tmp) {
          if (tmp->heapPtr) {
            //pointer arithmetic on void* is undefined behavior.
            char* tmp2 = tmp->heapPtr;
            tmp2 -= hPtr->size;
            tmp->heapPtr = tmp2;
          }
          tmp = tmp->next;
        }
        debug("after heapblocklist", logging);

        if (logging) {
          printf("HeapNext: %p\n", heapNext);
          printf("hPtr->next: %p\n", hPtr->next);
        }

        //  update all ProgramPtrs
        ProgramPtr* tmpPPtr;

        debug("update program ptrs", logging);
        //int index = 0;
        for (tmpPPtr = programPtrList->first; tmpPPtr != NULL; tmpPPtr = tmpPPtr->next) {

          if ((tmpPPtr->heapBlock) != NULL && (tmpPPtr->heapBlock->heapPtr) !=NULL ) {
            //FIXME: How do we make sure that tmpPPtr is valid so that we can access its member??
            if(&(tmpPPtr->varAddr) && tmpPPtr->varAddr) {
              *(tmpPPtr->varAddr) = tmpPPtr->heapBlock->heapPtr;//FIXME: This line is dangerous. 
            }
            else {
          throwError("Null varAddr!!!!", 1);
            }
          }
        }
        /* End of shifting operations */
              
        debug("after update program ptrs", logging);

        if (logging) {
          printf("HeapNext: %p\n", heapNext);
          printf("hPtr->next: %p\n", hPtr->next);
        }
      }

      debug("update space used and freeblockheapptr", logging);
      // update space used and freeblockheapptr
      spaceUsed -= hPtr->size;
      //pointer arithmetic on void* is undefined behavior.
      char* tmp1 = freeBlockHeapPtr;
      tmp1 -= hPtr->size;
      freeBlockHeapPtr = tmp1;

      debug("remove heapPtr", logging);
      // remove heapPtr
      // update heapBlockList
      if (logging) {
        printf("HeapNext: %p\n", heapNext);
        printf("hPtr->next: %p\n", hPtr->next);
      }

     if (hPtr == heapBlockList->first) {
       debug("first", logging);
        heapBlockList->first = hPtr->next;
        if (heapBlockList->listSize > 1) {
          hPtr->next->prev = NULL;
        }
      } else if (hPtr == heapBlockList->last) {
       debug("last", logging);
        HeapBlock* t = hPtr->prev;
        t->next = NULL;
             heapBlockList->last = t; 
      } else {
       debug("middle", logging); 
        // can cause segfault
        HeapBlock* t = hPtr->prev;
        HeapBlock* p = hPtr->next;
        t->next = p;
        p->prev = t; 
      }
      heapBlockList->listSize--;

      if (logging) {
        printf("HeapNext: %p\n", heapNext);
        printf("hPtr->next: %p\n", hPtr->next);
      }

      debug("free heapPtr", logging);
      if (logging) {
        printf("Heap Pointer List Size: %d\n", heapBlockList->listSize);

        printf("In loop before free\n");
        printf("HeapBlock Addr: %p\n", hPtr);
        printf("HeapBlock->next Addr: %p\n", hPtr->next);
        printf("HeapNext: %p\n", heapNext);
      }

      free(hPtr);
    }
  }

  debug("Sweep Complete", logging);

  // mark all programPtr heapBlocks to 0 after
  debug("Resetting all marks", logging);
  for (hPtr = heapBlockList->first; hPtr; hPtr = heapNext) {
    heapNext = hPtr->next;
    hPtr->mark = 0;
  }

  debug("After reset", logging);
}

/*
 *  Initialization of program heap space
 */
void initHeap(size_t size) {
  logMsg("Initializing Heap", logging);
  heap = malloc(size);
  memset(heap, 0, size);
  if (logging) {
    printf("Heap addr: %p\n", heap);
  }
}

/*
 *  Checks to see if the program ptr
 *  has already been defined in the
 *  program ptr list. If so, the user
 *  is reallocating the ptr. This will
 *  set that ptr's heapblock to null
 */
void checkPrgPtrExist(void** addr) {
  logWarning("checkProgPtrExist Call", logging);
  ProgramPtr* ptr;
  //ProgramPtr* next;

  for (ptr = programPtrList->first; ptr != NULL; ptr = ptr->next) {

    if (addr == ptr->varAddr) {
      logWarning("Setting heap block to null", logging);
      ptr->heapBlock = NULL;
    }
  }
}

void printProgramPointers(char* msg) {
   logWarning(msg, 1);
   ProgramPtr* pp2; 
   for (pp2 = programPtrList->first; pp2 != NULL; pp2 = pp2->next) {
      printf("(in test)printing programPtr->varAddr: %p\n", pp2->varAddr);
      printf("(in test)printing *(programPtr->varAddr): %p\n", (char*)*(pp2->varAddr));
    }
   logWarning("end debug lines", 1);
   printf("\n");
}

/*
 *  Allocation hook for C Projects
 *
 *  Program will ask for a size
 *  and GC will init block in heap
 *  and create Ptr in ProgramPtrList pointing
 *  to that memory
 *
 *  heapParent
 *
 *    If ProgramPtr exists within a struct, give field pointer
 *    the heap parent so it can figure out whether or not
 *    it can be freed when mark & sweep happens
 *
 *      link address to heaapParent (iterate through heapblock list)
 */
void* gcAlloc(size_t ptrSize, void** addr, void** heapParentAddr) {
  debug("gcAlloc call", logging);
  printf("addr = %p\n", addr);
  debug("Debug Statements Below", logging);
  if (logging) {
    printf("ptrSize: %zu\n", ptrSize);
    printf("heap size: %zu\n", heapSize);
    printf("Space Used: %zu\n", spaceUsed);
    printf("Space Left: %zu\n", (heapSize-spaceUsed));
  }
  debug("Debug Statements End", logging);

  checkPrgPtrExist(addr);

  if (!heap) {
    throwError("Heap doesn't exist!", 1);
    exit(1);
  } else if (heapSize < ptrSize) {
    throwError("Allocation larger than total heap size!", 1);
    exit(1);
  } else if ((heapSize-spaceUsed) < ptrSize) {
    // if no space left and total space is
    // larger than ptrSize, call garbagecollect()
    // to free space

    logWarning("Allocation larger than free space. Running Garbage Collector", logging);
    garbageCollect();

    debug("Post GC", logging);
    if (logging) {
      printf("heap size: %zu\n", heapSize);
      printf("Space Used: %zu\n", spaceUsed);
      printf("Space Left: %zu\n", (heapSize-spaceUsed));
    }
  }

  debug("Check avail space before alloc", logging);
  if ((heapSize-spaceUsed) >= ptrSize) {
    // otherwise...
    // allocate memory from heap and return ptr

    logWarning("Add new heap block pointer to heap block list", logging);
    addNewHeapBlock(heapBlockList, ptrSize, freeBlockHeapPtr);

    logWarning("Calling gcReg to allocate ProgramPtr", logging);
    gcReg(addr, heapBlockList->last, heapParentAddr, 1);
    //
    //  Change freeBlockHeapPtr position by ptrSize passed in
    void* returnPtr = freeBlockHeapPtr;
    debug("Increment freeblockptr", logging);
    // TODO: double check increment
    if (logging) {
      printf("Freeblockptr: %p\n", freeBlockHeapPtr);
      printf("ptrSize: %zu\n", ptrSize);
    }
    //pointer arithmetic on void* is undefined behavior.
    char* tmp = freeBlockHeapPtr;
    tmp += ptrSize;
    freeBlockHeapPtr = tmp;
    if (logging) {
      printf("Freeblockptr after inc: %p\n", freeBlockHeapPtr);
    }
    spaceUsed += ptrSize;
    debug("Done", logging);
    if (logging) {
      printf("Return ptr: %p\n", returnPtr);
      logWarning("returning from gcAlloc()!", logging);
    }

    //DEBUG: testing memory
    // write 0s to allocated memory,
    // read from allocated memory.
    /*logWarning("Testing memory.", logging);
    int* derp;
    for (derp = returnPtr; derp < freeBlockHeapPtr; derp++) {
    *derp = 0;
    printf("memtest read *derp = %d\n", *derp);
    }
    logWarning("Memory test complete.", logging);
*/
    return returnPtr;
  } else {
    if (logging) {
      printf("heap size: %zu\n", heapSize);
      printf("avail space: %zu\n", (heapSize-spaceUsed));
      printf("Ptr size: %zu\n", ptrSize);
    }
    throwError("ERROR: No space left to allocate memory", 1);
    exit(1);
  }
}

/*
 * Initialization Hook for C Projects.
 *
 * size: total space required for
 *  the entire project
 *
 */
void gcInit(size_t size, int log) {
  logMsg("Initializing Garbage Collector", logging);
  logMsg("Allocate a memory block", logging);
  initHeap(size);
  logging = (log ? 1 : 0);
  heapSize = size;
  spaceUsed = 0;
  freeBlockHeapPtr = heap;

  if (logging) {
    printf("Memory Address of Block: %p\n", heap);
  }

  programPtrList = init();

  heapBlockList = initHeapList();
}

/*
 *  Frees all memory used by GC
 */
void gcDestroy() {
  logWarning("Garbage Collector Destroy Invoke!", logging);
  freeList(programPtrList);
  debug("free list done", logging);
  freeHeapBlockList(heapBlockList);
  debug("free heap", logging);
  free(heap);
  logWarning("Garbage Collector Destroyed", logging);
}
