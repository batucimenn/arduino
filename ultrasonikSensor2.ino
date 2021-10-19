#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int yesil=8;
int mavi=9; 
int kirmizi=10;
int echoPin=6;
int trigPin = 7;
int sure;
int uzaklik;

void setup( ){
  lcd.begin(16, 2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(yesil,OUTPUT);
}

void loop( ){   
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure = pulseIn(echoPin,HIGH,11600);
  uzaklik = sure*0.0345/2;  
  delay(250);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Uzaklik:");
  lcd.setCursor(0,1);
  lcd.print(uzaklik);
  lcd.print(" cm");  
  if(uzaklik<20){
  digitalWrite(kirmizi, HIGH);
  digitalWrite(yesil, LOW);
  digitalWrite(mavi, LOW);    
  }
else if(uzaklik<50){
  digitalWrite(kirmizi,LOW);
  digitalWrite(yesil,HIGH);
  digitalWrite(mavi,LOW);  
  }
  else if(uzaklik<100){
  digitalWrite(kirmizi, LOW);
  digitalWrite(yesil, LOW);
  digitalWrite(mavi, HIGH);
  }
  else{
   digitalWrite(kirmizi, LOW);
  digitalWrite(yesil, LOW);
  digitalWrite(mavi, LOW);
  }  
} 
