#ifndef __MYOS_H__
#define __MYOS_H__

#define MAX_TASK 4

void osStart();
void createTsk(void (*tskBody)(void));
void tskEnd(void);
void initTskBody(void);


#endif