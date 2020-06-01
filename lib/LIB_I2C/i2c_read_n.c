#include "lib_i2c.h"


/**
 * 函数: i2c_read_n
 * 输入: byte DevAddr, byte DataAddr, byte *dat, byte n
 * 输出: 字节数据
 * 功能: 从指定I2C设备的某一地址读n个字节
 * 返回值: 0->成功  1->失败
*/
__bit i2c_read_n(byte DevAddr, byte DataAddr, byte *dat, byte n)
{
   byte i = 0;

   TRACE("\nDevAddr=0x%0bX, DataAddr=%0bu, size=%bu\n", DevAddr, DataAddr, n);
   i2c_start();
   i2c_sendbyte(DevAddr);    //设备地址(W)
   CHECK_ACK;
   i2c_sendbyte(DataAddr);   //地址
   CHECK_ACK;

   i2c_start();
   i2c_sendbyte(DevAddr | 0x1); //设备地址(R)
   CHECK_ACK;
   while (i < n) {
      *dat++ = i2c_recvbyte();  //读数据
      i2c_ack((__bit)(++i<n));    //[1]~[n-1]应答; [n]非应答
      TRACE("\ni=%bu, data=0x%0bX\n", i, *(dat-1));
   }
   i2c_stop();

   return 0;
}
