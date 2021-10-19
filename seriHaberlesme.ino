int k_Pin = 9;
int y_Pin = 10;
int m_Pin = 11;

void setup() {
  pinMode(k_Pin, OUTPUT);
  pinMode(y_Pin, OUTPUT);
  pinMode(m_Pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Renk gir Kırmızı = k, Yesil = y, Mavi = m");
}

void loop() {
  if(Serial.avaible()){
    char renk = Serial.read();
    Serial.println(renk);
    if(renk == 'k') {
      analogWrite(k_pin, 0); analogWrite(y_pin, 255); analogWrite(m_pin, 255);
    }
    else if(renk == 'y') {
      analogWrite(k_pin, 255); analogWrite(y_pin, 0); analogWrite(m_pin, 255);
    }
    else if(renk == 'm') {
      analogWrite(k_pin, 255); analogWrite(y_pin, 255); analogWrite(m_pin, 0);
    }
    else {
      analogWrite(k_pin, 255); analogWrite(y_pin, 255); analogWrite(m_pin, 255);
    }
  }
}
