#include "lib_ds1302.h"

void DS1302_SetTime(DayTime_t *Time)
{
   DS1302_SetWP(0);

   DS1302_Write(DS1302_SECOND, DEC_TO_BCD(Time->Second));
   DS1302_Write(DS1302_MINUTE, DEC_TO_BCD(Time->Minute));
   DS1302_Write(DS1302_HOUR,   DEC_TO_BCD(Time->Hour));
   DS1302_Write(DS1302_DAY,    DEC_TO_BCD(Time->Day));
   DS1302_Write(DS1302_MONTH,  DEC_TO_BCD(Time->Month));
   DS1302_Write(DS1302_WEEK,   DEC_TO_BCD(Time->Week));
   DS1302_Write(DS1302_YEAR,   DEC_TO_BCD(Time->Year));

   DS1302_SetWP(1);
}