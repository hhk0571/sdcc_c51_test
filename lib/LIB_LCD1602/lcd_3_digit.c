#include "lib_lcd1602.h"


/*------------------------------------------------
              写入3位数字(000 ~ 999)函数
------------------------------------------------*/
void lcd_3_digit(word Data)
{
   byte digit[3+1];

   digit[0] = ASCII((Data % 1000) / 100); //百位
   digit[1] = ASCII((Data % 100) / 10);   //十位
   digit[2] = ASCII(Data % 10);           //个位
   digit[3] = '\0';

   lcd_write_string(digit);
}
