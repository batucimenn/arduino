#include <EEPROM.h> 

int buzzer = 5, ledPin = 13; 
long int sayi, birler, on_binler, x;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.print("Sayıyı giriniz: ");
}

void loop()
{
  if(Serial.available())
  {    
     long int i, sayi1, sayi2, sayi3;
     sayi = Serial.parseInt();
     i = sayi;
     sayi1 = i % 100;
     i = i / 100;
     sayi2 = i % 100;
     i = i / 100;
     sayi3 = i;  
     EEPROM.write(2,sayi3);
     EEPROM.write(1,sayi2);
     EEPROM.write(0,sayi1);      
     Serial.print(EEPROM.read(2));
     Serial.print(EEPROM.read(1));
     Serial.println(EEPROM.read(0));
     delay(1000);
     birler = sayi % 10;      
     on_binler = sayi / 10000;     
      x = ((sayi % 10000) - (sayi % 10)) / 10;      
      Serial.print("Aradaki sayi: ");
      Serial.println(x);
      delay(1000);
      Serial.print("Buzzer ");
      Serial.print(on_binler);
      Serial.println(" kez ses çıkartır.");
      delay(1000);
      Serial.print("Led ");
      Serial.print(birler);
      Serial.println(" kez yanıp söner.");
      delay(1000);      
      while(on_binler > 0)
      {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay((x * 2,5) / 100);
        on_binler--;
       }
       delay(100);      
       while(birler > 0)
       {
          digitalWrite(ledPin, HIGH);
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(x / 10);
          birler--;
        }
     }
  }
