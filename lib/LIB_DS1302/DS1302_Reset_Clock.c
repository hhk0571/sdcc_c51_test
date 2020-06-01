#include "lib_ds1302.h"

/* 重设初始时间 (慎用) 2013-7-19 08:00:00 */
void DS1302_Reset_Clock(void)
{
    DayTime_t time = { 0, 0, 8, 19, 7, 5, 13 }; //秒分时日月周年
    DS1302_SetTime(&time);
}