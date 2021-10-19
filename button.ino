int ledPin = 5;
int buttonA = 9;
int buttonB = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonA, OUTPUT);
  pinMode(buttonB, OUTPUT);
}

void loop() {
  if(digitalRead(buttonA) == LOW) digitalWrite(ledPin, HIGH);
  if(digitalRead(buttonB) == LOW) digitalWrite(ledPin, LOW);
}
