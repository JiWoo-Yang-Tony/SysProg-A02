#include <stdio.h>

FILE* openInputFile(char *fileName);

FILE* openOutputFile(char *fileName);

void closeFile(FILE *fp);

void addFileExt(char *fileName, bool srec); 
