#ifndef __ESP8266_H__
#define	__ESP8266_H__

#include <reg52.h>
#include "include_type.h"
#include "interrupt.h"
#include "osp_global_str.h"
#include "Delay.h"
#include "string.h"

sbit EN = P0^0;

void ESP_Init(void);
BOOL ESP_send_commend(uint8_t * Temp, uint8_t * hrecv, uint16_t time);
void ESP_no_return_send(uint8_t * Temp, uint16_t time);
BOOL ESP_Link_com(void);
U8* ESP_recv_data(void);

#endif
