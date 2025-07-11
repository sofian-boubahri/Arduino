#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = {
  B01010,
  B01010,
  B00000,
  B01010,
  B00100,
  B01110,
  B00000,
  B00000
};

void setup() {
  lcd.begin(16, 2);            
  lcd.createChar(0, smiley);  
  lcd.setCursor(0, 0);         
  lcd.print("Hello :)");
  lcd.setCursor(8, 0);         
  lcd.write(byte(0));          
}

void loop() {
}
