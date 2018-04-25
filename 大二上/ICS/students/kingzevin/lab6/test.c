#include <stdio.h>
    // int IR[5];
int main(){
    int place = 0x300e;
    for(int i = 1; i <=16; i++)
        printf("i:%8d %8d %8d\n",i, (place&(1<<i))>>i, ((place&(1<<i))>>i)&1);
    // printf("\nimm = %d\n SEXT = %d\n", imm, SEXT(4));
    return 0;
}

