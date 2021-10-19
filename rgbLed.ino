int k_Pin = 9;
int y_Pin = 10;
int m_Pin = 11;

void setup() {
  pinMode(k_Pin, OUTPUT);
  pinMode(y_Pin, OUTPUT);
  pinMode(m_Pin, OUTPUT);
}

void loop() {
  analogWrite(k_Pin, 0); analogWrite(y_Pin, 255); analogWrite(m_Pin, 255); delay(1000); //Kırmızı 
  analogWrite(k_Pin, 255); analogWrite(y_Pin, 0); analogWrite(m_Pin, 255); delay(1000); //Yeşil 
  analogWrite(k_Pin, 255); analogWrite(y_Pin, 255); analogWrite(m_Pin, 0); delay(1000); //Mavi
  analogWrite(k_Pin, 0); analogWrite(y_Pin, 0); analogWrite(m_Pin, 255); delay(1000); //Sarı 
  analogWrite(k_Pin, 127); analogWrite(y_Pin, 255); analogWrite(m_Pin, 127); delay(1000); //Mor 
  analogWrite(k_Pin, 255); analogWrite(y_Pin, 127); analogWrite(m_Pin, 127); delay(1000); //Turkuaz 
  analogWrite(k_Pin, 0); analogWrite(y_Pin, 0); analogWrite(m_Pin, 0); delay(1000); //Beyaz 
}
