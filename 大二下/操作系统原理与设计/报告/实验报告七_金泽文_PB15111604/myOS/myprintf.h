#ifndef __MYPRINTF_H__
#define __MYPRINTF_H__ 
#include <stdarg.h>



void put_char(char c, char color);

void put_chars(char *format, char color);

void myprintf(int color, const char *format, ...);

void clear_screen(void);

#endif
