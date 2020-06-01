#include "lib_ds1302.h"


/**
 * 读出DS1302数据
*/
byte DS1302_Read(byte reg)
{
    byte temp = 0;

    start_ds1302_io();
    write_byte_to_ds1302(R_REG(reg));
    temp = read_byte_from_ds1302();
    stop_ds1302_io();

    return (temp);
}
