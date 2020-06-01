#include "lib_i2c.h"


/**
 * 函数: i2c_start()
 * 功能: 启动I2C (起始信号)
*/
void i2c_start()
{
   SDA = 1; //SDA初始化为高电平“1”
   SCL = 1; //开始数据传送时，要求SCL为高电平“1”
   NOPS;
   SDA = 0; //SDA的下降沿被认为是开始信号
   NOPS;
   SCL = 0; //SCL为低电平时，SDA上数据才允许变
}
