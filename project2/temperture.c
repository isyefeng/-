#include "temperture.h"

static void Delay_10us()		//@11.0592MHz
{
	 U8 i;
	i--;
	i--;
	i--;
	i--;
	i--;
	i--;
}

static void Delay(U16 j)
{     
	U8 i;
	for(;j>0;j--)
	{ 	
	for(i=0;i<27;i++);

	}
}


void Temperture_read(U8* recv_buf)
{
	U8 index1 = 0;
	U8 index2 = 0;
	//��������18ms 
	QD=0;
	 Delay(180);
	 QD=1;
 //������������������ ������ʱ20us
	 Delay_10us();
	 Delay_10us();
	 Delay_10us();
	 Delay_10us();
 //������Ϊ���� �жϴӻ���Ӧ�ź� 
	 QD=1;
 //�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź� �粻��Ӧ����������Ӧ����������	  
	 if(!QD)		 //T !	  
	 {
		 while(!QD);
		 while(QD);
		for(index1 = 0;index1 < 4;index1++)
		{
			for(index2 = 0;index2 < 8;index2++)
			{
				while(!QD);
				Delay_10us();
				Delay_10us();
				Delay_10us();
				recv_buf[index1]<<=1;
				if(QD)
					recv_buf[index1]|=1;
				while(QD);
			}
		}
	}
}