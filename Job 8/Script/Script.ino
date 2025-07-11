const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness += 1) {
    analogWrite(ledPin, brightness);
    delay(2000); 
  }

  for (int brightness = 255; brightness >= 0; brightness -= 1) {
    analogWrite(ledPin, brightness);
    delay(2000);
  }
}
