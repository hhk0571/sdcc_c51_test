#include "lib_ds1302.h"

void DS1302_SetWP(__bit flag)    //是否写保护
{
    if (flag)
        DS1302_Write(DS1302_WP, 0x80);
    else
        DS1302_Write(DS1302_WP, 0x00);
}
