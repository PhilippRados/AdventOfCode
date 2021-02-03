#include <stdio.h>

#define FILELENGTH 1106
#define ARRLEN 288 // result from countBlankLines-function

extern int isBlank(char*);
extern int countBlankLines(FILE*);
extern char **splitElements(FILE*,int);
