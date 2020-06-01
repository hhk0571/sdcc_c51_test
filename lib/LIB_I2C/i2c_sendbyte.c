#include "lib_i2c.h"

/**
 * 函数: i2c_sendbyte(byte dat)
 * 功能: 将输入的一字节数据dat发送
*/
void i2c_sendbyte(byte dat)
{
    byte i;

    for(i=0; i<8; i++)
    {
        SDA = (__bit)(dat & 0x80);
        NOPS;
        SCL = 1;
        dat <<= 1;
        NOPS;
        SCL = 0;
    }
}
