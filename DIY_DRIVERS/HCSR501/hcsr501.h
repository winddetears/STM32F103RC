#ifndef   HCSR501_H__

#define   HCSR501_H__

#include "sys.h"


#define  HCSR501_FLAG   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)


void hcsr501_init(void);
u8 hcsr501_check(void);






#endif

