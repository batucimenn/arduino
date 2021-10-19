int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int butonPin = 7;
int potPin = A0;

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(butonPin, INPUT_PULLUP);
}

void loop() {
  int hiz = analogRead(potPin) / 4;
  boolean yon = digitalRead(butonPin);
  motor(hiz, yon);
}

void motor(int hiz, boolean yon){
  analogWrite(enablePin, hiz);
  digitalWrite(in1Pin, ! yon);
  digitalWrite(in2Pin, yon);
}
