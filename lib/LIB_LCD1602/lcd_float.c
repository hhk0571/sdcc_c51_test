#include "lib_lcd1602.h"

/*------------------------------------------------
写入小于100, 最多三位小数点的浮点数 (0.000 ~ 99.999)
precise: 要显示几位小数 (1 - 3)
------------------------------------------------*/
void lcd_float(float Data, byte precise)
{
   byte  digit[5];
   byte  i;
   dword temp = Data * 1000;  //保留三位小数点

   if ( precise == 0)
      precise = 1;
   else if ( precise > 3 )
      precise = 3;

   digit[0]= temp/10000;         //十位
   digit[1]= (temp%10000)/1000;  //个位
   digit[2]= (temp%1000)/100;    //十分位
   digit[3]= (temp%100)/10;      //百分位
   digit[4]= temp%10;            //千分位

   if (digit[0]) {
      lcd_write_dat (ASCII(digit[0]));//十位
   }
   lcd_write_dat (ASCII(digit[1]));   //个位
   lcd_write_dat ('.');               //小数点

   for (i=0; i<precise; i++) {
      lcd_write_dat (ASCII(digit[i+2])); //小数点之十,百,千分位
   }
}

