#include "lib_ds1302.h"

void DateTimeToStr(DayTime_t *Time)
{
    Time->DateString[0] = ASCII(Time->Year / 10);
    Time->DateString[1] = ASCII(Time->Year % 10);
    Time->DateString[2] = '-';
    Time->DateString[3] = ASCII(Time->Month / 10);
    Time->DateString[4] = ASCII(Time->Month % 10);
    Time->DateString[5] = '-';
    Time->DateString[6] = ASCII(Time->Day / 10);
    Time->DateString[7] = ASCII(Time->Day % 10);
    Time->DateString[8] = '\0';

    Time->TimeString[0] = ASCII(Time->Hour / 10);
    Time->TimeString[1] = ASCII(Time->Hour % 10);
    Time->TimeString[2] = ':';
    Time->TimeString[3] = ASCII(Time->Minute / 10);
    Time->TimeString[4] = ASCII(Time->Minute % 10);
    Time->TimeString[5] = ':';
    Time->TimeString[6] = ASCII(Time->Second / 10);
    Time->TimeString[7] = ASCII(Time->Second % 10);
    Time->DateString[8] = '\0';
}
