#include <stdio.h>

int get(int fp){
    return fp;
}

int main()
{
    FILE *fp = fopen("l","w");
    fclose(fp);             //fclose - 1
    
    for(int i = 0; i < 10; i++)
        fp--;
    fp += 10;               //unchanged.

    fclose(fp);             //fclose - 2

    FILE *fpp = get(fp);
    fclose(fpp);            //fclose - 3

    return 0;
}