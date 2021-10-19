int engelSensor_Pin = 2;
int sola_ileri = 3;
int sola_geri = 4;
int sag_ileri = 6;
int sag_geri = 5;
int zaman;
int uzaklik;
int yon = 0;

void setup()
{
  pinMode(sola_ileri, OUTPUT);
  pinMode(sola_geri, OUTPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  Serial.begin(9600);
}

void sag()
{
  digitalWrite(sola_ileri, HIGH);
  digitalWrite(sola_geri, LOW);
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, HIGH);
  Serial.println("Saga donuldu.");
  delay(500);
}

void sol()
{
  digitalWrite(sola_ileri, LOW);
  digitalWrite(sola_geri, HIGH);
  digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
  Serial.println("Sola dönüldü.");
  delay(500);
}

void duz()
{
  digitalWrite(sola_ileri, HIGH);
  digitalWrite(sola_geri, LOW);
  digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
}

void loop()
{
  pinMode(engelSensor_Pin, OUTPUT);
  digitalWrite(engelSensor_Pin, LOW);
  delayMicroseconds(5);
  digitalWrite(engelSensor_Pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(engelSensor_Pin, LOW);
  pinMode(engelSensor_Pin, INPUT);
  zaman = pulseIn(engelSensor_Pin, HIGH);
  uzaklik = zaman / 29.1 / 2;    
  if(uzaklik < 30)
  {
    if(yon == 0, yon == 2, yon == 3, yon == 6 )
    {
      sag();
      delayMicroseconds(3.9);
      duz();
      yon++;
   }
   else if(yon == 1,  yon == 4 || yon== 5)
   {
      sol();
      delayMicroseconds(3.9);
     duz();
      yon++;
    }
    else
    {
      duz();
    }
  }
  if(yon == 7)
  {
    Serial.println("Çıkışa ulaşıldı.");
    digitalWrite(sola_ileri, LOW);
    digitalWrite(sola_geri, LOW);
    digitalWrite(sag_ileri, LOW);
    digitalWrite(sag_geri, LOW);
    yon++;
  }  
}
