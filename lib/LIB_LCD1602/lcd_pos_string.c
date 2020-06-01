#include "lib_lcd1602.h"


/*------------------------------------------------
              写入字符串函数
x 横坐标(那个位置): 有效值 0 - 39
y 纵坐标(第几行)  : 有效值 0 - 1
------------------------------------------------*/
void lcd_pos_string(byte x, byte y, const byte *s)
{
   lcd_pos (x, y);
   lcd_write_string(s);
}
