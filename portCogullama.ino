int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
byte led = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 256; i++){
    led = i;
    ledYaz();
    delay(50);
  }
}

void ledYaz(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, led);
  digitalWrite(latchPin, HIGH);
}
