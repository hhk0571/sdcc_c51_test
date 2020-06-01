#include "lib_PCF8591.h"


/*--------------------------------------------------------------------
函数全称：
函数功能：读入给定模式(byte mode)指定通道(byte channel)的A/D转换结果到指针(byte *pRdDat)
注意事项：
提示说明：
输    入：
返    回：0 - 成功; 1 - 失败
--------------------------------------------------------------------*/
__bit PCF8591_getAD(byte mode, byte channel, byte *pRdDat)
{
   return i2c_read(PCF8591_ADDR, mode|channel, pRdDat);
}
