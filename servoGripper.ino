#include <Servo.h>  

Servo s_Motor;
int k1, k2, k3, k4;
int bekle;

void Setup() 
{ 
  s_Motor.attach(9);
  for(int i=4; i<=11; i++)
  {
    pinMode(i, OUTPUT);
  }
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW); 
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  k1 = 4;
  k2 = 7;
  k3 = 8;
  k4 = 11;
  bekle = 10;
}

void loop() 
{ 
  ilerle(200);
  sagaDon(90);
  delay(1000); 
  ilerle(500);
  delay(1000);
  solaDon(90);
  delay(1000);
  ilerle(100);
  delay(1000);
  solaDon(150);
  delay(1000);
  ilerle(700);
  delay(1000);
  sagaDon(80);
  delay(1000);
  ilerle(750);
  delay(1000);
  solaDon(100);
  ilerle(1050);
  delay(1000);
  s_Motor.write(0);
  solaDon(60);
  ilerle(1350);
  s_Motor.write(90);
}

void ilerle (int adim) 
{
  for(int i = 0; i < adim; i++) 
  {
  digitalWrite(k1, HIGH);
  delay(bekle);
  digitalWrite(k1, LOW);
  k_Yukselt();  
  digitalWrite(k4, HIGH);
  delay(bekle);
  digitalWrite(k4, LOW);
  k_indir();
 }
}

void sagaDon (int adim) 
{
  for(int i = 0; i < adim; i++) 
{
  digitalWrite(k2, HIGH);
  delay(bekle);
  digitalWrite(k2, LOW);
  k_SagSol2();
  
  digitalWrite(k4, HIGH);
  delay(bekle);
  digitalWrite(k4, LOW);
  k_Yukselt();
 }
}

void solaDon (int adim) 
{
  for(int i = 0; i < adim; i++) {
  digitalWrite(k1, HIGH);
  delay(bekle);
  digitalWrite(k1, LOW);
  k_Yukselt();  
  digitalWrite(k3, HIGH);
  delay(bekle);
  digitalWrite(k3, LOW);
  k_SagSol1();
 }
}

void k_Yukselt() 
{
 k1++;
 if (k1 == 8) k1 = 4;
}

void k_indir() {
  k4--;
  if (k4 == 7) k4 = 11;
}

void k_SagSol1() 
{
  k3++;
  if (k3 == 12) k3 = 8;
}

void k_SagSol2() 
{
  k2++;
  if (k2 == 3) k2 = 7;
}
