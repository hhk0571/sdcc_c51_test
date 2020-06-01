 /*********************************************************************
 *
 *                          lib_hjc52.h
 *
 *********************************************************************
 * 文件名: lib_hjc52.h
 * 描  述: HL-1/HJ-3G/HJ-C52开发板头文件
 ********************************************************************/

#ifndef __HJC52_H__
#define __HJC52_H__

/*变量类型标识的宏定义,通常做法*/
#define uchar unsigned char // 8   0-255
#define uint unsigned int   // 16  0-65535

/* Interrupt Number */
#define INT_ID_EXT0     0  /* EXTERNAL INT 0         */
#define INT_ID_T0       1  /* TIMER/COUNTER 0        */
#define INT_ID_EXT1     2  /* EXTERNAL INT 1         */
#define INT_ID_T1       3  /* TIMER/COUNTER 1        */
#define INT_ID_SERIAL   4  /* SERIAL PORT            */
#define INT_ID_T2       5  /* TIMER/COUNTER 2 (8052) */

/* HL-1/HJ-3G/HJ-C52HJ-C52 引脚定义 */
SBIT(L0, _P1, 0); //LED0引脚
SBIT(L1, _P1, 1);
SBIT(L2, _P1, 2);
SBIT(L3, _P1, 3);
SBIT(L4, _P1, 4);
SBIT(L5, _P1, 5);
SBIT(L6, _P1, 6);
SBIT(L7, _P1, 7);

SBIT(RS, _P1, 0);  //RS为寄存器选择，1=数据寄存器、0=指令寄存器。
SBIT(RW, _P1, 1);  //RW为读写信号线，1=读操作，0=写操作。
                   //当RS=RW=0可以写入指令或者显示地址，
                   //当RS=0，RW=1可以读忙信号，
                   //当RS=1，RW=0可以写入数据。

SBIT(SDI, _P1, 5);  //DS1302
SBIT(SDO, _P1, 6);  //DS1302
SBIT(SCK, _P1, 7);  //DS1302

SBIT(SCL, _P1, 7);  //I2C  时钟
SBIT(SDA, _P1, 2);  //I2C  数据

SBIT(EN , _P2, 5);  //当EN端由高电平跳变成低电平时，液晶模块执行命令。
SBIT(CS , _P2, 6);
SBIT(RST, _P2, 7);  //DS1302时钟
SBIT(RX , _P3, 0);
SBIT(TX , _P3, 1);
SBIT(IR , _P3, 2);
SBIT(B20, _P2, 4);
SBIT(FM , _P2, 3);

SBIT(DU, _P2, 0);    //数码管段选
SBIT(WE, _P2, 1);    //数码管位选

SBIT(CS88, _P2, 2);  //8X8点阵使能

/*为方便使用，部分管脚的多重定义*/

#define CLK SW0
#define DAT SW1


//系统初始化函数
void hjc52_init(void); /*HL-1/HJ-3G/HJ-C52主板初始化*/


#endif