#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7; 
bool running = true;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

unsigned long previousMillis = 0;
int seconds = 0;

void setup() {
  lcd.begin(16, 2); 
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.setCursor(0, 0);
  lcd.print("SoloQ");
}

void loop() {
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) {
      running = !running;  
    }
  }
  lastButtonState = reading;

  if (running && millis() - previousMillis >= 1000) {
    previousMillis = millis();
    seconds++;

    lcd.setCursor(0, 1); 
    lcd.print("Temps: ");
    lcd.print(seconds);
    lcd.print(" s     ");
  }
}
