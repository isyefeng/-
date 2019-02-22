#include "interrupt.h"

uint8_t recv_buf[40];
uint8_t m_index;

void EXTI_Init(void)
{
	TMOD |= 0x20;	  
	TH1 = 253;     
	TL1 = 253;
	TR1 = 1;       
	SCON |= 0x50;	
	ES = 1;
	EA = 1;           
	TI = 0;
	RI = 0;
}

void Send_types(U8* Temp)
{
	while(*Temp != '\0')
	{
		sentTemp(*Temp);
		Temp++;
	}
}

void sentTemp(U8 Temp)
{
	SBUF=Temp; 
	while(!TI);
	TI=0;
}

void RSINTR() interrupt 4 using 2
{
	U8 InPut3;

	if(RI==1)	 	  
	{	
		InPut3=SBUF;
		recv_buf[m_index] = InPut3;
		if(recv_buf[m_index] == '\n')
			m_index = 0;
		else
			m_index++;
		RI=0;								 
	}
}
