#include "lib_i2c.h"

/**
 * 函数: i2c_init()
 * 功能: I2C 初始化
*/
void i2c_init()
{
   SCL = 1;
   NOPS;
   SDA = 1;
   NOPS;
}
