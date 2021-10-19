# define a1 3
# define a2 5

int ldr = A0;
int led = 2; 
int ldrdeger;     
const int iPin = A1;
float voltDeger = 0;
float sensorDeger = 0;
float sicaklik = 0;
int time;  

void setup() 
{ 
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
} 

void loop() 
{  
  ldrdeger = analogRead(A0); 
  Serial.print("LDR Değeri= ");
  Serial.print(ldrdeger);
  float analogvoltaj = (float)5/1023*ldrdeger;
  Serial.print("  Voltaj Değeri= ");
  Serial.print(analogvoltaj);
  Serial.println("V= ");  
  if (analogvoltaj > 2.78)
  {
       digitalWrite(led, HIGH);
  }
   else
  {
      digitalWrite(led, LOW);
  } 
  sensorDeger = analogRead(iPin);
  Serial.print("Isının Sensördeki Değeri= ");
  Serial.println(sensorDeger);   
  voltDeger = (sensorDeger/1023)*5000; 
  Serial.print("Gerilim Değeri= ");
    Serial.println(voltDeger);  
  sicaklik = voltDeger/10; 
  Serial.print("Sıcaklık Değeri= ");
  Serial.print(sicaklik);
  Serial.println(" C"); 
  if (sicaklik > 45)
  { 
  digitalWrite(a2, HIGH);  
  }
  else     
  { 
      delay(2500);
      digitalWrite(a1, HIGH);
      delay(600000);
      digitalWrite(a1, LOW);     
  }
 delay(1500);
}
