#include <LiquidCrystal.h>

// Brochage : RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7; // le bouton est connecté à la broche 7
bool running = true;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

unsigned long previousMillis = 0;
int seconds = 0;

void setup() {
  lcd.begin(16, 2);  // initialiser l'écran LCD 16 colonnes et 2 lignes
  pinMode(buttonPin, INPUT_PULLUP); // bouton avec résistance interne
  lcd.setCursor(0, 0);
  lcd.print("SoloQ");
}

void loop() {
  // Lecture du bouton avec anti-rebond
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) {
      running = !running;  // Inverser l'état (pause / lecture)
    }
  }
  lastButtonState = reading;

  // Mise à jour du compteur si actif
  if (running && millis() - previousMillis >= 1000) {
    previousMillis = millis();
    seconds++;

    lcd.setCursor(0, 1);  // ligne 2
    lcd.print("Temps: ");
    lcd.print(seconds);
    lcd.print(" s     "); // espace pour effacer les anciens chiffres
  }
}
