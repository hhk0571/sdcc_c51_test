#include "lib_lcd1602.h"

void DelayMs(uint xms)
{
   uint i,j;
   for(i=xms;i>0;i--)
       for(j=110;j>0;j--);
}

