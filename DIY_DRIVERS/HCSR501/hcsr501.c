#include "hcsr501.h"

/*
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ��V1.0.0
*/



//���˸ߵ�ƽ  û�˵͵�ƽ

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
����1 ����      ����0û��      ����ֵ����
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
