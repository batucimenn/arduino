#include <Servo.h>

Servo s_Motor;
int sensorPin1 = 9;
int sensorPin2 = 10;
int durum1, durum2;

void setup() 
{
  s_Motor.attach(9);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
}

void loop() 
{
  durum1 = digitalRead(sensorPin1);
  durum2 = digitalRead(sensorPin2);
  if (durum1 == HIGH  && durum2 == HIGH) 
  {
    s_Motor.write(0);
    delay(1500);
    s_Motor.write(45);
    delay(1500); 
  } 
  else if (durum1 == LOW && durum2 == HIGH) 
  {
    s_Motor.write(135);
    delay(1500);
    s_Motor.write(0);
    delay(1500); 
  }
  else 
  {
    s_Motor.write(0);
  }
}
