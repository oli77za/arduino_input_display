#include "input_display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 or )x20 for a 16 chars and 2 line display depending on your display.

void setup()
{
  LCD_STRINGS[0] = LCD_STRING_0;
  LCD_STRINGS[1] = LCD_STRING_1;
  LCD_STRINGS[2] = LCD_STRING_2;
  LCD_STRINGS[3] = LCD_STRING_3;
  LCD_STRINGS[4] = LCD_STRING_4;
  LCD_STRINGS[5] = LCD_STRING_5;

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A6, INPUT);

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
  const int source = check_source();
  display_output(source);
  delay(10);
}

int check_source(void)
{
  int source = 0;
  if (digitalRead(A0) == LOW) {
    source = 1;
  }
  if (digitalRead(A1) == LOW) {
    source = 2;
  }
  if (digitalRead(A2) == LOW) {
    source = 3;
  }
  if (digitalRead(A3) == LOW) {
    source = 4;
  }
  if (digitalRead(A6) == LOW) {
    source = 5;
  }

  return source;
}

void display_output(int source)
{
  if (source != curr_source)
  {
    curr_source = source;
    lcd.setCursor(0, 1);
    lcd.print(LCD_STRINGS[source]); // Channel 1 of HDMI switcher LCD name
#ifdef DEBUG
    Serial.write(LCD_STRINGS[source]);
#endif
  }
}
