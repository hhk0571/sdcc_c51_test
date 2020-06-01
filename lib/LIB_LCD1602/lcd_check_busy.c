#include "lib_lcd1602.h"

/*------------------------------------------------
              判忙函数
------------------------------------------------*/
__bit lcd_check_busy(void)
{
   DataPort = 0xFF;
   RS_CMD;
   RW_READ;
   EN = 0;
   NOP();
   EN = 1;

   return (__bit)(DataPort & 0x80);
}
