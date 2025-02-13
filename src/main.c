#include <stdio.h>
#include <string.h>
#include "command.h"
#include "fileIO.h"
#include "srec.h"
#include "asm.h"
#include "stdIO.h"
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
            		if (srec) {
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);

										binaryToSrec(inFp, outFp);

										closeFile(inFp);
										closeFile(outFp);
            		} else {
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);
										
									  binaryToAsm(inFp, outFp);
	
										closeFile(inFp);
										closeFile(outFp);
            		}
        	} else {
								addFileExt(inputFileName, outputFileName, srec);

            		if (srec) {
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);

										binaryToSrec(inFp, outFp);

										closeFile(inFp);
										closeFile(outFp);
            		} else {
										inFp = openInputFile(inputFileName);
										outFp = openOutputFile(outputFileName);

										binaryToAsm(inFp, outFp);

										closeFile(inFp);
										closeFile(outFp);
            		}	
        	}
    	} else {
        	if (hasOutputFile) {
            		if (srec) {
                		printf("case 4\n");  // stdin -> output.srec
										outFp = openOutputFile(outputFileName);
										
										binaryToSrec(stdin, outFp, "DAIMON-JIWOO");

										closeFile(outFp);
            		} else {
                		printf("case 3\n");  // stdin -> output.asm
										outFp = openOutputFile(outputFileName);

										binaryToAsm(stdin, outFp);

										closeFile(outFp);
            		}
        	} else {
            		if (srec) {
                		printf("case 2\n");  // stdin -> stdout (srec)
										binaryToSrec(stdin, stdout, "DAIMON-JIWOO");
            		} else {
                		printf("case 1\n");  // stdin -> stdout (asm)
										binaryToAsm(stdin, stdout);
        	    	}
        	}
    	}	

	return 0;
}
