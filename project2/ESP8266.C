#include "ESP8266.h"

sbit LED1=P1^0;
sbit LED2=P1^1;
sbit LED3=P1^2;
sbit LED4=P1^3;
sbit LED5=P1^4;
sbit LED6=P1^5;
sbit LED7=P1^6;
sbit LED8=P1^7;		//用于警告返回字符太多

void ESP_Init(void)
{
	EN = 0;
	Delay100us(10);
	EN = 1;
	Delay100us(10);
}

BOOL ESP_send_commend(uint8_t * Temp, uint8_t * hrecv, uint16_t time)
{
	osp_memset(recv_buf, 0, sizeof(recv_buf));	//清除一次串口缓存
	m_index = 0;
	Send_types(Temp);
	Delay100us(time);
	if(m_index >= 20)
		LED8=0;
	m_index = 0;		//从头开始接收
	if(strstr(recv_buf, hrecv) != NULL)
		return TURE;
	else
		return FALSE;
}

void ESP_no_return_send(uint8_t * Temp, uint16_t time)
{
	osp_memset(recv_buf, 0, sizeof(recv_buf));	//清除一次串口缓存
	m_index = 0;
	Send_types(Temp);
	Delay100us(time);
}

U8* ESP_recv_data(void)
{
	if(m_index != 0)
	{
		Delay100us(100);	//10ms延时，足够接收串口发来的数据
		m_index = 0;
		if(strstr(recv_buf, "+IPD,8:") != NULL)
		{
			return recv_buf + 7;
		}
	}
	return NULL;
}

BOOL ESP_Link_com(void)
{
	uint8_t index = 0;
	uint8_t index1 = 0;
	
	for(index1 = 0;index1 < 10;index1++)
	{
		Delay10ms(20);
		if(ESP_send_commend("AT\r\n","OK",100))
		{
			LED2=0;
			Delay10ms(20);
			if(ESP_send_commend("AT+CWMODE=3\r\n","OK",100))
			{
				LED3=0;
				Delay10ms(20);
				for(index = 0;index < 3;index++)
				{
					if(ESP_send_commend("AT+CWJAP=\"TP-LINK_ACEC34\",\"10086111\"\r\n","OK",1000))
					{
						LED4=0;
						Delay10ms(20);
						if(ESP_send_commend("AT+CIPSTART=\"TCP\",\"192.168.1.101\",8080\r\n","OK",500))
						{
							LED5=0;
							ESP_no_return_send("AT+CIPSEND=4\r\n",100);
							ESP_send_commend("TXOK\r\n","OK",100);
							LED6=0;
							return TURE;
						}
					}
					Delay10ms(100);
				}
			}
		}
	}
	return FALSE;
}
