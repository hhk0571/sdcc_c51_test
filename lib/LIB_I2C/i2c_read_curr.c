#include "lib_i2c.h"

/**
 * 函数: i2c_read_curr
 * 输入: byte DevAddr
 * 输出: 字节数据
 * 功能: 从指定I2C设备的当前地址读一个字节
 * 返回值: 0->成功  1->失败
*/
__bit i2c_read_curr(byte DevAddr, byte *dat)
{
   i2c_start();
   i2c_sendbyte(DevAddr | 0x1); //设备地址(R)
   CHECK_ACK;
   *dat = i2c_recvbyte();  //读数据
   i2c_ack(0);             //因为只读一字节数据，不发送ACK信号
   i2c_stop();

   return 0;
}
