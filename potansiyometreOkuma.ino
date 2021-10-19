int potPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Analog input okuma ornegi.");
}

void loop() {
  int deger = analogRead(potPin);
  Serial.println(deger);
  delay(100);
}
