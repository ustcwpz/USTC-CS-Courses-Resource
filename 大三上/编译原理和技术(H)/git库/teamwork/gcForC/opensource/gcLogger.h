#ifndef GCLOGGER_H
#define GCLOGGER_H

void throwError(char * err, int log);
void logWarning(char *msg, int log);
void logMsg(char *msg, int log);
void runTest(char *msg, int log);
void debug(char *msg, int log);

#endif

//之前没有看过log的写法和用法， 但是它的处理其实就是Print出来。