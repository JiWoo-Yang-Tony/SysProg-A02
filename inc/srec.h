#ifndef SREC_H
#define SREC_H

#include <stdio.h>
#include <stdint.h>

#define kMaxLen 16

void byteToHex(uint8_t byte, char *hexStr);

uint8_t checkSum(uint8_t count, uint16_t address, uint8_t *data, int dataLen);

void binaryToSrec(FILE *inFp, FILE *outFp, const char *authorName);

void s0(FILE *outFp, const char *authorName);

void s1(FILE *outFp, FILE *inFp, uint16_t *address, int *s1Count);

void s5(FILE *outFp, int s1Count);

void s9(FILE *outFp);

#endif // SREC_H

