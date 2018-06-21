#ifndef _FIFO4SERIAL_H_
#define _FIFO4SERIAL_H_

#include "sys.h"

#define QUEUE_EMPTY 0
#define QUEUE_FULL 1
#define QUEUE_OK 2
#define QUEUE_BUFFER 128

typedef struct {
	u8 base[QUEUE_BUFFER] ;
	unsigned int bufferCount ;
	unsigned int front ;
	unsigned int rear ;
} Fifo4Serial ;

 void QueueInit(Fifo4Serial *Q);
 u8 QueueIn(Fifo4Serial *Q,u8 dat);
 u8 QueueOut(Fifo4Serial *Q,u8 *dat);

#endif
