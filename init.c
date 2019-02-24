#include"s3c2440_soc.h"

void memsetup(void)
{
	BWSCON =   0x22011110;
	BANKCON0 = 0x00000700;
	BANKCON1 = 0x00000700;
	BANKCON2 = 0x00000700;
	BANKCON3 = 0x00000700;
	BANKCON4 = 0x00000700;
	BANKCON5 = 0x00000700;
	BANKCON6 = 0x00001801;
	BANKCON7 = 0x00001801;
	REFRESH  = 0x008404f5;
	BANKSIZE = 0x000000b1;
	MRSRB6   = 0x00000020;
	MRSRB7   = 0x00000020;
}

void copy_steppingstone_to_sdram(void)
{/*
	volatile unsigned int * src = (volatile unsigned int *)0x00000000;
	volatile unsigned int * dst = (volatile unsigned int *)0x30000000;
	int i;
	for(i=0;i < 4096;i++)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*/
}

int sdram_test(void)
{
	volatile unsigned char *p = (volatile unsigned char *)0x30000000;
	int i;

	// write sdram
	for (i = 0; i < 1000; i++)
		p[i] = 0x55;

	// read sdram
	for (i = 0; i < 1000; i++)
		if (p[i] != 0x55)
			return -1;

	return 0;
}
