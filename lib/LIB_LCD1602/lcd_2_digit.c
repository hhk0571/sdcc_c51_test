#include "lib_lcd1602.h"


/*------------------------------------------------
              写入2位数字(00 ~ 99)函数
------------------------------------------------*/
void lcd_2_digit(byte Data)
{
   byte digit[2+1];

   digit[0] = ASCII(Data / 10); //十位
   digit[1] = ASCII(Data % 10); //个位
   digit[2] = '\0';

   lcd_write_string(digit);
}
