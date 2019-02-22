#ifndef __TEMPERTURE_H__
#define	__TEMPERTURE_H__

#include <reg52.h>
#include "include_type.h"
#include <intrins.h>

sbit QD = P2^0;

void Temperture_read(U8* recv_buf);

#endif