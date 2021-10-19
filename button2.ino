int ledPin = 5;
int buttonA = 9;
byte durum = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonA, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(buttonA) == LOW){
    delay(100);
    while(digitalRead(buttonA) == LOW);
    durum =~ durum;
    digitalWrite(ledPin, durum);
    delay(1000);
  }
}
