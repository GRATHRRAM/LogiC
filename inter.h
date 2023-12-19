#ifndef INTER_H
#define INTER_H
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "gates.h"
#include "strc.h"
//interpreter

bits inter(bits BITS, char gate[3]);
bits inter2bits(char *STRING);

bits inter(bits BITS, char gate[3]) {
	bool* buff = (bool*) malloc(sizeof(bool) * BITS.len);
	size_t buff_len = 0;
	if (strcmp(gate, "not") == 0) {
		for (size_t bit = 0; bit < BITS.len;bit++)
		{
			buff[bit] = not(BITS.bit[bit]);
		}
		buff_len = BITS.len;
	}
    else if (strcmp(gate, "and") == 0) {
		size_t helpr = 0;
		for (size_t bit = 0; bit + 1 <=  BITS.len;bit+=2)
		{
			buff[helpr] = and(BITS.bit[bit], BITS.bit[bit+1]);
			helpr++;
		}
		buff_len = helpr;
	}
	else if (strcmp(gate, "nand") == 0) {
		size_t helpr = 0;
		for (size_t bit = 0; bit + 1 <=  BITS.len;bit+=2)
		{
			buff[helpr] = nand(BITS.bit[bit], BITS.bit[bit+1]);
			helpr++;
		}
		buff_len = helpr;
	}
	else if (strcmp(gate, "or") == 0) {
		size_t helpr = 0;
		for (size_t bit = 0; bit + 1 <=  BITS.len;bit+=2)
		{
			buff[helpr] = or(BITS.bit[bit], BITS.bit[bit+1]);
			helpr++;
		}
		buff_len = helpr;
	}
	else if (strcmp(gate, "nor") == 0) {
		size_t helpr = 0;
		for (size_t bit = 0; bit + 1 <=  BITS.len;bit+=2)
		{
			buff[helpr] = nor(BITS.bit[bit], BITS.bit[bit+1]);
			helpr++;
		}
		buff_len = helpr;
	}
	else if (strcmp(gate, "xor") == 0) {
		size_t helpr = 0;
		for (size_t bit = 0; bit + 1 <=  BITS.len;bit+=2)
		{
			buff[helpr] = xor(BITS.bit[bit], BITS.bit[bit+1]);
			helpr++;
		}
		buff_len = helpr;
	}
	else if (strcmp(gate, "nxor") == 0) {
		size_t helpr = 0;
		for (size_t bit = 0; bit + 1 <=  BITS.len;bit+=2)
		{
			buff[helpr] = xnor(BITS.bit[bit], BITS.bit[bit+1]);
			helpr++;
		}
		buff_len = helpr;
	}


	bits bt;
	STRC_Alloc_Bites(&bt, buff_len);
	bt.bit = buff;
	return bt;
}

bits inter2bits(char *STRING) {
	size_t counter = 0;
	bool *buff = (bool*) malloc(sizeof(bool));
	while (STRING[counter] != '\0') {
		if(counter > 1) buff = (bool*) realloc(buff, sizeof(bool) * counter);
		if(STRING[counter] == '1') buff[counter] = true;
		if(STRING[counter] == '0') buff[counter] = false;
		counter++;
	}
	bits bt;
	STRC_Alloc_Bites(&bt, counter);
	bt.bit = buff;
	return bt;
}
#endif // !INTER_H