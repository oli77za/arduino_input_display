#include "input_display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 or )x20 for a 16 chars and 2 line display depending on your display.

void setup()
{
  pinMode(ch_2, INPUT);
  pinMode(ch_3, INPUT);
  pinMode(ch_4, INPUT);
  pinMode(ch_5, INPUT);
  Serial.begin(9600);

  lcd.init();      // Initialize the lcd
  lcd.backlight(); // Turn ON LCD backlight
  lcd.clear();

  lcd.print(LCD_STRING_SOURCE);
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

  
  if (!ch2_in && !ch3_in && !ch4_in && !ch4_in && curr_source != 1)
  {
    curr_source = 1;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRING_CH1); // Channel 1 of HDMI switcher LCD name
    Serial.write(LCD_STRING_CH1);
  }
  else if (ch2_in && curr_source != 2)
  {
    curr_source = 2;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRING_CH2); // Channel 2 of HDMI switcher LCD name
    Serial.write(LCD_STRING_CH2);
  }
  else if (ch3_in && curr_source != 3)
  {
    curr_source = 3;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRING_CH3); // Channel 3 of HDMI switcher LCD name
    Serial.write(LCD_STRING_CH3);
  }
  else if (ch4_in && curr_source != 4)
  {
    curr_source = 4;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRING_CH4); // Channel 4 of HDMI switcher LCD name
  }
  else if (ch5_in && curr_source != 5)
  {
    curr_source = 5;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRING_CH5); // Channel 5 of HDMI switcher LCD name
  }
}
