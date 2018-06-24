#include "include.h"
/*
			自从厌倦于追寻，我已学会一觅即中；
		自从一股逆风袭来，我亦能抗御八面来风，驾舟而行！
		                                          ------WindDeTears
 *      Created on: 20180620
 *      @Author   : XJ <winddetears.@163.com>
 *		@id       : WindDeTears
 *      @version  ：V1.0.0
 
*                        ,%%%%%%%%,
*                      ,%%/\%%%%/\%%
*                     ,%%%\c''''J/%%%
*           %.        %%%%/ o  o \%%%
*           `%%.      %%%%       |%%%
*            `%%      `%%%%(__Y__)%%'
*            //        ;%%%%`\-/%%%'
*            ((      /   `%%%%%%%'
*             \\     .'           |
*              \\   /        \  | |
*               \\/          ) | |
*                \          /_ | |__
*                (____________))))))) 攻城狮
*/

u8 cmd;
u8 temp = 0;
u8 humi = 0;
u8 ret;
u16 data;
u8 send_data;
float adc_vaule;
float sq_check;

void SYSTEM_Congfig_Init(void);
 
int main(void)
{	
	u8 send[7] = {0}; 
	send[0] = 0xff;
	send[6] = 0xfe;
	SYSTEM_Congfig_Init();
	while(1)
	{
		dht11_read_data(&temp, &humi);
		send[1] = temp;
		send[2] = humi;
		adc_vaule = mq2_voltage();
		sq_check = (float)((adc_vaule * 10) / 33) + 0.03;
		data = (uint16_t)(sq_check * 1000);
		send[3] = (data&0xff00) >> 8 ;
		send[4] = data&0xff;	
		ret = hcsr501_check();
		send[5] = ret;
		delay_ms(500);
		
		Usart_SendArray(USART1, send, 7);

	}

}

 /* 外设初始化 */
void SYSTEM_Congfig_Init(void)
{
	delay_init();
	uart_init(9600);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	
	led_init();
	dht11_init();
	mq2_init();
	hcsr501_init();
	while(!dht11_check());
}	

void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		cmd = USART_ReceiveData(USART1);	//读取接收到的数据
		if(cmd == 'a')
		{
			led_on();
		}
		if(cmd == 'b')
		{
			led_off();
		}
	}
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}


/* ***********************唯一无法冷静的是决心 *******************************/
