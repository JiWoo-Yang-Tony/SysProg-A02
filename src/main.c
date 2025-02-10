#include <stdio.h>
#include "command.h"

int main (int argc, char *argv[]){
	
	Data data;
	bool hasInputFile = false;
	bool hasOutputFile = false;
	bool srec = false;

	readCommand(argc, argv, &data);

	if (data.help) {
		return 0;
	}

	if (data.inputFile[0] != '\0') {
		hasInputFile = true;
	}

	if (data.outputFile[0] != '\0') {
		hasOutputFile = true;
	}

	srec = data.srec;

    	if (hasInputFile) {
        	if (hasOutputFile) {
            		if (srec) {
                		printf("case 8\n");  // input.bin -> output.srec
            		} else {
                		printf("case 7\n");  // input.bin -> output.asm
            		}
        	} else {
            		if (srec) {
                		printf("case 6\n");  // input.bin -> input.bin.srec
            		} else {
                		printf("case 5\n");  // input.bin -> input.bin.asm
            		}	
        	}
    	} else {
        	if (hasOutputFile) {
            		if (srec) {
                		printf("case 4\n");  // stdin -> output.srec
            		} else {
                		printf("case 3\n");  // stdin -> output.asm
            		}
        	} else {
            		if (srec) {
                		printf("case 2\n");  // stdin -> stdout (srec)
            		} else {
                		printf("case 1\n");  // stdin -> stdout (asm)
        	    	}
        	}
    	}	

	return 0;
}
