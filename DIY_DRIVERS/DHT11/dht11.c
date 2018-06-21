#include "dht11.h"


/*
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ：V1.0.0
*/


//DHT11 --> PC6

//dht11初始化

void dht11_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//使能PA端口时钟
	
	GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_6;       //端口配置
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_Out_PP;                     	
	GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;                         
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
}



//产生复位信号
void dht11_rst(void)
{
	DHT11_OUTPUT();
	DHT11_DATA_OUT = 0;
	delay_ms(20);
	DHT11_DATA_OUT = 1;
	delay_us(30);
}


//dht11应答
//1代表应答    0代表非应答
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


//1表示检测到  0没有检测到
u8 dht11_check(void)
{
	dht11_rst();
	return dht11_ack();
}

//读取一位数据
u8 read_bit()
{
	

	while(DHT11_DATA_IN);//等待变为低电平
	
	while(!DHT11_DATA_IN);//等待变高电平

	delay_us(40);//等待40us
	
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

//从DHT11中读取数据
//0代表成功   1 代表失败
//temp：温度    humi：湿度
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




 
