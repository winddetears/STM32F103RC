#ifndef   DHT11_H__

#define   DHT11_H__

#include "sys.h"
#include "delay.h"


#define  DHT11_INPUT()    {GPIOC->CRL = GPIOC->CRL & 0xf0ffffff  | 8 << 24;}
#define  DHT11_OUTPUT()   {GPIOC->CRL = GPIOC->CRL & 0xf0ffffff  | 3 << 24;}

#define  DHT11_DATA_IN    PCin(6)
#define  DHT11_DATA_OUT   PCout(6)

void dht11_init(void);

//������λ�ź�
void dht11_rst(void);


//dht11Ӧ��
//1����Ӧ��    0�����Ӧ��
u8 dht11_ack(void);

u8 dht11_check(void);

//��ȡһλ����
u8 read_bit(void);


u8 read_byte(void);


//��DHT11�ж�ȡ����
//0����ɹ�   1 ����ʧ��
//temp���¶�    humi��ʪ��
u8 dht11_read_data(u8 * temp, u8 * humi);



#endif  /* DHT11_H__ */







