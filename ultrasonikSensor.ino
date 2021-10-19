#include <NewPing.h>
#define TRIG 12
#define ECHO 11
#define MAX_MES 200

NewPing sonar(TRIG, ECHO, MAX_MES);
void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
