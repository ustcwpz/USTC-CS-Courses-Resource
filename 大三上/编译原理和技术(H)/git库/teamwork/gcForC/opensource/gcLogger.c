#include <stdio.h>
#include "gcLogger.h"

void throwError(char *err, int log){
	if(log){
		fprintf(stderr, "\x1B[31m[GCErr] - %s\n", err);
		printf("\x1b[0m");
	}
}
// 是给输出的文字添加颜色。[31m是选择红色。[0m是选择黑色。


void logWarning(char* msg, int log) {
  if (log) {
    printf("\x1B[33m[GCWrn] - %s\n", msg);
    printf("\x1b[0m");
  }
}

void logMsg(char* msg, int log) {
  if (log) {
    printf("\x1B[0m[GCMsg] - %s\n", msg);
  }
}

void runTest(char* msg, int log) {
  if (log) {
    printf("\x1B[32m[GCTst] - %s\n", msg);
    printf("\x1b[0m");
  }
}

void debug(char* msg, int log) {
  if (log) {
    printf("\x1B[34m[GCDbg] - %s\n", msg);
    printf("\x1b[0m");
  }
}
