 /*********************************************************************
 *
 *                           delay.c
 *
 *********************************************************************
 * 描    述: 网上收集整理的延时函数，试用源码。
 * 开发平台: KEIL+HL-1/HJ-3G/HJ-C52开发板*/

#include "lib_delay.h"  /*包含网上收集的延时函数头文件*/

/*一些固定延时函数*/

/*1uS延时函数*/
/*FOSC=11.0592、12、22.1184MHZ时，适用*/
/*其他晶振频率时，要调整_nop_();语句的句数，NOP();语句的句数=FOSC-10*/
void delay1us()
{
   #if FOSC==11059200
      NOP();
   #elif FOSC==12000000
      NOP();NOP();
   #elif FOSC==22118400
      NOP();NOP();NOP();NOP();NOP();
      NOP();NOP();NOP();NOP();NOP();
      NOP();NOP();
   #endif
}

/*2uS延时函数*/
/*FOSC=11.0592、12、22.1184MHZ时，适用*/
/*其他晶振频率时，要调整_nop_();语句的句数，NOP();语句的句数=2*FOSC-10*/
void delay2us()
{
   #if FOSC==11059200
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();
   #elif FOSC==12000000
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();
   #elif FOSC==22118400
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();   NOP();
      NOP();   NOP();   NOP();   NOP();
   #endif
}


/*5uS延时函数*/
void delay5us()
{
   delay8((FOSC/1000000*5-18)/10);
}

/*10uS延时函数*/
void delay10us()
{
   delay8((FOSC/1000000*10-18)/10);
}


/*20uS延时函数*/
void delay20us()
{
   delay8((FOSC/1000000*20-18)/10);
}
/*50uS延时函数*/
void delay50us()
{
   delay8((FOSC/1000000*50-18)/10);
}
/*100uS延时函数*/
void delay100us()
{
   delay((0.1*FOSC/1000-24)/13);
}
/*200uS延时函数*/
void delay200us()
{
   delay((0.2*FOSC/1000-24)/13);
}
/*500uS延时函数*/
void delay500us()
{
   delay((0.5*FOSC/1000-24)/13);
}
/*1mS延时函数*/
void delay1ms()
{
   delay((1*FOSC/1000-24)/13);
}
/*2mS延时函数*/
void delay2ms()
{
   delay((2*FOSC/1000-24)/13);
}
/*5mS延时函数*/
void delay5ms()
{
   delay((5*FOSC/1000-24)/13);
}
/*10mS延时函数*/
void delay10ms()
{
   delay((10*FOSC/1000-24)/13);
}
/*20mS延时函数*/
void delay20ms()
{
   delayms(20);
}
/*50mS延时函数*/
void delay50ms()
{
   delayms(50);
}
/*100mS延时函数*/
void delay100ms()
{
   delayms(100);
}
/*200mS延时函数*/
void delay200ms()
{
   delayms(200);
}
/*500mS延时函数*/
void delay500ms()
{
   delays(0.5);
}
/*1S延时函数*/
void delay1s()
{
   delays(1);
}
/*2S延时函数*/
void delay2s()
{
   delays(2);
}
/*5S延时函数*/
void delay5s()
{
   delays(5);
}
/*10S延时函数*/
void delay10s()
{
   delays(10);
}

/*0.8us--116us延时函数(FOSC=22.1184M时)*/
/*1.5us--214us延时函数(FOSC=12M时)*/
/*1.6us--232us延时函数(FOSC=11.0592M时)*/
/*延时时间：(18+10t)/FOSC*/
/*最大延时：2568/FOSC*/
/*最小延时：18/FOSC*/
/*设要延时的时间为T(常量，单位为us),调用方式:delay8((FOSC/1000000*T-18)/10)*/
/*例如要延时的时间为100us,调用方式:delay8((FOSC/1000000*100-18)/10)*/
void delay8(unsigned char t)
{
   unsigned char i;
   for(i=t;i;i--);
}

/* 1.1us--38.5ms延时函数(FOSC=22.1184M时)                              */
/* 2us--70.9ms延时函数(FOSC=12M时)                                     */
/* 2.2us--77ms延时函数(FOSC=11.0592M时)                                */
/* 延时时间：(13t+24)/FOSC                                             */
/* 最大延时：851979/FOSC                                               */
/* 最小延时：24/FOSC                                                   */
/* 设要延时的时间为T(常量，单位为ms),调用方式:delay((T*FOSC/1000-24)/13) */
/* 例如要延时的时间为10ms,调用方式:delay((10*FOSC/1000-24)/13)          */
void delay(unsigned int t)
{
   unsigned int i;
   for(i=t;i;i--);
}



/*一个毫秒级可变延时函数*/
/*功  能：实现与参数直接对应的时间（单位为毫秒）的延时*/
/*参  数：范围1到255*/
/*返回值：无*/
void delayms(unsigned char t)
{
   unsigned char j;
   for(j=t;j;j--)
      delay1ms();/*1ms延时*/
}


/*一个秒级可变延时函数*/
/*功  能：实现与参数直接对应的时间（单位为秒）的延时*/
/*参  数：范围0.01到42949672*/
/*返回值：无*/
void delays(float t)
{
    unsigned int j;
   j=t*100;
   while(j--)
     {
      delay10ms();/*10ms延时*/
    }
}
