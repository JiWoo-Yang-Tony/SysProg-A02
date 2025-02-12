/* FILENAME	: asm.c
 * PROGRAMMER	: Daimon, Quin
 * DATE		: 2025-02-10
 * PURPOSE	: asm.c file holds function convert binary to .asm format
 */

#include <stdio.h>
#include "asm.h"
//Testing for git and making sure vim is doing what I want

void binaryToAsm(FILE *inFp, FILE *outFp)
{
	//code go here
	//Each line requires an fprintf(outFp, "dc.b")
	//Since each line of asm starts with that??
	//
	//While(not over 16 bytes)
	//Loop and translate each piece into ASM
	//This needs to be in a bigger loop that does each line
	//->Needs to fprintf each hex with a ','
	//
	//
	int byteCount = 0;
	char buffer[16];
	//Find how many bytes are in the line and add to buffer to go through
	//which i have no idea how to do
	//well, maybe a little idea
	//now im just rambling dont look at my comments, i like comments:
	do
	{
		byteCount = fread(buffer, 1, 16, inFp);
		//i think this loops how i think it does
		
		fprintf(outFp, "dc.b\t");
		for(int i = 0; i < byteCount; i++)
		{
			fprintf(fpOut, "%02X%s", buffer[i]);
		
			if((byteCount-1)>i)
			{
				fprintf(outFp, ", ");
			}
			else
			{
				fprintf(fpOut, "\n");
			}
		}	
	} while(byteCount > 0);
}
