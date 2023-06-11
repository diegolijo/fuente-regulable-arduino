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
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* byte tipo[8] = {0x04, 0x04, 0x0E, 0x15, 0x04, 0x0E, 0x0A, 0x1B};
byte smiley[8] = {0b00000, 0b00000, 0b01010, 0b00000, 0b00000, 0b10001, 0b01110, 0b00000};
byte heart[8] = {0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000}; */
byte uno[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte dos[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF};
byte tres[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF};
byte cuatro[8] = {0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF};
byte cinco[8] = {0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte seis[8] = {0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte siete[8] = {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte ocho[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

int sensorV = A4;

float toDecimalVol(int value)
{
  float dec = ((float)value * 5.0 / 1024.0) * 10;
  return dec;
}

void setup()
{
  // ************** LCD **************
  lcd.begin(16, 2);
  lcd.createChar(0, uno);
  lcd.createChar(1, dos);
  lcd.createChar(2, tres);
  lcd.createChar(3, cuatro);
  lcd.createChar(4, cinco);
  lcd.createChar(5, seis);
  lcd.createChar(6, siete);
  lcd.createChar(7, ocho);
  // ************** CAD **************
  // 1.1V analogReference(INTERNAL);
}

void loop()
{
  // ********* voltaje *********
  int valueV = analogRead(sensorV);
  float volt = toDecimalVol(valueV);
  // *********** LCD ***********
  lcd.setCursor(0, 1);
  lcd.print("Parrino         ");
  for (int i = 0; i < 8; i++)
  {
    float segment = (3 * i) + 11.0;
    if (volt < segment)
    {
      break;
    }
    lcd.setCursor(i + 8, 1);
    lcd.write((byte)i);
  }

  lcd.setCursor(0, 0);
  lcd.print("                ");
  if (volt < 10)
  {
    lcd.setCursor(10, 0);
    lcd.print(volt);
    lcd.print(" v");
  }
  else
  {
    lcd.setCursor(9, 0);
    lcd.print(volt);
    lcd.print(" v");
  }

  delay(500);
}
