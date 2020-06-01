#ifndef   __LIB_I2C_H__
#define   __LIB_I2C_H__

#include "STC89xx.h" /*STC单片机头文件*/
#include "lib_hjc52.h"   /*HJ-C52开发板头文件*/
#include "lib_uart.h"

#define NOPS       do {NOP();NOP();NOP();NOP();NOP();} while(0) //定义空指令
#define CHECK_ACK  do {if (!i2c_waitACK()) return 1;} while(0)

void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_ack(__bit ack);
__bit i2c_waitACK();
void i2c_sendbyte(byte dat);
byte i2c_recvbyte();
__bit i2c_write(byte DevAddr, byte DataAddr, byte dat);
__bit i2c_read(byte DevAddr, byte DataAddr, byte *dat);
__bit i2c_read_n(byte DevAddr, byte DataAddr, byte *dat, byte n);
__bit i2c_read_curr(byte DevAddr, byte *dat);

#endif
