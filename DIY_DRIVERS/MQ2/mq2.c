#include "mq2.h"
#include "adc.h"

/*
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ��V1.0.0

*/


void mq2_init(void)
{
	adc_init();
}



//��ȡ��ȡ��adcֵ
u16 get_mq2_vaule(void)
{
	return get_adc_value();
}


//��ѹֵ
float mq2_voltage(void)
{
	float tmp;
	tmp = get_mq2_vaule() * 3.3 / 4096;
	return tmp;
}

