#ifndef __PCF8591_H__
#define __PCF8591_H__

#include "STC89xx.h" /*包含STC单片机头文件*/
#include "lib_hjc52.h"   /*包含HJ-C52开发板头文件*/
#include "lib_i2c.h"

#define PCF8591_ADDR  0x90    //定义器件地址 A0 A1 A2 = 0 0 0

#define AD_MODE0  0x00  //Channel 0 = AIN0;
                        //Channel 1 = AIN1;
                        //Channel 2 = AIN2;
                        //Channel 3 = AIN3;

#define AD_MODE1  0x10  //Channel 0 = AIN3-AIN0;
                        //Channel 1 = AIN3-AIN1
                        //Channel 2 = AIN3-AIN2;

#define AD_MODE2  0x20  //Channel 0 = AIN0;
                        //Channel 1 = AIN1;
                        //Channel 2 = AIN3-AIN2;

#define AD_MODE3  0x30  //Channel 0 = AIN1-AIN0;
                        //Channel 1 = AIN3-AIN2;

#define CHNL0  0x0      //Using Channel 0
#define CHNL1  0x1      //Using Channel 1
#define CHNL2  0x2      //Using Channel 2
#define CHNL3  0x3      //Using Channel 3

#define AUTO_INCR 0x04  //Auto-Increment Flag
#define DA_EN     0x40  //Analogue Output Enable


__bit PCF8591_getAD(byte mode, byte channel, byte *pRdDat);
__bit PCF8591_getAD_all(byte mode, byte *dat);
__bit PCF8591_setDA(byte val);

#endif
