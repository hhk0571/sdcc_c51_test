#include "STC89xx.h"     /*包含STC单片机头文件*/
#include "lib_hjc52.h"       /*包含HJ-C52开发板头文件*/
#include "lib_lcd1602.h"
#include "lib_ds1302.h"

const char * __code Week[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
DayTime_t init_time={00,07,22,30,5,6,20};//秒分时日月周年

void DelayMs(uint xms)
{
    uint i, j;
    for (i = xms; i > 0; i--)
        for (j = 110; j > 0; j--);
}

/*****************************************************
函数功能：主函数
***************************************************/
void main(void)
{
   DayTime_t time;

   hjc52_init();
   lcd_init();
   DS1302_init();

#if 0
   DS1302_SetTime(&init_time); // 只需设置一次即可
#endif

   lcd_clear();//清屏

/*
    0123456789012345
   |----------------|
   | 2013-07-18 THU |
   |   23:27:50     |
   |----------------|
*/
   lcd_pos_string(1,0,"    -  -");
   lcd_pos_string(3,1,"  :  :");


   while(1) {
      DS1302_GetTime(&time);   //秒分时日月周年
      lcd_pos(1, 0);
      lcd_4_digit(time.Year+2000);
      lcd_pos(6, 0);
      lcd_2_digit(time.Month);
      lcd_pos(9, 0);
      lcd_2_digit(time.Day);
      lcd_pos_string(12, 0, Week[time.Week%7]);

      lcd_pos(3, 1);
      lcd_2_digit(time.Hour);
      lcd_pos(6, 1);
      lcd_2_digit(time.Minute);
      lcd_pos(9, 1);
      lcd_2_digit(time.Second);

      DelayMs(800); //延时一秒(大概)
   }
}

