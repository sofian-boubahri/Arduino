const int leds[] = {1, 2, 3, 4, 5, 6, 7, 8};
const int nbLeds = 8;

void setup() {
  for (int i = 0; i < nbLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < nbLeds; i++) {
    digitalWrite(leds[i], HIGH); 
    delay(200);                  
    digitalWrite(leds[i], LOW);  
  }
}
