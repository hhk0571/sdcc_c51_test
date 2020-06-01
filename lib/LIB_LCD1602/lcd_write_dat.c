#include "lib_lcd1602.h"

/*------------------------------------------------
              写入数据函数
------------------------------------------------*/
void lcd_write_dat(byte Data)
{
   while(lcd_check_busy()); //忙则等待
   RS_DAT;
   RW_WRITE;
   EN = 1;
   DataPort = Data;
   NOP();
   EN = 0;
}
