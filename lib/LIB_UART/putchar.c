#include "lib_uart.h"

/*
 * UART 发送一字节
 * 注: 要使用printf(), sdcc要求必须实现putchar函数.
 * 在使用printf()之前, 先调用UART_init()初始化串口.
 */
char putchar(char c)
{
   ES = 0;      //关闭串口中断, 否则每发送一个字符, 会触发发送中断TI
   SBUF = c;
   while (!TI); //等待发送完毕, 发送完毕后, 硬件会将TI置1
   TI = 0;      //软件将TI清零
   ES = 1;      //发送完毕, 恢复串口中断

   return c;
}
