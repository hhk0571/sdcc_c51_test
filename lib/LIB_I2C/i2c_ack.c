#include "lib_i2c.h"

/**
 * 函数: i2c_ack(__bit ack)
 * 功能: ack为1时发送应答信号ACK,
 *       ack为0时不发送ACK
*/
void i2c_ack(__bit ack)
{
    //SDA=0是应答; SDA=1是非应答
    SDA = ack ? 1 : 0;
    TRACE("\nack=%bu, SDA=%bu\n", (byte)ack, (byte)SDA);
    NOPS;
    SCL = 1;
    NOPS;
    SCL = 0;   //SCL为低电平时，SDA上数据才允许变
}
