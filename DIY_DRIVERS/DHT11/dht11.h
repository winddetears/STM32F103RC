#ifndef   DHT11_H__

#define   DHT11_H__

#include "sys.h"
#include "delay.h"


#define  DHT11_INPUT()    {GPIOC->CRL = GPIOC->CRL & 0xf0ffffff  | 8 << 24;}
#define  DHT11_OUTPUT()   {GPIOC->CRL = GPIOC->CRL & 0xf0ffffff  | 3 << 24;}

#define  DHT11_DATA_IN    PCin(6)
#define  DHT11_DATA_OUT   PCout(6)

void dht11_init(void);

//产生复位信号
void dht11_rst(void);


//dht11应答
//1代表应答    0代表非应答
u8 dht11_ack(void);

u8 dht11_check(void);

//读取一位数据
u8 read_bit(void);


u8 read_byte(void);


//从DHT11中读取数据
//0代表成功   1 代表失败
//temp：温度    humi：湿度
u8 dht11_read_data(u8 * temp, u8 * humi);



#endif  /* DHT11_H__ */







