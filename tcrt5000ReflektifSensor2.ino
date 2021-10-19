int seviye = A0;
int kirmizi = 8;
int yesil = 9;
int mavi = 10;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  seviye = analogRead(A0);
  Serial.println(seviye);
  if(seviye > 500){
    digitalWrite(kirmizi, 0);
    digitalWrite(yesil, 1);
    digitalWrite(mavi, 1);
  }
  else if(seviye > 300){
    digitalWrite(kirmizi, 1);
    digitalWrite(yesil, 0);
    digitalWrite(mavi, 1);
  }
  else if(seviye > 50){
    digitalWrite(kirmizi, 1);
    digitalWrite(yesil, 1);
    digitalWrite(mavi, 0);
  }
  else{
    digitalWrite(kirmizi, 1);
    digitalWrite(yesil, 1);
    digitalWrite(mavi, 1);
  }
  delay(100);
}
