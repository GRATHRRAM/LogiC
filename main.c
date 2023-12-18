#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inter.c"
#include "strc.c"


int main(void) 
{
	printf("LogiC - by GRATHRRAM (pre alpha)\n");
	char inp[255];

	bits bt;
	bt = inter2bits("11");


	
	

	for (int c = 0; c < bt.len;c++) {
		printf("%d\n", bt.bit[c]);
	}

	/*while (1)
	{
		scanf("%255S", &inp);
		if()
	}*/
}