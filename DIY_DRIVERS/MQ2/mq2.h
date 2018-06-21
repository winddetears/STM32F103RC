#ifndef   MQ2_H__

#define   MQ2_H__

#include "sys.h"


void mq2_init(void);




//获取读取的adc值
u16 get_mq2_vaule(void);



//电压值
float mq2_voltage(void);














#endif  /* MQ2_H__ */

