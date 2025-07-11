#include <LiquidCrystal.h> // Librairie pour Ecran LCD

int heure_date[6] = {10,20,15,9,07,2025}; //seconde minute heure jour mois année
int mod[6] = {60,60,24,31,12,3000}; // limite d incrementation
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // On initialise la librairie avec les pins ou l'ecran est branche

void setup() {
  lcd.begin(16, 2); // On initialise l'ecran avec sa taille
}

void loop() {
  heure_date[0]++;//incrementation du temps
    for (int i = 0; i < 6 ; i++){
      if (heure_date[i] == mod[i]) { // verification du dépassement de limite
        if (i<5) {heure_date[i+1] ++;}
        heure_date[i] = 0;
      }
    }
    lcd.setCursor(0,0); //On place le curseur sur la première ligne
    for (int j = 3; j < 5; j++) { //affichage de la date
      if (heure_date[j]<10){
        lcd.print("0");
        lcd.print(heure_date[j]);
      }
        else {lcd.print(heure_date[j]);}
      lcd.print("/");    
    }
    lcd.print(heure_date[5]); 
    lcd.setCursor(0,1); //On place le curseur sur la deuxième ligne
    for (int j = 2; j >= 0; j--) { //affichage de l'heure 
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
 