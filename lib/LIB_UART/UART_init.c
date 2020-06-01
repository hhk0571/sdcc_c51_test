#include "lib_uart.h"

void UART_init()
{
   TMOD |= 0x20; //设定T1定时器工作方式2
   TH1 = 0xfd;   //波特率9600时T1定时器初值 9600bps@11.0592MHz
   TL1 = 0xfd;   //波特率9600时T1定时器初值 9600bps@11.0592MHz
   TR1 = 1;      //启动T1定时器

#if 1 //Alternative 1
   SCON = 0x50;
#else //Alternative 2
   SM0 = 0;
   SM1 = 1; //设定串口工作方式1
   REN = 1; //允许串口接收
   /* 注意:REN=1不能放在前面, 否则单片机刚上电是SCON被清零(方式0),
      一旦执行REN置1后,串行口直接开始从RXD引脚接收数据, 无论有无发送数据
   */
#endif
   EA = 1; //开总中断
   ES = 1; //开串口中断
}
