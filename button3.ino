int buttonA = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonA, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(buttonA) == LOW) {
    delay(100);
    while(digitalRead(buttonA) == LOW);
    digitalWrite(ledPin, !digitalRead(ledpin));
  }
}
