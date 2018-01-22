这个是学习的他人代码，来源：
https://github.com/briancain/garbage-collector
使用方法是#include "garbageCollector.h",然后使用新的malloc和GC函数。

heapList.c和.h是heap块信息，一个链表。每一个node对应一块heap内存，记录了内存的大小，是一个双向链表。  
list.h和.c是程序指针的链表，追踪了指针。  
garbage.h和.c是最主要的内容，里面实现了mark-sweep的GC，使用这套GC，直接include "garbage.h"就可以了。  
gcLogger.h，.c是报告中间信息和信息输出的，可以在garbage.c中设置使能，用来debug或者看中间信息。  
源仓库中含有用于测试的main.c，里面跑了这套GC的demo以及相应的makefile。这里没有重新抄写阅读他们，因此没有放过来。