#include "lib_i2c.h"

/**
 * 函数: i2c_write
 * 输入: byte DevAddr, byte DataAddr, byte dat
 * 功能: 向指定I2C设备的某一地址写一个字节
 * 返回值: 0->成功  1->失败
*/
__bit i2c_write(byte DevAddr, byte DataAddr, byte dat)
{
   i2c_start();
   i2c_sendbyte(DevAddr);
   CHECK_ACK;
   i2c_sendbyte(DataAddr);
   CHECK_ACK;
   i2c_sendbyte(dat);
   CHECK_ACK;
   i2c_stop();
   return 0;
}
