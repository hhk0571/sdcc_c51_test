#include "lib_lcd1602.h"


/*------------------------------------------------
              写入4位数字(0000 ~ 9999)函数
------------------------------------------------*/
void lcd_4_digit(word Data)
{
   byte digit[4+1];

   digit[0] = ASCII((Data % 10000) / 1000);         //千位
   digit[1] = ASCII((Data % 1000) / 100); //百位
   digit[2] = ASCII((Data % 100) / 10);   //十位
   digit[3] = ASCII(Data % 10);           //个位
   digit[4] = '\0';

   lcd_write_string(digit);
}
