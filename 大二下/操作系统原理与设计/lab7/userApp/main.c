#include "../myOS/myOS.h"

//=========================my Main===========================================
int myMain(void){

	clear_screen();

	myprintf(0x7,"myMain:HELLO WORLD!\n");	
	osStart();

	//never here    	
	return 0;
}


