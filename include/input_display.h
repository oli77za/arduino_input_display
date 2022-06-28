#ifndef __INPUT_DISPLAY_H__
#define __INPUT_DISPLAY_H__

#include <LiquidCrystal_I2C.h> // Version 1.1.2
#include <Arduino.h>

const char *LCD_STRING_SOURCE = "**** SOURCE ****";
const char *LCD_STRING_0 = "    NO INPUT";
const char *LCD_STRING_1 = "   AV INPUT ";
const char *LCD_STRING_2 = "      PS_4  ";
const char *LCD_STRING_3 = "    NOT USED";
const char *LCD_STRING_4 = "     CD/DVD ";
const char *LCD_STRING_5 = "   COMPUTER ";

const char *LCD_STRINGS[6];

int curr_source = -1; // Used to store which source is currently displayed

int check_source(void);
void display_output(int source);

#endif