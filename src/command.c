#include <stdio.h>
#include <string.h>
#include "command.h"


/* FILENAME : command.c
 * PROGRAMMER : Jiwoo, Yang
 * DATE : 2025-02-10
 */

void readCommand(int argc, char *argv[], Data *data) {

	data->inputFile[0] = '\0';
	data->outputFile[0] = '\0';
	data->srec = false;
	data->help = false;

	for (int i = 1; i < argc; i++) {
		
		if (strcmp(argv[i], "-h") == 0) {
			data->help = true;
			usagePrompt();
		} else if (strncmp(argv[i], "-i", 2) == 0) {
			strncpy(data->inputFile, argv[i] + 2, kFileNameSize - 1); 
		} else if (strncmp(argv[i], "-o", 2) == 0) {
			strncpy(data->outputFile, argv[i] + 2, kFileNameSize - 1); 
		} else if (strcmp(argv[i], "-srec") == 0) {
			data->srec = true;
		} else {
			printf("Error: Unknown Command\n");
			data->help = true;
			usagePrompt();
		}
	}
}

void usagePrompt(void) {
	printf("Usage: \n"
		"-iINPUTFILENAME - input file name\n"
	       	"-oOUTPUTFILENAME - output file name\n"
	       	"-srec - S-Record output\n"
	       	"-h - help\n");
}
