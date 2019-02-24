#include <stdio.h>
#include <stdbool.h>
#define GPFCON (*(volatile unsigned int *) 0x56000050)
#define GPFDAT (*(volatile unsigned int *) 0x56000054)
#define GPGCON (*(volatile unsigned int *) 0x56000060)
#define GPGDAT (*(volatile unsigned int *) 0x56000064)

#define GPF0_MASK (3 << (2 * 0))
#define GPF2_MASK (3 << (2 * 2))
#define GPF4_MASK (3 << (2 * 4))
#define GPF5_MASK (3 << (2 * 5))
#define GPF6_MASK (3 << (2 * 6))
#define GPG3_MASK (3 << (2 * 3))

#define GPF4_OUT  (1 << (2 * 4))
#define GPF5_OUT  (1 << (2 * 5))
#define GPF6_OUT  (1 << (2 * 6))

void sleep (unsigned long i)
	{

	for(i * 1; i ;i--);


	}

int main(int argc, char * argv[])
{
	bool buff_LED0=false,buff_LED1=false,buff_LED2=false;
	unsigned long dat;
	GPFCON &= ~(GPF0_MASK | GPF2_MASK | GPF4_MASK | GPF5_MASK | GPF6_MASK);
	GPFCON |= GPF4_OUT | GPF5_OUT | GPF6_OUT;
    GPGCON &= ~(GPG3_MASK);
	while(1)
	{
		dat = GPFDAT;
		
		if((dat & 0x01) ==0)
		{
			sleep(80);
			if((GPFDAT & 0x01) ==0)
			buff_LED0 = !buff_LED0;
		}

		if((dat & 0x04) == 0) 
		{
			sleep(80);
			if((GPFDAT & 0x04) == 0) 
			buff_LED1 = !buff_LED1;
			
		}
		if(buff_LED1)
		{
			GPFDAT &= 0xDF;
		}
		else
		{
			GPFDAT |= 0x20;
		}
		if(buff_LED0)
		{
			GPFDAT &= 0xBF;
		}
		else
		{
			GPFDAT |= 0x40;
		}
		dat = GPGDAT;
		if((dat & 0x08) == 0)
		{
			sleep(80);
			if((GPGDAT & 0x08) == 0)
			buff_LED2 = !buff_LED2;
		}
		if(buff_LED2)
		{
			GPFDAT &= 0xEF;
		}
		else
		{
			GPFDAT |= 0x10;
		}
		
	}	

}
