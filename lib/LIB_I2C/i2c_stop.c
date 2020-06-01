#include "lib_i2c.h"

/**
 * 函数: i2c_stop()
 * 功能: 停止I2C (终止信号)
*/
void i2c_stop()
{
   SDA = 0; //SDA初始化为低电平“0”
   SCL = 1; //结束数据传送时，要求SCL为高电平“1”
   NOPS;
   SDA = 1; //SDA的上升沿被认为是结束信号
   NOPS;
   /* 停止后, 要求SCL=1, SDA=1, 总线空闲 */
}
