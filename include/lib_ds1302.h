#ifndef __DS1302_LIB_H__
#define __DS1302_LIB_H__

#include "STC89xx.h" /*包含STC单片机头文件*/
#include "lib_hjc52.h"   /*包含HJ-C52开发板头文件*/

typedef struct _DayTime_t_{
   byte Second;
   byte Minute;
   byte Hour;
   byte Day;
   byte Month;
   byte Week;
   byte Year;
   char DateString[9];
   char TimeString[9];
}DayTime_t;   //定义的时间类型


#define ASCII(a)           ((a) + 0x30)
#define DEC_TO_BCD(n)      (((n)/10)*16 + (n)%10) //只适用于两位十进制数
#define R_REG(reg)         ((reg) + 1)
#define W_REG(reg)         ((reg))

#define DS1302_W_ADDR      0x80  //第一个写寄存器
#define DS1302_R_ADDR      0x81  //第一个读寄存器

/* Write-Registers */
#define DS1302_SECOND      0x80
#define DS1302_MINUTE      0x82
#define DS1302_HOUR        0x84
#define DS1302_WEEK        0x8A
#define DS1302_DAY         0x86
#define DS1302_MONTH       0x88
#define DS1302_YEAR        0x8C
#define DS1302_WP          0x8E
#define DS1302_CLK_BURST   0xBE
#define DS1302_RAM_BURST   0xFE
#define DS1302_RAM(X)      (0xC0+(X)*2)  //用于计算 DS1302_RAM 地址的宏
#define DS1302_RAM_MAX     30 //RAM[0] ~ RAM[30]

void delaynus(byte n);
void start_ds1302_io(void);
void stop_ds1302_io(void);
void write_byte_to_ds1302(byte dat);
byte read_byte_from_ds1302(void);
void DS1302_Write(byte reg, byte dat);
byte DS1302_Read(byte reg);
void DS1302_SetWP(__bit flag);
void DS1302_SetTime(DayTime_t *Time);
void DS1302_GetTime(DayTime_t *Time);
void DS1302_init(void);
void DateTimeToStr(DayTime_t *Time);
byte WeekDay(word year, byte month, byte day);
void DS1302_Reset_Clock(void); /* 重设初始时间 (慎用) */

/**
 * 设定时钟数据
*/

/********************************************************************************
void BurstWrite1302(byte *pWClock)   //往DS1302写入时钟数据(多字节方式)
{
    byte i;
    Write1302(0x8e,0x00);            // 控制命令,WP=0,写操作?
    DS1302_RST = 0;
    DS1302_CLK = 0;
    DS1302_RST = 1;
    DS1302InputByte(0xbe);           // 0xbe:时钟多字节写命令
    for (i = 8; i>0; i--)           //8Byte = 7Byte 时钟数据 + 1Byte 控制
    {
        DS1302InputByte(*pWClock);    // 写1Byte数据
        pWClock++;
    }
    DS1302_CLK = 1;
    DS1302_RST = 0;
}

void BurstRead1302(byte *pRClock)   //读取DS1302时钟数据(时钟多字节方式)
{
    byte i;
    DS1302_RST = 0;
    DS1302_CLK = 0;
    DS1302_RST = 1;
    DS1302InputByte(0xbf);                // 0xbf:时钟多字节读命令
    for (i=8; i>0; i--)
    {
       *pRClock = DS1302OutputByte();   // 读1Byte数据
       pRClock++;
    }
    DS1302_CLK = 1;
    DS1302_RST = 0;
}

void DS1302_TimeStop(__bit flag)           // 是否将时钟停止
{
   byte Data;
   Data=Read1302(DS1302_SECOND);
   DS1302_SetProtect(0);
   if(flag)
      Write1302(DS1302_SECOND, Data|0x80);
   else
      Write1302(DS1302_SECOND, Data&0x7F);
}
********************************************************************************/

#endif