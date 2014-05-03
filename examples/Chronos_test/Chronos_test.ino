
#include <ez430chronoslib.h>
#include "RTC_A.h"


void setup()
{
      
  lcd_init();
  
  RTC_init(55,12,12,3, MONDAY,6,1987);
  RTC_enableRTCInterrupt(Update);
  display_symbol(LCD_SEG_L1_COL,SEG_ON_BLINK_ON);
  
}

void Update() {
  

   char Second[3];
   char Minute[3];
   
   
  itoa(RTC_getSecond(),Second,10);
  itoa(RTC_getMinute(),Minute,10);
  
  
  display_chars(LCD_SEG_L1_3_0, Minute, SEG_ON);
  display_chars(LCD_SEG_L1_1_0, Second, SEG_ON);
  
}

void Alarm() {
  
}

void loop()
{
  __bis_SR_register(LPM3_bits + GIE);
}


