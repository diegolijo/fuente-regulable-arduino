/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte polla[8] = {0x04, 0x04, 0x0E, 0x15, 0x04, 0x0E, 0x0A, 0x1B};
byte smiley[8] = {0b00000, 0b00000, 0b01010, 0b00000, 0b00000, 0b10001, 0b01110, 0b00000};
byte heart[8] = {0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000};

int sensorPin = A0;
int sensorValue = 0;

float toDecimal(int value)
{
  float dec = ((float)value * 50 / 1024.0);
  return dec;
}

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.createChar(0, polla);
  lcd.createChar(1, smiley);
  lcd.createChar(2, heart);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("I ");
  lcd.write((byte)2);
  lcd.print(" Jony ");
  lcd.write((byte)1);
  lcd.print(" ");
  lcd.write((byte)0);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  /*   float value = ((int) (dec * 100)) / 100.0; */
  float value = toDecimal(sensorValue);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  if (value < 10)
  {
    lcd.setCursor(10, 1);
    lcd.print(value);
    lcd.print(" v");
  }
  else
  {
    lcd.setCursor(9, 1);
    lcd.print(value);
    lcd.print(" v");
  }

  delay(500);
}
