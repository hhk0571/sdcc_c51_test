#include "STC89xx.h"     /*包含STC单片机头文件*/
#include "lib_hjc52.h"   /*包含HJ-C52开发板头文件*/
#include "lib_uart.h"
#include "lib_ds1302.h"
#include <stdio.h>

const char * __code week[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

DayTime_t time={30,17,0,19,7,5,13};//秒分时日月周年

void delay(word n)
{
   while (n--) NOP();
}


main()
{
   hjc52_init();
   UART_init(); //若想调用printf向串口打印字符串，需要先调用此函数
   DS1302_init();

#if 0
   DS1302_SetTime(&time); // 只需设置一次即可
#endif
   while(1)
   {

      DS1302_GetTime(&time);   //秒分时日月周年
      // DateTimeToStr(&time);
      // UART_send_str(time.DateString);
      // UART_send_byte(' ');
      // UART_send_byte(WeekDay(time.Year+2000, time.Month, time.Day) + '0');
      // UART_send_byte(' ');
      // UART_send_str(time.TimeString);
      // UART_send_byte('\r');
      // UART_send_byte('\n');
      printf("%04d-%02d-%02d %02d:%02d:%02d %s\r\n",
         time.Year+2000, time.Month, time.Day,
         time.Hour, time.Minute, time.Second, week[time.Week % 7]
      );

      delay(15000);
   }
}

