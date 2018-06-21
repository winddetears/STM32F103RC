#include "dht11.h"


/*
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ��V1.0.0
*/


//DHT11 --> PC6

//dht11��ʼ��

void dht11_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//ʹ��PA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_6;       //�˿�����
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_Out_PP;                     	
	GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;                         
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
}



//������λ�ź�
void dht11_rst(void)
{
	DHT11_OUTPUT();
	DHT11_DATA_OUT = 0;
	delay_ms(20);
	DHT11_DATA_OUT = 1;
	delay_us(30);
}


//dht11Ӧ��
//1����Ӧ��    0�����Ӧ��
u8 dht11_ack(void)
{
	DHT11_INPUT();

	delay_us(25);
	if(DHT11_DATA_IN == 0)
	{
		delay_us(50);
		if(DHT11_DATA_IN == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	
	else 
	{
		return 0;
	}
		
}


//1��ʾ��⵽  0û�м�⵽
u8 dht11_check(void)
{
	dht11_rst();
	return dht11_ack();
}

//��ȡһλ����
u8 read_bit()
{
	

	while(DHT11_DATA_IN);//�ȴ���Ϊ�͵�ƽ
	
	while(!DHT11_DATA_IN);//�ȴ���ߵ�ƽ

	delay_us(40);//�ȴ�40us
	
	if(DHT11_DATA_IN)
		return 1;
	else 
		return 0;

}



u8 read_byte(void)
{
	u8 i;
	u8 data = 0;
	
	for(i = 0; i < 8; i++)
	{
		data <<= 1;
		data |= read_bit();
	}
	return data;
}

//��DHT11�ж�ȡ����
//0����ɹ�   1 ����ʧ��
//temp���¶�    humi��ʪ��
u8 dht11_read_data(u8 * temp, u8 * humi)
{
	u8 buf[5];
	u8 i;
	dht11_rst();
	if(dht11_ack())
	{
		for(i = 0; i < 5; i++)
		{
			buf[i] = read_byte();
		}

		if(buf[0] + buf[1] + buf[2] + buf[3] == buf[4])
		{
			*humi=buf[0];
			*temp=buf[2];
			
			return 0;
		}
		else
			return 1;	
	}
	else
		return 2;
	
}




 
