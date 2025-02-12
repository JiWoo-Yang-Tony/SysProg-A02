/* FILENAME	: asm.c
 * PROGRAMMER	: Daimon, Quin
 * DATE		: 2025-02-10
 * PURPOSE	: asm.c file holds function convert binary to .asm format
 */

#include <stdio.h>
#include "asm.h"

void binaryToAsm(FILE *inFp, FILE *outFp)
{
	size_t byteCount = 0;
	char buffer[16];

	do
	{
		byteCount = fread(buffer, 1, 16, inFp);
		
		if(byteCount != 0)
		{
			fprintf(outFp, "dc.b\t");
		}
		for(int i = 0; i < byteCount; i++)
		{
			fprintf(outFp, "$%02X%s", buffer[i]);
		
			if((byteCount-1)>i)
			{
				fprintf(outFp, ", ");
			}
			else
			{
				fprintf(outFp, "\n");
			}
		}	
	} while(byteCount > 0);
	return;
}
