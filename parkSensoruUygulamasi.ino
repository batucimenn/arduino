#define echoPin 6
#define trigPin 7
#define buzzerPin 8

void setup( )
{  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop( )
{ 
  int olculen = mesafe(100,0);
    ses(olculen*10);
}

int mesafe(int maxR,int minR){
  long sure, uzaklik;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  sure = pulseIn(echoPin, HIGH);
  uzaklik = sure/58.2;
  delay(50);  
  if(uzaklik>maxR||uzaklik<minR){
      return 0;
  }
  return uzaklik;  
}

int ses(int x){
  tone(buzzerPin, 200);
  delay(x);
  noTone(buzzerPin);
  delay(x);
}
