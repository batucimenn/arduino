const int motorA1 = 9; //L298N'in IN3 Girişi
const int motorA2 = 8; //L298N'in IN1 Girişi
const int motorB1 = 11; //L298N'in IN2 Girişi
const int motorB2 = 10; //L298N'in IN4 Girişi
const int led = 13;
const int buzer = 2;
int i = 0;
int j = 0;
int state;
int vSpeed = 255;

void setup() {
  //Pinlerimizi belirleyelim
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzer, OUTPUT);
  Serial.begin(9600);
  delay(10);
}

void loop() {
  /*Bluetooth bağlantısı koptuğunda veya kesildiğinde arabayı durdur. (Aktif etmek için alt satırın "//" larını kaldırın.) */
  //if(digitalRead(BTState) == LOW) { state = 'S'; }
  if(Serial.available() > 0){
    state = Serial.read();
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    //Serial.println("geldi");
  }
  if(state == '0') { vSpeed = 0; }
  else if(state == '1') { vSpeed = 25; }
  else if(state == '2') { vSpeed = 50; }
  else if(state == '3') { vSpeed = 75; }
  else if(state == '4') { vSpeed = 100; }
  else if(state == '5') { vSpeed = 125; }
  else if(state == '6') { vSpeed = 150; }
  else if(state == '7') { vSpeed = 175; }
  else if(state == '8') { vSpeed = 200; }
  else if(state == '9') { vSpeed = 250; }
  else if(state == 'q') { vSpeed = 255; }
  if(state == 'F') { 
    //Gelen veri 'F' ise araba ileri gider. 
    analogWrite(motorA1, vSpeed); digitalWrite(motorA2, LOW);
    analogWrite(motorB1, (vSpeed)); digitalWrite(motorB2, LOW);
    }
   else if(state == 'B') { 
    //Gelen veri 'B' ise araba geri gider. 
    analogWrite(motorA1, (255 - vSpeed)); digitalWrite(motorA2, HIGH);
    analogWrite(motorB1, (255 - vSpeed)); digitalWrite(motorB2, HIGH);
    }
   else if(state == 'I') { 
    //Gelen veri 'I' ise araba ileri sol(çapraz) gider. 
    analogWrite(motorA1, vSpeed); digitalWrite(motorA2, LOW);
    analogWrite(motorB1, (vSpeed / 2)); digitalWrite(motorB2, LOW);
    }
    else if(state == 'G') { 
    //Gelen veri 'G' ise araba ileri sağ(çapraz) gider. 
    analogWrite(motorA1, (vSpeed / 2)); digitalWrite(motorA2, LOW);
    analogWrite(motorB1, vSpeed); digitalWrite(motorB2, LOW);
    }
    else if(state == 'J') { 
    //Gelen veri 'J' ise araba geri sol(çapraz) gider. 
    analogWrite(motorA1, 175); digitalWrite(motorA2, HIGH);
    analogWrite(motorB1, (255 - vSpeed)); digitalWrite(motorB2, HIGH);
    }
    else if(state == 'H') { 
    //Gelen veri 'H' ise araba geri sağ(çapraz) gider. 
    analogWrite(motorA1, (255 - vSpeed)); digitalWrite(motorA2, HIGH);
    analogWrite(motorB1, 175); digitalWrite(motorB2, HIGH);
    }
    else if(state == 'R') { 
    //Gelen veri 'R' ise araba sağ gider. 
    analogWrite(motorA1, vSpeed); digitalWrite(motorA2, LOW);
    analogWrite(motorB1, (255 - vSpeed)); digitalWrite(motorB2, HIGH);
    }
    else if(state == 'L') { 
    //Gelen veri 'L' ise araba sola gider. 
    analogWrite(motorA1, (255 - vSpeed)); digitalWrite(motorA2, HIGH);
    analogWrite(motorB1, vSpeed); digitalWrite(motorB2, LOW);
    }
    else if(state == 'S') { 
    //Gelen veri 'S' ise arabayı durdur. 
    analogWrite(motorA1, 0); digitalWrite(motorA2, LOW);
    analogWrite(motorB1, 0); digitalWrite(motorB2, LOW);
    }
}
