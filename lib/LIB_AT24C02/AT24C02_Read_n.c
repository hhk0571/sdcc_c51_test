#include "lib_AT24C02.h"


/*--------------------------------------------------------------------
函数名称：AT24C02读出N个数据
函数功能：数据由指针pRdDat返回
注意事项：
提示说明：
输    入：
返    回：0 - 成功; 1 - 失败
--------------------------------------------------------------------*/
__bit AT24C02_Read_n(byte DataAddr, byte *pRdDat, byte cnt)
{
   return i2c_read_n(AT24C02_ADDR, DataAddr, pRdDat, cnt);
}

