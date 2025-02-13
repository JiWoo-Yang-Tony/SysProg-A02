#include <stdio.h>

FILE* openInputFile(char *fileName);

FILE* openOutputFile(char *fileName);

void closeFile(FILE *fp);

void addFileExt(char *inputFileName, char *outputFileName, bool srec);
