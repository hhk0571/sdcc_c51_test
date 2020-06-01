#include "lib_ds1302.h"



void DS1302_GetTime(DayTime_t *Time)
{
   byte ReadValue;

   ReadValue = DS1302_Read(DS1302_SECOND);
   Time->Second = ((ReadValue & 0x70) >> 4) * 10 + (ReadValue & 0x0F); // BCD -> DEC
   ReadValue = DS1302_Read(DS1302_MINUTE);
   Time->Minute = ((ReadValue & 0x70) >> 4) * 10 + (ReadValue & 0x0F);
   ReadValue = DS1302_Read(DS1302_HOUR);
   Time->Hour = ((ReadValue & 0x70) >> 4) * 10 + (ReadValue & 0x0F);
   ReadValue = DS1302_Read(DS1302_DAY);
   Time->Day = ((ReadValue & 0x70) >> 4) * 10 + (ReadValue & 0x0F);
   ReadValue = DS1302_Read(DS1302_WEEK);
   Time->Week = ((ReadValue & 0x70) >> 4) * 10 + (ReadValue & 0x0F);
   ReadValue = DS1302_Read(DS1302_MONTH);
   Time->Month = ((ReadValue & 0x70) >> 4) * 10 + (ReadValue & 0x0F);
   ReadValue = DS1302_Read(DS1302_YEAR);
   Time->Year = ((ReadValue & 0xF0) >> 4) * 10 + (ReadValue & 0x0F);
}
