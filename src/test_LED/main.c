// #include "at89x52.h"
#include "STC89xx.h"    /*包含STC单片机头文件*/
#include "lib_hjc52.h"      /*包含HJ-C52开发板头文件*/
#include "lib_delay.h"  /*包含网上收集的延时函数头文件*/
#include "lib_uart.h"

#include <stdio.h>

void main()
{
   unsigned char i;//0-255

   hjc52_init();
   // UART_init();

   while(1)
   {
      P1=0xff;
      for(i=0;i<8;i++)
      {
         P1<<=1;
         delay10ms();
      }

      P1=0x80; // 1000 0000
      delay10ms();
      for(i=0;i<7;i++)
      {
         P1= (P1>>1) | 0x80;
         delay10ms();
      }

      printf("Hello world! This is %d year\r\n", 2020);
   }
}

