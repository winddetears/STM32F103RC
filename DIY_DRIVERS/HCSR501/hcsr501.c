#include "hcsr501.h"

/*
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ：V1.0.0
*/



//有人高电平  没人低电平

//PB9

void hcsr501_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
 	GPIO_Init(GPIOE, &GPIO_InitStructure);

}


/*
返回1 有人      返回0没人      其他值出错
*/
u8 hcsr501_check(void)
{
	if(HCSR501_FLAG == 1)
	{
		return 1;
	}
	else if(HCSR501_FLAG == 0)
	{
		return 0;
	}
	else
		return 2;
}
