//test1.c
#include <stdio.h>
int main(){
    long a[1][2];
    int i;
    long b[1][1];
    printf("a:0x%08lx\n", a);
    printf("i:0x%08lx\n", &i);
    printf("b:0x%08lx\n", b);
    printf("b-a:0x%x\n", (unsigned long)b-(unsigned long)a);
    return 0;
}
