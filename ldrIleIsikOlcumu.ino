int LDR = A0;
int Led = 3;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  int deger = analogRead(LDR);
  analogWrite(Led, (deger / 4));
  delay(100);
}
