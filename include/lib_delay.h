 /*********************************************************************
 *
 *                           delay.h
 *
 *********************************************************************
 * 描    述: 网上收集整理的延时函数头文件，试用源码。
 * 开发平台: KEIL+HL-1/HJ-3G/HJ-C52开发板
 ********************************************************************/

#ifndef   __LIB_DELAY_H__
#define   __LIB_DELAY_H__

#include "STC89xx.h"/*包含STC单片机头文件*/

void delay1us();
void delay2us();
void delay5us();
void delay10us();
void delay20us();
void delay50us();
void delay100us();
void delay200us();
void delay500us();
void delay1ms();
void delay2ms();
void delay5ms();
void delay10ms();
void delay20ms();
void delay50ms();
void delay100ms();
void delay200ms();
void delay500ms();
void delay1s();
void delay2s();
void delay5s();
void delay10s();


void delay8(unsigned char t);  /*1.6us--232us延时函数(fosc=11.0592M时)*/
void delay(unsigned int t);    /*2.2us--77ms延时函数(fosc=11.0592M时)*/
void delayms(unsigned char t); /*一个毫秒级可变延时函数*/
void delays(float t);          /*一个秒级可变延时函数*/


#endif