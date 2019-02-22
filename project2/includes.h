#ifndef __INCLUDES_H__
#define	__INCLUDES_H__

#include <reg52.h>
#include "interrupt.h"
#include "include_type.h"
#include "ESP8266.h"
#include "Delay.h"
#include "temperture.h"

sbit LED1=P1^0;
sbit LED2=P1^1;
sbit LED3=P1^2;
sbit LED4=P1^3;
sbit LED5=P1^4;
sbit LED6=P1^5;
sbit LED7=P1^6;
sbit LED8=P1^7;

sbit ZD_PIN = P0^0;
sbit WS_PIN = P0^1;

#endif
