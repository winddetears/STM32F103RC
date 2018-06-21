#ifndef   LED_H__

#define   LED_H__

#include "sys.h"

#define ON  1
#define OFF 0



#define LED1 101
#define LED2 102
#define LED3 103

void led_init(void);
void led_off(void);
void led_on(void);

u8 led_ctl(u8 led_cmd, u8 status);





#endif   /* LED_H__ */

