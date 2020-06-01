#include "lib_lcd1602.h"

/*------------------------------------------------
              写入命令函数
------------------------------------------------*/
void lcd_write_cmd(byte cmd)
{
   while(lcd_check_busy()); //忙则等待
   RS_CMD;
   RW_WRITE;
   EN = 1;
   DataPort = cmd;
   NOP();
   EN = 0;
}
