int k_Pin = 9;
int y_Pin = 10;
int m_Pin = 11;
int sure = 50;
int k = 0, y = 0, m = 0;

void setup() {
  pinMode(k_Pin, OUTPUT);
  pinMode(y_Pin, OUTPUT);
  pinMode(m_Pin, OUTPUT);
}

void loop() {
  for(k = 0; k <= 255; k++){
    for(y = 0; y <= 255; y++){
      for(m = 0; m <= 255; m++){
        analogWrite(k_Pin, k); analogWrite(y_Pin, y); analogWrite(m_Pin, m); delay(sure);
      }
    }
  }
}
