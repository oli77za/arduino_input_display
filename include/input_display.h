#ifndef __INPUT_DISPLAY_H__
#define __INPUT_DISPLAY_H__

#include <LiquidCrystal_I2C.h> // Version 1.1.2
#include <Arduino.h>

const char *LCD_STRING_SOURCE = "**** SOURCE ****";
const char *LCD_STRING_CH1 = "   AV INPUT ";
const char *LCD_STRING_CH2 = "      PS_4  ";
const char *LCD_STRING_CH3 = "    NOT USED";
const char *LCD_STRING_CH4 = "     CD/DVD ";
const char *LCD_STRING_CH5 = "   COMPUTER ";

const char *LCD_STRINGS[9];

const int ch_2 = A0; // Inputs from HDMI switcher
const int ch_3 = A1;
const int ch_4 = A2;
const int ch_5 = A3;

int curr_source = 0; // Used to store which source is currently displayed

void check_source(void);

#endif