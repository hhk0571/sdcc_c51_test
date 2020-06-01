#include "STC89xx.h"    /*包含STC单片机头文件*/
#include "lib_hjc52.h"   /*包含HJ-C52开发板头文件*/

#define INIT_VALUE 99999999
// #define INIT_VALUE 500

/* 共阴数码管数字编码 */
const byte __code leddata[]={
/*index:  0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22 */
/*char: "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "H", "L", "n", "u", "P", "o", "-" */
       0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x76,0x38,0x37,0x3E,0x73,0x5C,0x40
};

byte t0;
dword count = INIT_VALUE;
void delayms(uint);

void init_timer0()
{
    TMOD |= 0x1; //使用模式一(16位定时器),使用"|"符号可以在使用多个定时器时不受影响
    TH0 = TIMER_50MS_INIT_VALUE / 256;
    TL0 = TIMER_50MS_INIT_VALUE % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void timer0() __interrupt INT_ID_T0
{
    TH0 = TIMER_50MS_INIT_VALUE / 256;
    TL0 = TIMER_50MS_INIT_VALUE % 256;
    if (++t0 == 2) { // 100ms
        t0 = 0;
        if (count-- == 0) {
            count = INIT_VALUE;
        }
    }
}

void display_one_digit(byte digit, byte wei)
{
   P0 = 0; /* 清空数据，防止有交替重影 */
   DU = 1;
   DU = 0;

   P0 = ~(1<<(8-wei)); /* 最右边的数码管(对应数字的个位)选接在P0.7口 */
   WE = 1;
   WE = 0;

   P0 = leddata[digit]; /* 取0-9,A-F的编码*/
   DU = 1;
   DU = 0;
}

/* 数码管显示十进制数: 0~99999999 */
void display_dec(dword n)
{
   dword q = 0, r = 0; //Q表示商, R表示余数
   dword temp = n;
   byte  i=1; // 位数 [1~8]
   do {
      q = temp/10;
      r = temp%10;
      display_one_digit(r,i);
      delayms(1);
      i++;
      temp = q;
   } while (temp>0 && i<=8);
}

/* 数码管显示十六进制数: 0~FFFFFFFF */
void display_hex(dword n)
{
   dword temp = n;
   byte  digit =0;
   byte  i=1; // 位数 [1~8]
   do {
      digit = temp & 0xF;
      display_one_digit(digit,i);
      delayms(1);
      temp >>= 4;
      i++;
   } while (temp>0 && i<=8);
}

void main()
{
   hjc52_init();
   init_timer0();
   while(1)
   {
      // display_hex (count);
      display_dec (count);
   }
}

void delayms(uint xms)
{
    uint i, j;
    for (i = xms; i > 0; i--)
        // 如果有数码管显示有抖动, 请自行调整j的数值
        for (j = 50; j > 0; j--) {
            NOP();
        }
}
