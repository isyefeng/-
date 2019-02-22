#ifndef __INTERRUPT_H_
#define	__INTERRUPT_H_

#include <reg52.h>
#include "include_type.h"

extern uint8_t recv_buf[40];
extern uint8_t m_index;

void EXTI_Init(void);
void Send_types(U8* Temp);
void sentTemp(U8 Temp);


#endif
