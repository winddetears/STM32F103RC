#include "include.h"
/*
			�Դ������׷Ѱ������ѧ��һ�ټ��У�
		�Դ�һ�����Ϯ���������ܿ����������磬���۶��У�
		                                          ------WindDeTears
 *      Created on: 20180620
 *      @Author   : XJ
 *		@id       : WindDeTears
 *      @version  ��V1.0.0
 
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
*                (____________))))))) ����ʨ
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
	SYSTEM_Congfig_Init();
	while(1)
	{
		dht11_read_data(&temp, &humi);
		
		adc_vaule = mq2_voltage();
		sq_check = (float)((adc_vaule * 10) / 33) + 0.03;
		data = (uint16_t)(sq_check * 1000);

		
		ret = hcsr501_check();
		delay_ms(500);
		
		switch(cmd)
		{
			case 'a':led_on();cmd = 0;break;
			case 'b':led_off();cmd = 0;break;
			case TEMP_FLAG:USART_SendByte(USART1,temp);cmd = 0; break;
			case HUMI_FLAG:USART_SendByte(USART1,humi);cmd = 0; break;
			case SQ_FLAG:USART_SendHalfWord(USART1,get_adc_value());cmd = 0; break;
			case HCSR_FLAG:USART_SendData(USART1,ret);cmd = 0; break;
			default : break;
		}

	}

}

 /* �����ʼ�� */
void SYSTEM_Congfig_Init(void)
{
	delay_init();
	uart_init(9600);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	
	led_init();
	dht11_init();
	mq2_init();
	hcsr501_init();
	while(!dht11_check());
}	

void USART1_IRQHandler(void)                	//����1�жϷ������
{
	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		cmd = USART_ReceiveData(USART1);	//��ȡ���յ�������
	}
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}


/* ***********************Ψһ�޷��侲���Ǿ��� *******************************/
