/* FILENAME	: srec.c
 * PROGRAMMER	: Jiwoo Yang
 * DATE		: 2025-02-10
 * PURPOSE	: This file holds convert functions binary to srec format
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srec.h"

void byteToHex(uint8_t byte, char *hexStr) {
	sprintf(hexStr, "%02X", byte);
}

uint8_t checkSum(uint8_t count, uint16_t address, uint8_t *data, int dataLen) {
	uint32_t sum = 0;

	sum += count;
	
	sum += (address >> 8) & 0xFF;
	sum += address & 0xFF;

	for (int i = 0; i < dataLen; i++) {
		sum += data[i];
	}

	return (~sum) & 0xFF;
}

void binaryToSrec(FILE *inFp, FILE *outFp) {
	uint16_t address = 0x0000;
	int s1Count = 0;
	const char ourName[13] = "DAIMON-TONY";

	s0(outFp, ourName);

	s1(outFp, inFp, &address, &s1Count);

	s5(outFp, s1Count);

	s9(outFp);
}

void s0(FILE *outFp, const char *ourName) {
	char s0Data[32] = {0};
	int nameLen = strlen(ourName);

	for (int i = 0; i < nameLen && i < 16; i++) {
		byteToHex(ourName[i], &s0Data[i * 2]);
	}

	uint8_t count = 4 + nameLen;
	uint8_t checksum = checkSum(count, 0x0000, (uint8_t *)s0Data, nameLen);

	fprintf(outFp, "S0%02X0000%s%02X\n", count, s0Data, checksum);
}

void s1(FILE *outFp, FILE *inFp, uint16_t *address, int *s1Count) {
    uint8_t buffer[kMaxLen];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, kMaxLen, inFp)) > 0) {
        uint8_t count = 4 + bytesRead;
        uint8_t checksum = checkSum(count, *address, buffer, bytesRead);

        fprintf(outFp, "S1%02X%04X", count, *address);
        for (size_t i = 0; i < bytesRead; i++) {
            char hexData[3];
            byteToHex(buffer[i], hexData);
            fprintf(outFp, "%s", hexData);
        }
        fprintf(outFp, "%02X\n", checksum);

        *address += kMaxLen;
        (*s1Count)++;
    }
}

void s5(FILE *outFp, int s1Count) {
    uint8_t count = 3;
    uint8_t checksum = checkSum(count, s1Count, NULL, 0);

    fprintf(outFp, "S503%04X%02X\n", s1Count, checksum);
}

void s9(FILE *outFp) {
    uint8_t count = 3;
    uint8_t checksum = checkSum(count, 0x0000, NULL, 0);

    fprintf(outFp, "S9030000%02X\n", checksum);
}
