#include <stdio.h>
#include <string.h>
#include "command.h"
#include "fileIO.h"
#include "srec.h"
#include "asm.h"
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

	char inputFileName[kFileNameSize] = "";
	char outputFileName[kFileNameSize] = "";

	strcpy(inputFileName, data.inputFile);
	strcpy(outputFileName, data.outputFile);

	FILE *inFp;
	FILE *outFp;

    	if (hasInputFile) {
        	if (hasOutputFile) {
            		if (srec) { // case 8
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);

										binaryToSrec(inFp, outFp);

										closeFile(inFp);
										closeFile(outFp);
            		} else { // case 7
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);
										
									  binaryToAsm(inFp, outFp);
	
										closeFile(inFp);
										closeFile(outFp);
            		}
        	} else {
								addFileExt(inputFileName, outputFileName, srec);

            		if (srec) { // case 6
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);

										binaryToSrec(inFp, outFp);

										closeFile(inFp);
										closeFile(outFp);
            		} else { // case 5
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);

										binaryToAsm(inFp, outFp);

										closeFile(inFp);
										closeFile(outFp);
            		}	
        	}
    	} else {
        	if (hasOutputFile) {
            		if (srec) { // case 4
										outFp = openOutputFile(outputFileName);
										
										binaryToSrec(stdin, outFp);

										closeFile(outFp);
            		} else { // case 3
										outFp = openOutputFile(outputFileName);

										binaryToAsm(stdin, outFp);

										closeFile(outFp);
            		}
        	} else {
            		if (srec) { // case 2
										binaryToSrec(stdin, stdout);
            		} else { // case 1
										binaryToAsm(stdin, stdout);
        	    	}
        	}
    	}	

	return 0;
}
