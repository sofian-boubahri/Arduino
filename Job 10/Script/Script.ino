const int potPin = A1;    
const int led1 = 11;        
const int led2 = 10;       

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);           
  int ledBrightness1 = map(potValue, 0, 1023, 0, 255);   
  int ledBrightness2 = 255 - ledBrightness1;             

  analogWrite(led1, ledBrightness1);  
  analogWrite(led2, ledBrightness2); 
}

