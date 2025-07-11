#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int dhtPin = 7;

void setup() {
  pinMode(dhtPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Station Meteo");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(A0); 
  float temperature = 24.0 + random(-50, 50) / 10.0;
  float humidity = 50.0 + random(-200, 200) / 10.0;  

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223); 
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity, 1);
  lcd.print(" %");

  delay(2000);
}
