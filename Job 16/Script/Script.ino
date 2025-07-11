#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);  
  lcd.clear();
}

void loop() {
  lcd.clear();
  for (int i = 0; i < 16; i++) {
    int pourcentage = (i + 1) * 100 / 16;
    
    lcd.setCursor(0, 0);
    lcd.print(pourcentage);
    lcd.print("%");

    lcd.setCursor(i, 1);
    lcd.write(byte(1));

    delay(3000); 
  }

  delay(3000);
}
