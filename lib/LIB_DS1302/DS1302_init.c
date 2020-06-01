#include "lib_ds1302.h"

void DS1302_init(void)
{
    byte Second = DS1302_Read(DS1302_SECOND);

    if (Second & 0x80) {
        DS1302_Write(DS1302_SECOND, 0);
    }
}