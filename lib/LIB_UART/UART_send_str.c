#include "lib_uart.h"

/*
 * UART 发送字符串
*/
void UART_send_str(const char *buf)
{
   ES = 0; //关闭串口中断, 否则每发送一个字符, 会触发发送中断TI
   while (*buf != '\0') {
      SBUF = *buf++;
      while (!TI); //等待发送完毕, 发送完毕后, 硬件会将TI置1
      TI = 0;      //软件将TI清零
   }
   ES = 1; //发送完毕, 恢复串口中断
}
