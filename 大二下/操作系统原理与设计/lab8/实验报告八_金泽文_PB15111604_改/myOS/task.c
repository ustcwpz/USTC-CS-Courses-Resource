#include "myOS.h"
#define STACK 0x200

typedef struct myTCB{
    unsigned int pid; //进程序列
    enum state{
        terminated,   //作为进程结束的标志，后面以此判断是否存在于队列中
        ready,        //created
        running,      //running
        waiting
    }state;
    unsigned char reserved[STACK];
    unsigned long *stack;
    int tick;
}myTCB;
int xxx = 0;
unsigned int pid_now = -1;
unsigned long **nextStk;            //for CTX_SW_e
unsigned long **preStk;             //for CTX_SW_e
unsigned long **schedule_point;
unsigned long **eip;
unsigned long **eflags;

//unsigned long **STACK = 0xa800;
myTCB jobs[MAX_TASK + 1];               //all the jobs
unsigned int queue[MAX_TASK + 1];   //queue[0] means the number of the readys
unsigned pid_total = 0;
unsigned long reserve[0x50];

int TICK = 0;
int msecond = 0;
int tmp_msecond = 0;
enum iore{
    i,
    e
}iore = e;

unsigned long* stack_init(unsigned long *stack, void (*task)(void));
void schedule();
void idle();
void enqueue(unsigned int pid);
void dequeue();
int fcfs();
void test_tick();

void osStart(){
disable_interrupt();
    createTsk(initTskBody);
    pMemInit();
    dPartitionInit(pMemHandler, 0x10000);
    clock();
    schedule();
}

//入队列的是进程对应的pid，而不是tcb，jobs数组中保存tcb。
void createTsk(void (*tsk)()){
    myTCB* task = jobs + pid_total;
    task->pid = pid_total++;
    task->state = ready;
    task->stack = &task->reserved[STACK-1];
    task->tick = 0;
    //STACK += 0x200;
    task->stack = stack_init(task->stack, tsk);
    enqueue(task->pid);
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
    *(stack--)   = (unsigned long) 0x77777777;
    *(stack)   = (unsigned long)0x0287;
    return stack;
}

//tskEnd出队列，tcb->state = terminated
void tskEnd(){
    disable_interrupt();
    myTCB *task = jobs + pid_now;
    task->state = terminated;
    dequeue();
    nextStk = preStk;
    preStk = &reserve[0x4f];
    CTX_SW_e();
}

void test_tick(){
    if(pid_now == -1){
        TICK = 2;    
        return;
    }
    jobs[pid_now].tick = (jobs[pid_now].tick + 1) % 100;
    TICK = jobs[pid_now].tick;
}

void schedule(){
    disable_interrupt();
if(pid_now >=0)
    jobs[pid_now].stack = preStk;
    int pid;

    while((pid = fcfs()) != -1){    //如果还有进程
        nextStk = jobs[pid].stack;
        init8253();

        pid_now = pid;

        CTX_SW_s();
        if(queue[0] ==0){
         pid_now = -1;
            idle();
        }

    }

    idle();
    //Should never arrive here.
}

void enqueue(unsigned int pid){
    queue[0] += 1;
    int number = queue[0];
    queue[number] = pid;
}

void dequeue(){
    int pid = pid_now;
    int number = queue[0];
    int i;
    for(i = 1; i <= number; i++){
        if(queue[i] == pid)
            break;
    }
    queue[0]--;
    for(; i < number; i++){
        queue[i] = queue[i + 1];
    }
    queue[number] = 0;
}

//具体出队列操作在tskend实现。
//-1表示没有进程，返回i表示队列中下一个进程
int fcfs(){
    int number = queue[0];
    if(number == 0)
        return -1;
    int ret = queue[1];
    for(int i = 1; i < number ; i++)
        queue[i] = queue[i + 1];
    queue[number] = ret;
    return ret;
}

void idle(){

    xxx = 1;
    init8253();
    enable_interrupt();
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
    if(tmp_msecond != msecond + 1)msecond = tmp_msecond + 1; 
    tmp_msecond ++;   
    if(msecond % 100 != 0){
        if(msecond != 1)return;
    }

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
    short cs;
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
