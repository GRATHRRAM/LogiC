#ifndef INTER_C
#define INTER_C
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "gates.c"
#include "strc.c"
#endif // !INTER_C
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
	bits bt;
	STRC_Alloc_Bites(&bt, buff_len);
	bt.bit = buff;
	return bt;
}

bits inter2bits(char *STRING) {
	size_t counter = 0;
	bool *buff = (bool*) malloc(sizeof(bool));
	while (STRING[counter] != '\n') {
		if(counter > 1) buff = (bool*) realloc(buff, sizeof(bool) * counter);
		buff[counter] = (bool) atoi(STRING[counter]);
		counter++;
	}
	bits bt;
	STRC_Alloc_Bites(&bt, counter);
	bt.bit = buff;
	return bt;
}