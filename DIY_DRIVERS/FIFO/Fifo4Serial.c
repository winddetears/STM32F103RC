#include "Fifo4serial.h" 

/**********************************************
�������ܣ���������
���룺��
�������
��ע�������ṹ��
**********************************************/
Fifo4Serial USART2Send,USART2Recieve ;

/**********************************************
�������ܣ����г�ʼ��
���룺��
�������
**********************************************/
void QueueInit(Fifo4Serial *Q)
{
	Q->front = 0 ;
	Q->rear = 0 ;
	Q->bufferCount = 0 ;
}
/**********************************************
�������ܣ�����
���룺��
�������
��ע������ѭ������
**********************************************/
u8 QueueIn(Fifo4Serial *Q,u8 dat)
{
	if(((Q->rear) % QUEUE_BUFFER == Q->front) && (Q->bufferCount == QUEUE_BUFFER ))
		return QUEUE_FULL ;
	Q->base[Q->rear] = dat ;
	Q->rear = (Q->rear + 1) % QUEUE_BUFFER ;
	Q->bufferCount++ ;
	return(QUEUE_OK) ;
}
/**********************************************
�������ܣ�����
���룺��
�������
**********************************************/
u8 QueueOut(Fifo4Serial *Q,u8 *dat)
{
 	if((Q->front == Q->rear) && (Q->bufferCount == 0)) 
		return(QUEUE_EMPTY) ;
	else {
		*dat = Q->base[Q->front] ;
		Q->front = (Q->front + 1) % QUEUE_BUFFER ;
		Q->bufferCount-- ;
		return(QUEUE_OK) ;
	}
}

