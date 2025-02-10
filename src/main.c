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
				// -i -o -srec
			}

			// -i -o
		}

		// -i
	} else {
		if (hasOutputFile) { 
			if (srec) {
				// -o -srec
				// standard input
				// srec
			}
			// -o
			// standard input
			// assembly
		}
		// None
		// standard input
		// assembly
	}

	

	return 0;
}
