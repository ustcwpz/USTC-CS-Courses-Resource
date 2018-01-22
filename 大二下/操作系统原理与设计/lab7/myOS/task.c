#include "myOS.h"

typedef struct myTCB{
    unsigned int pid; //进程序列
    enum state{
        terminated,   //作为进程结束的标志，后面以此判断是否存在于队列中
        ready,        //created
        running,      //running
        waiting
    }state;
    unsigned long *stack;
}myTCB;

unsigned long **nextStk;            //for CTX_SW
unsigned long **preStk;             //for CTX_SW

unsigned long **STACK = 0xb000;
myTCB jobs[MAX_TASK];               //all the jobs
unsigned pid_num = 0;

int msecond = 0;

unsigned long* stack_init(unsigned long *stack, void (*task)(void));
void schedule();
void idle();


void osStart(){
    createTsk(initTskBody);
    pMemInit();
    schedule();
}

//入队列的是进程对应的pid，而不是tcb，jobs数组中保存tcb。
void createTsk(void (*tsk)()){
    myTCB* task = jobs + pid_num;
    task->pid = pid_num++;
    task->state = ready;
    task->stack = STACK;
    STACK += 0x200;
    task->stack = stack_init(task->stack, tsk);

}   

unsigned long* stack_init(unsigned long *stack, void (*task)(void)){
    *(stack--) = (unsigned long) 0x08;
    *(stack--) = (unsigned long) task;
    *(stack--) = (unsigned long) 0xAAAAAAAA;
    *(stack--) = (unsigned long) 0xCCCCCCCC;
    *(stack--) = (unsigned long) 0xDDDDDDDD;
    *(stack--) = (unsigned long) 0xBBBBBBBB;
    *(stack--) = (unsigned long) 0x44444444;
    *(stack--) = (unsigned long) 0x55555555;
    *(stack--) = (unsigned long) 0x66666666;
    *(stack)   = (unsigned long) 0x77777777;    
    return stack;
}

//tskEnd出队列，tcb->state = terminated
void tskEnd(){
    unsigned int pid = head();
    myTCB *task = jobs + pid;
    task->state = terminated;
    nextStk = preStk;
    preStk = 0xab00;
    CTX_SW();
}

void schedule(){
    int pid;
    dPartitionInit(pMemHandler, 0x10000);
    while((pid = head()) != -1){    //如果还有进程
        nextStk = jobs[pid].stack;
        CTX_SW();
        //free or compact
    }
    idle();
    //Should never arrive here.
}

//具体出队列操作在tskend实现。
//-1表示没有进程，返回i表示队列中第一个进程
int head(){
    int i = 0;
    while(jobs[i].state == terminated && i != MAX_TASK){
        i++;
    }
    if(i == (MAX_TASK))
        return -1;      //-1表示没有进程
    return i;           //返回i表示队列中第一个进程
}

void idle(){
    char string[] = "IDLE";
    int i;
    char *vga = (char *)0xb8000 + 3000;
    //for(i = 0; i < 4000; i++)
    //*(vga + i) = 0;
    for(i = 0; i < 4; i++){
        *(vga + i*2) = string[i];
        *(vga + i*2 + 1 ) = 0x2f;
    }
    while(1);
}


// typedef struct Schedule_Node{
//     struct Schedule_Node* next;
//     unsigned pid;
// }Schedule_Node;


// struct FCFS_Queue{
//     unsigned int length;
//     unsigned int number_ready;
//     unsigned int number_running;
//     Schedule_Node* head;
//     Schedule_Node* tail;
//     Schedule_Node* present;
// }FCFS_Queue;

// void schedule(){
//     Schedule_Node* it = FCFS_Queue.head;
//     while(it != NULL){
//         ;
//     }
// }

void clock(){
    msecond ++;
    if(msecond != 1 && msecond % 100 != 0)return;
    int hour = msecond / 100 / 60 / 60;
    int minute = (msecond / 100 / 60) % 60;
    int second = (msecond / 100) % 60;
    int where = 0xb8000 + 160;
    *(char *)(where - 2) = (second % 10) + '0';
    *(char *)(where - 1) = 0x7;
    *(char *)(where - 4) = (second - second % 10) / 10 + '0';
    *(char *)(where - 3) = 0x7;

    *(char *)(where - 6) = ':';
    *(char *)(where - 5) = 0x7;
    
    *(char *)(where - 8) = (minute % 10) + '0';
    *(char *)(where - 7) = 0x7;
    *(char *)(where - 10) = (minute - minute % 10) / 10 + '0';
    *(char *)(where - 9) = 0x7;

    *(char *)(where - 12) = ':';
    *(char *)(where - 11) = 0x7;

    *(char *)(where - 14) = (hour % 10) + '0';
    *(char *)(where - 13) = 0x7;
    *(char *)(where - 16) = (hour - hour % 10) / 10 + '0';
    *(char *)(where - 15) = 0x7;
}

struct{
    short offset_h;
    char type;
    char zero;
    short ds;
    short offset_l;
}idt_entry;
 long IDT_ADDRESS = 0x1000;
extern INTERRUPT();
void set_idt(){
    long x = (void (*)())INTERRUPT;
    
    //long INTERRUPT = 0x7e82;
    long address = IDT_ADDRESS;
    idt_entry.offset_h = (short)((x >> 16) & 0xff);
    idt_entry.type = 0x8e;
    idt_entry.zero = 0;
    idt_entry.cs = 0x08;
    idt_entry.offset_l = (short)(x & 0xffff);
    for(int i = 0; i < 0x100; i++){
        *(short *)(address + 8 * i) = idt_entry.offset_l;
        *(short *)(address + 8 * i + 2) = idt_entry.cs;
        *(char *)(address + 8 * i + 4) = idt_entry.zero;
        *(char *)(address + 8 * i + 5) = idt_entry.type;
        *(short *)(address + 8 * i + 6) = idt_entry.offset_h;
    }
}