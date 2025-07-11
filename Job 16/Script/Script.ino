#include <LiquidCrystal.h>

// Définir les broches selon ton schéma
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);  // Initialiser l'écran LCD 16x2
  lcd.clear();
}

void loop() {
  lcd.clear();
  for (int i = 0; i < 16; i++) {
    // Calculer le pourcentage
    int pourcentage = (i + 1) * 100 / 16;
    
    // Afficher le pourcentage sur la première ligne
    lcd.setCursor(0, 0);
    lcd.print(pourcentage);
    lcd.print("%");

    // Dessiner le rectangle (bloc plein) sur la deuxième ligne
    lcd.setCursor(i, 1);
    lcd.write(byte(1));

    delay(3000);  // Attendre 3 secondes avant d'ajouter un nouveau bloc
  }

  // Une fois terminé, on attend un peu et on recommence
  delay(3000);
}
