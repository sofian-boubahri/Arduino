#include <LiquidCrystal.h> 

int heure_date[6] = {10,20,15,9,07,2025}; 
int mod[6] = {60,60,24,31,12,3000}; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  heure_date[0]++;
    for (int i = 0; i < 6 ; i++){
      if (heure_date[i] == mod[i]) { 
        if (i<5) {heure_date[i+1] ++;}
        heure_date[i] = 0;
      }
    }
    lcd.setCursor(0,0); 
    for (int j = 3; j < 5; j++) { 
      if (heure_date[j]<10){
        lcd.print("0");
        lcd.print(heure_date[j]);
      }
        else {lcd.print(heure_date[j]);}
      lcd.print("/");    
    }
    lcd.print(heure_date[5]); 
    lcd.setCursor(0,1);
    for (int j = 2; j >= 0; j--) { 
      if (heure_date[j]<10)
      {
        lcd.print ("0");
        lcd.print(heure_date[j]);
      }else {lcd.print(heure_date[j]);}
      if (j != 0){
        lcd.print(":"); 
      }   
    }
    delay(250);
}
 
