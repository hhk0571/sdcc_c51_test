/*********************************************************************
AT24C02 读写函数
*********************************************************************/
#ifndef  __AT24C02_LIB_H__
#define  __AT24C02_LIB_H__

#include "STC89xx.h"     /*包含STC单片机头文件*/
#include "lib_i2c.h"

#define AT24C02_ADDR    0xA0 //器件地址：A0 A1 A2 = 0 0 0

__bit AT24C02_Write(byte DataAddr, byte WdDat);
__bit AT24C02_Read(byte DataAddr, byte *pRdDat);
__bit AT24C02_Read_n(byte DataAddr, byte *pRdDat, byte cnt);

#endif

