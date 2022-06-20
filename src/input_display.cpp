#include "input_display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 or )x20 for a 16 chars and 2 line display depending on your display.

void setup()
{
  LCD_STRINGS[0] = LCD_STRING_CH1;
  LCD_STRINGS[1] = LCD_STRING_CH2;
  LCD_STRINGS[2] = LCD_STRING_CH3;
  LCD_STRINGS[4] = LCD_STRING_CH4;
  LCD_STRINGS[8] = LCD_STRING_CH5;

  pinMode(ch_2, INPUT);
  pinMode(ch_3, INPUT);
  pinMode(ch_4, INPUT);
  pinMode(ch_5, INPUT);

  lcd.init();      // Initialize the lcd
  lcd.backlight(); // Turn ON LCD backlight
  lcd.clear();

  lcd.print(LCD_STRING_SOURCE);

  #ifdef DEBUG
  Serial.begin(9600);
  #endif

}

void loop()
{
  check_source();
  delay(10);
}

void check_source(void)
{
  bool ch2_in = digitalRead(ch_2) == HIGH;
  bool ch3_in = digitalRead(ch_3) == HIGH;
  bool ch4_in = digitalRead(ch_4) == HIGH;
  bool ch5_in = digitalRead(ch_5) == HIGH;

  byte source = 0 |ch2_in |(ch3_in << 1) |(ch4_in << 2) |(ch5_in << 3); 
  
  if (source != curr_source) {
    curr_source = source;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRINGS[source]); // Channel 1 of HDMI switcher LCD name
    #ifdef DEBUG
    Serial.write(LCD_STRINGS[source]);
    #endif
  }
}
