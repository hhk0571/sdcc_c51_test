#include "lib_ds1302.h"


/*****************************************************
函数功能：DS1302 I/O传输开始
***************************************************/
void start_ds1302_io(void)
{
   RST = 0;
   SCK = 0;
   RST = 1;
   delaynus(2);
}