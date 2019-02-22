#include "Delay.h"

void Delay100us(uint32_t time)		//@11.0592MHz
{
	unsigned char i, j;
	while(time--)
	{
		_nop_();
		_nop_();
		i = 2;
		j = 15;
		do
		{
			while (--j);
		} while (--i);	
	}
}

void Delay10ms(uint32_t time)		//@11.0592MHz
{
	unsigned char i, j;

	while(time--)
	{
		i = 108;
		j = 145;
		do
		{
			while (--j);
		} while (--i);
	}
}

