#include "led.h"

/*
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ：V1.0.0

*/


//led1     ------    PB12
//led2     ------    PB13
//led3     ------    PB14

//led初始化

void led_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//使能PA端口时钟
	
	GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;  //端口配置
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_Out_PP;                         //推挽输出	
	GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;                         //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);               //输出高
}


void led_off(void)
{
	PBout(14) = 1;
	PBout(13) = 1;
	PBout(12) = 1;
}

void led_on(void)
{
	PBout(14) = 0;
	PBout(13) = 0;
	PBout(12) = 0;
}


//返回1  正确执行
//返回0  错误执行
u8 led_ctl(u8 led_cmd, u8 status)
{
	if(led_cmd == LED1)
	{
		if(status == ON)
		{
			PBout(12) = 0;
		}
		else if(status == OFF)
		{
			PBout(12) = 1;
		}
	}
	
	else if(led_cmd == LED2)
	{
		if(status == ON)
		{
			PBout(13) = 0;
		}
		else if(status == OFF)
		{
			PBout(13) = 1;
		}
	}
	
	else if(led_cmd == LED3)
	{
		if(status == ON)
		{
			PBout(14) = 0;
		}
		else if(status == OFF)
		{
			PBout(14) = 1;
		}
	}
	
	else
	{
		return 0;
	}
	
	return 1;
}

