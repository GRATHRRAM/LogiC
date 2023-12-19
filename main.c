#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "inter.h"
#include "strc.h"


int main(void) 
{
	printf("LogiC - by GRATHRRAM (pre alpha 1)\n");
	char inp[255];
	memset(inp,'\0',255);

	bits bt;

	while(scanf("%254s", inp) != EOF)
	{
		if(inp[0] == 'b') {
			bt = inter2bits(inp);
			printf("b ->");
			for (int c = 0; c < bt.len;c++) {
				printf("%d", bt.bit[c]);
			}
			printf("\n");
		}
		else if (strcmp(inp, "sbb") == 0) {
			printf("sbb ->");
			for (int c = 0; c < bt.len;c++) {
				printf("%d", bt.bit[c]);
			}
			printf("\n");
		}
		else if (strcmp(inp, "help") == 0){
			printf("b*bites (010101010)* --- Sets Bites Buffer\n");
			printf("sbb   --- ShowBufferBites\n");
			printf("not   --- use bb to simulate not  gate\n");
			printf("and   --- use bb to simulate and  gate\n");
			printf("nand  --- use bb to simulate nand gate\n");
			printf("or    --- use bb to simulate or   gate\n");
			printf("nor   --- use bb to simulate nor  gate\n");
			printf("xor   --- use bb to simulate xor  gate\n");
			printf("nxor  --- use bb to simulate nxor gate\n");
			printf("cls   --- clears screen\n");
			printf("ctr+c --- exit\n");
			printf("\n\nAnd Gate example..\n11 -> 1\n10 -> 0\n01 -> 0\n00 -> 0\n1000 -> 00");
			printf("\n1100 -> 10\n1111 -> 11\n0011 -> 01\n");
		}
		else if (strcmp(inp, "not") == 0){
			bt = inter(bt,"not");
			printf("not");
			for (int c = 0; c < bt.len;c++) {
				printf("%d", bt.bit[c]);
			}
			printf("\n");
		}
		memset(inp,'\0',255);
	}
}