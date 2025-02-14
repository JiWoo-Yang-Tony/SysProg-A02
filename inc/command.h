#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define kFileNameSize 256

typedef struct {
	char inputFile[kFileNameSize];
	char outputFile[kFileNameSize];
	bool srec;
	bool help;
} Data; 

void readCommand(int argc, char *argv[], Data *data);

void usagePrompt(void); 
