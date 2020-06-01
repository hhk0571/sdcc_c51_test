#ifndef __LCD1602_LIB_H__
#define __LCD1602_LIB_H__

#include "STC89xx.h" /*包含STC单片机头文件*/
#include "lib_hjc52.h"   /*包含HJ-C52开发板头文件*/

#define RS_CMD      RS=0
#define RS_DAT      RS=1

#define RW_WRITE    RW=0
#define RW_READ     RW=1

#define DataPort    P0
#define ASCII(a)    ((a) + 0x30)

#define LCD_SET_MODE       0x38

//LCD Display, Cursor, Blinking Setting
#define LCD_CONFIG         0x08
#define LCD_DISPLAY_ON     0x04
#define LCD_DISPLAY_OFF    0x00
#define LCD_CURSOR_ON      0x02
#define LCD_CURSOR_OFF     0x00
#define LCD_BLINK_ON       0x01
#define LCD_BLINK_OFF      0x00

//LCD Operation Commands
#define LCD_CLR            0x01
#define LCD_CR             0x02
#define LCD_CUR_LEFT       0x10
#define LCD_CUR_RIGHT      0x14
#define LCD_SCR_LEFT       0x18
#define LCD_SCR_RIGHT      0x1C

void lcd_write_cmd(byte cmd);
void lcd_write_dat(byte Data);
__bit lcd_check_busy(void);
void lcd_clear(void);
void lcd_pos(byte x, byte y);
void lcd_write_string(const byte *s);
void lcd_pos_string(byte x, byte y, const byte *s);
void lcd_pos_char(byte x, byte y, byte Data);
void lcd_2_digit(byte Data);
void lcd_3_digit(word Data);
void lcd_4_digit(word Data);
void lcd_float(float Data, byte precise);
void lcd_init(void);

void DelayMs(uint xms);

#endif

