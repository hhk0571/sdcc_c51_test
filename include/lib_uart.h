#ifndef   __UART_H__
#define   __UART_H__

#include "STC89xx.h"     /*包含STC单片机头文件*/

#define CAT(a,b)  a##b

#ifdef DEBUG
// need to call UART_init() first before using TRACE/printf
#define TRACE  printf
#else
// #define TRACE  CAT(/,/)
#define TRACE
#endif

extern void UART_init();
extern void UART_send_byte(byte dat);
extern void UART_send_str(const char *buf);

/*
 * extern char putchar(char c);
 * 注: 要使用printf(), sdcc要求必须实现putchar函数.
 * 在使用printf()之前, 先调用UART_init()初始化串口.
 */

#endif
