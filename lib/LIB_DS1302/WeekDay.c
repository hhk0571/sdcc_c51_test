#include "lib_ds1302.h"

#define BASE_YEAR    1901
#define BASE_WDAY    2  //Sun=0 or 7, Mon=1,Tue=2, ..., Sat=6
// 若以1901年为起始年, 该年元旦是星期二, 1+x=2, 所以x是1
// 若以2000年为起始年, 该年元旦是星期六, 1+x=6, 所以x是5
// 若以2006年为起始年, 该年元旦是星期日, 1+x=0 或者 1+x =7, 所以x是-1或6
#define COMPENSATION (BASE_WDAY - 1)

#define IS_LEAP_YEAR(Y) ((((Y) % 4 == 0) && ((Y) % 100 != 0)) || ((Y) % 400 == 0))

/*
函数名: byte WeekDay(word year, byte month, byte day)
功能  : 计算某指定日期是星期几. 适用范围: 1901年1月1日至2099年12月31日
形参  : year 某年; month 某月; day 某日
返回值: Sun=0, Mon=1, Tue=2, ..., Sat=6
*/
byte WeekDay(word year, byte month, byte day)
{
    word i, count=0;
    word MonthAdd[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
#if 0
    byte days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    for(i = 1;i < month;i++)
       count = count + days[i];
#else
    count = MonthAdd[month-1];
#endif
    count = count + day;
    if( IS_LEAP_YEAR(year) && month >= 3)
       count += 1;
    count = count + (year - BASE_YEAR) * 365;
    for (i = BASE_YEAR; i < year; i++) {
        if (IS_LEAP_YEAR(i))
            count++;
    }

    return ((count + COMPENSATION) % 7);
}

