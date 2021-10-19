#include <dht11.h> // dht1 kütüphanesini ekliyoruz.
#define DHT11PIN 2 

dht11 DHT11;

void setup() {
  Serial.begin(9600); // Seri iletişimi başlatıyoruz.
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(DHT11.dewPoint(), 2);
  delay(2000);
}
