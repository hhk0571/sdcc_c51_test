#include "lib_i2c.h"

/**
 * 函数: i2c_recvbyte( )
 * 功能: 从总线上接收1字节数据
*/
byte i2c_recvbyte()
{
   byte tmp=0, i;

   SDA = 1; // 释放SDA数据总线, 以接收字节位
   for (i=0; i<8; i++)
   {
      SCL = 1;
      NOPS;
      tmp = (tmp<<1)|SDA;
      SCL = 0;
      NOPS;
   }

   return tmp;
}
