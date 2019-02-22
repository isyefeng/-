#include "includes.h"

bit m_tim_flag;
U8 m_beyond_temp = 30;	//默认报警温度
U8 m_beyond_dt = 90;		//默认报警湿度

code U8 recv_temp[10] = "010000";
code U8 recv_dt[10] = "010001";
	
void TIM0_Init(void)
{
	TMOD |= 0X01;
	TH0 = (65535-1000)/256;
	TL0 = (65535-1000)%256;
	TR0=1;
	EA = 1;
	ET0=1;
}

void Global_Driver_Init(void)
{
	EXTI_Init();//初始化串口中断
	ESP_Init();
	TIM0_Init();
}

void temperture_error_send(uint8_t* DHT_DATA)
{
		uint8_t send_buf[6] = {0, };
		send_buf[0] = DHT_DATA[0]/10 + 48;
		send_buf[1] = DHT_DATA[0]%10 + 48;
		send_buf[2] = DHT_DATA[2]/10 + 48;
		send_buf[3] = DHT_DATA[2]%10 + 48;
		send_buf[4] = '\r';
		send_buf[5] = '\n';
		ESP_no_return_send("AT+CIPSEND=4\r\n",100);
		ESP_send_commend(send_buf,"OK",100);
}

void main(void)
{
	uint8_t DHT_DATA[4] = {0,};
	U8 * esp_recv = NULL;
	Global_Driver_Init();
	LED1=0;
	if(!ESP_Link_com())
	{
		LED8=0;
		while(1);
	}
	P1 = 0xff;
	while(1)
	{
		if(m_tim_flag)
		{
				Temperture_read(DHT_DATA);
		}
		esp_recv = ESP_recv_data();
		if(esp_recv != NULL)	//接收到wifi发来的命令
		{
			LED1 = 0;
			if(strstr(esp_recv, recv_temp) != NULL)
			{
				m_beyond_temp = (*(esp_recv + 6) - 48)*10 + (*(esp_recv + 7) - 48);//求出传递温度
			}
		}
		P1 = 0xff;
	}
}

void tim0() interrupt 1
{
	static uint8_t index;
	TH0 = (65535-1000)/256;
	TL0 = (65535-1000)%256;
	index++;
	if(index == 200)
	{
		index = 0;
		m_tim_flag = ~m_tim_flag;
	}
}
