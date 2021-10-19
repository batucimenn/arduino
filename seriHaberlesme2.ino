int k_Pin = 9;
int y_Pin = 10;
int m_Pin = 11;

void setup() {
  pinMode(k_Pin, OUTPUT);
  pinMode(y_Pin, OUTPUT);
  pinMode(m_Pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Renk değerlerini aralarına boşluk bırakarak girin 0-255");
  Serial.println("Örnek 200 155 100");
}

void loop() {
  if(Serial.avaible()){
    int kir = Serial.parseInt();
    int yes = Serial.parseInt();
    int mavi = Serial.parseInt();
    Serial.print("kirmizi ="); Serial.println(kir);
    Serial.print("yesil ="); Serial.println(yes);
    Serial.print("mavi ="); Serial.println(mavi);
    analogWrite(k_Pin, kir); analogWrite(y_Pin, yes); analogWrite(m_Pin, mavi);
  }
}
