#include "lib_ds1302.h"

/**
 * 写入数据到DS1302
*/
void DS1302_Write(byte reg, byte dat)
{
   start_ds1302_io();
   write_byte_to_ds1302(reg);
   write_byte_to_ds1302(dat);
   stop_ds1302_io();
}