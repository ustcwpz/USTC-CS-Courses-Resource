
char string[] = "PB15111604";
int fun(){

    int i;
    char *vga = (char *)0xb8000;
    for(i = 0; i < 600; i++)
    *(vga + i) = 0;
    for(i = 0; i < 10; i++){
    *(vga + i*2) = string[i];
    *(vga + i*2 + 1 ) = 0x2f;
    }
    //*((char *)0xb8400 + 0) = 'P';
    //*((char *)0xb8402) = 'B';

    for(i = 0; i < 100; i++)
    i--;
    return 0;
}

