#include "myprintf.h"
#include <stdarg.h>
int cursor_row, cursor_col;
char print[80];

void put_char(char c, char color) {

    unsigned char *ptr = (unsigned char *)0xb8000;
    if(c == '\n'){
        cursor_col = 0;
        cursor_row = (cursor_row + 1) % 25;
    }
    else{
        ptr[(cursor_row * 80 + cursor_col) * 2] = c;
        ptr[(cursor_row * 80 + cursor_col) * 2 + 1] = color;  
        if(cursor_col == 80){
            cursor_row += 1;
            cursor_col = 0;
        }
        else{
            cursor_col ++;
        }
    }
}

void put_chars(char *format, char color){
    char *ptr = format;
    char c;
    
    c = *ptr;
    while (c!='\0'){
        put_char(c, color);     
        c = *(++ptr);
    }
}

void myprintf(int color, const char *format, ...){
    va_list ap;

    va_start(ap, format);
    int i_print, i_format;
    for(i_print = 0; i_print < 80; i_print++){
        print[i_print] = '\0';
    }
    i_print = 0;
    i_format = 0;
    int vi;
    unsigned long vl;

    while(format[i_format] != '\0'){
        if(format[i_format] == '%'){
            if(format[i_format + 1] == 'x'){
                vl = va_arg(ap, unsigned long);
                i_format += 2;
                unsigned long mask = 0xf0000000;
                int hex;
                int i = 28;
                while(mask != 0){
                    hex = (vl & mask) >> i;
                    if(hex > 9)
                        print[i_print++] = hex - 10 + 'a';
                    else
                        print[i_print++] = hex + '0';
                    mask = mask / 16;
                    i = i - 4;
                }
                continue;
            }
            else if(format[i_format + 1] == 'd'){
                vi = va_arg(ap, int);
                i_format += 2;
                if(vi == 0){
                    print[i_print++] = '0';
                    continue;
                }
                int decimal[10];
                int i;
                for(i = 9; i >= 0; i--){
                    decimal[i] = vi % 10;
                    vi = vi / 10;
                }                
                i = 0;
                while(decimal[i] == 0)
                    i++;
                for(i = i; i < 10; i++){
                    print[i_print++] = decimal[i] + '0';
                }
                continue;
            }
        }
        print[i_print++] = format[i_format++];
    }
    va_end(ap);

    put_chars(print, color);
}

void clear_screen(void) {
    int row, col;
    unsigned short *ptr = (unsigned short *)0xb8000;
    for(row = 0; row < 25; row++) {
        for (col = 0; col < 80; col++) {
            (*ptr++) = 0;
        }
    }
}

