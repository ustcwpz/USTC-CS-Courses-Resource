/* init.c */
#include "../myOS/myOS.h"


//n second
void busy_second(int n){
	int second = 0x2000000;// 1秒内大约多少条乘法指令 毛估估
	int a=21,b=31,c;
	for(int i=0;i<n;i++)
		for(int j=0;j<second;j++) c=a*b;  //about 1sec
}

void myTSK0(void){ 
	int i=0;
	
	while(i<10){
		busy_second(1);
		myprintf(0x7,"myTSK0::%d    \n",i);
		i++;
	}
	tskEnd();   //the task is end
}

void myTSK1(void){
	int i=0;
	
	while(i<10){
		busy_second(1);
		myprintf(0x7,"myTSK1::%d    \n",i);
		i++;
	}
	tskEnd();   //the task is end
}

void myTSK2(void){
	int i=0;
	
	while(i<10){
		busy_second(1);
		myprintf(0x7,"myTSK2::%d    \n",i);
		i++;
	}
	tskEnd();  //the task is end
}

void initTskBody(void){
 	myprintf(0x7,"********INIT START\n\n");
	
	createTsk(myTSK0);

	busy_second(4);
	createTsk(myTSK1);

	busy_second(4);
	createTsk(myTSK2);
 	myprintf(0x7,"********INIT END\n\n");
  tskEnd();  // init end
}
