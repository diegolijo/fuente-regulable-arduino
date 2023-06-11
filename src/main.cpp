#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte uno[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte dos[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF};
byte tres[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF};
byte cuatro[8] = {0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF};
byte cinco[8] = {0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte seis[8] = {0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte siete[8] = {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte ocho[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

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
  int valueV = analogRead(A4);
  float volt = toDecimalVol(valueV);
  // *********** LCD ***********
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

  delay(500);
}
