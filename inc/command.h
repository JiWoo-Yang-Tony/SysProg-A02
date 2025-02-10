#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define kEnd -1
#define kProcess 1
#define kFileNameSize 256

typedef struct {
	char inputFile[kFileNameSize];
	char outputFile[kFileNameSize];
	bool srec;
	bool help;
} Data; 

int readCommand(int argc, char *argv[], Data *data);

void usagePrompt(void); 
