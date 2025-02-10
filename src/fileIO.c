/* FILENAME  : fileIO.c
 * PROGRAMMER: Jiwoo Yang
 * DATE	     : 2025-02-10
 * PURPOSE   : This file contain fileIO modular function. Open and Close.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileIO.h"
#include "command.h"

FILE* openInputFile(char *fileName) {

	FILE *inFp = fopen(fileName, "rb");
	if (inFp == NULL) {
		printf("Error: Fail to open %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	return inFp;
}

FILE* openOutputFile(char *fileName) {
	
	FILE *outFp = fopen(fileName, "w");
	if (outFp == NULL) {
		printf("Error: Fail to open %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	return outFp;
}

void closeFile(FILE *fp) {
	if (fclose(fp) != 0) {
		printf("Error: Fail to close\n");
	}
}

void addFileExt(char *fileName, bool srec) {
	if (srec) {
		// add .srec
		strncat(fileName, ".srec", kFileNameSize - strlen(fileName) - 1);
	} else {
		// add. asm
		strncat(fileName, ".asm", kFileNameSize - strlen(fileName) - 1);
	}
}

