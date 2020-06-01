#include "lib_lcd1602.h"

/*------------------------------------------------
              初始化函数
------------------------------------------------*/
void lcd_init(void)
{
   EN = 0;
   lcd_write_cmd(LCD_SET_MODE); /*显示模式设置: 16×2 显示，5×7 点阵，8 位数据接口*/
   DelayMs(5);
   lcd_write_cmd(LCD_SET_MODE);
   DelayMs(5);
   lcd_write_cmd(LCD_SET_MODE);
   DelayMs(5);
   lcd_write_cmd(LCD_SET_MODE);

   lcd_write_cmd (LCD_CONFIG | LCD_DISPLAY_ON );
   lcd_write_cmd(0x06);    /*显示光标移动设置*/
   lcd_write_cmd(LCD_CLR); /*显示清屏*/
}
