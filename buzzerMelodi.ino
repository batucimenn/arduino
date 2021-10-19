#define do1 1000
#define re 1122
#define mi 1260
#define fa 1335
#define sol 1498
#define la 1681
#define si 1887
#define do2 2000

int buz = 12;
int melodi[] = {do1, re, do2, si, do1, re, do2, si, do1, si, do1, re, do2, si, do1, si, la, si, la, sol, fa, la};
int N_sure[] = {6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 6, 2, 6, 9, 8, 5, 5, 2};
int tempo = 1200;

void setup() {
  pinMode(buz, OUTPUT);
  digitalWrite(buz, HIGH); delay(500);
  digitalWrite(buz, LOW); delay(500);
  digitalWrite(buz, HIGH); delay(500);
  digitalWrite(buz, LOW); delay(500);
}

void loop() {
  for(int i = 0; i < 24; i++){
    int sure = tempo / N_sure[i];
    tone(8, melodi[i], sure);
    delay(sure * 1.2);
  }
}
