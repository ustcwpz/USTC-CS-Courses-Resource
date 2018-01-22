/* init.c */
#include "../myOS/myOS.h"
#include "userApp.h"

char *message1 = "********************************\0";
int row=0,col=0;	

void myTSK0(void){  
  char *message2 = "*     TSK0: HELLO WORLD!       *\0";
	row=8; col=4; put_chars(message1,WHITE,&row,&col);
	row++; col=4; put_chars(message2,WHITE,&row,&col);
	row++; col=4; put_chars(message1,WHITE,&row,&col);	
	
	tskEnd();   //the task is end
}

void myTSK1(void){
  char *message2 = "*     TSK1: HELLO WORLD!       *\0";
	row=12; col=4; put_chars(message1,WHITE,&row,&col);
	row++; col=4; put_chars(message2,WHITE,&row,&col);
	row++; col=4; put_chars(message1,WHITE,&row,&col);	
	
	tskEnd();   //the task is end
}

void myTSK2(void){
  char *message2 = "*     TSK2: HELLO WORLD!       *\0";
	row=16; col=4; put_chars(message1,WHITE,&row,&col);
	row++; col=4; put_chars(message2,WHITE,&row,&col);
	row++; col=4; put_chars(message1,WHITE,&row,&col);	
	
	tskEnd();  //the task is end
}

void initTskBody(void){
  char *message2 = "*        INIT  INIT !          *\0";
	row=4; col=4; put_chars(message1,WHITE,&row,&col);
	row++; col=4; put_chars(message2,WHITE,&row,&col);
	row++; col=4; put_chars(message1,WHITE,&row,&col);

	createTsk(myTSK0);
	createTsk(myTSK1);
	createTsk(myTSK2);
    tskEnd();  // init end
}
