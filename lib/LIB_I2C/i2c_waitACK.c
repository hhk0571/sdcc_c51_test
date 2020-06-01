#include "lib_i2c.h"

/**
 * 函数: i2c_waitACK()
 * 功能: 返回为1时收到ACK
 *       返回为0时没收到ACK
*/
__bit i2c_waitACK()
{
   byte i = 0;

   SDA = 1;
   NOPS;
   SCL = 1;
   NOPS;
   while((SDA) && (i<255)) {
      i++;
   }

   if (SDA) {
      SCL = 0;
      i2c_stop();
      return 0;
   }
   else  {
      SCL = 0;
      return 1;
   }
}
