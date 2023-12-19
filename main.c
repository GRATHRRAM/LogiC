#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inter.h"
#include "strc.h"


int main(void) 
{
	printf("LogiC - by GRATHRRAM (pre alpha 1)\n");
	char inp[255];

	bits bt;
	bt = inter2bits("1010\0");
	bt = inter(bt,"nxor");


	
	

	for (int c = 0; c < bt.len;c++) {
		printf("%d\n", bt.bit[c]);
	}

	/*while (1)
	{
		scanf("%255S", &inp);
		if()
	}*/
}