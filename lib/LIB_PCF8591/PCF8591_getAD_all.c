#include "lib_PCF8591.h"


/*--------------------------------------------------------------------
函数全称：
函数功能：连续读入4路通道的A/D转换结果到指针指向的区域
注意事项：
提示说明：
输    入：
返    回：0 - 成功; 1 - 失败
--------------------------------------------------------------------*/
__bit PCF8591_getAD_all(byte mode, byte *dat)
{
   byte i = 0;
   byte ch_cnt = 0;
   byte ctrl_byte = mode | AUTO_INCR;

   switch (mode) {
      case AD_MODE0: ch_cnt = 4; break;
      case AD_MODE1: ch_cnt = 3; break;
      case AD_MODE2: ch_cnt = 3; break;
      case AD_MODE3: ch_cnt = 2; break;
   }

   i2c_start();
   i2c_sendbyte(PCF8591_ADDR);    //设备地址(W)
   CHECK_ACK;
   i2c_sendbyte(ctrl_byte);   //地址
   CHECK_ACK;

   i2c_start();
   i2c_sendbyte(PCF8591_ADDR | 0x1); //设备地址(R)
   CHECK_ACK;

   i2c_recvbyte(); //如果设了自动增量, 通道将自动设为最高可用通道号, 空读一下, 下次通道开始从0开始
   i2c_ack(1);

   while (i < ch_cnt) {
      *dat++ = i2c_recvbyte();  //读数据
      i2c_ack((__bit)(++i<ch_cnt));    //[1]~[n-1]应答; [n]非应答
   }
   i2c_stop();

   return 0;
}
