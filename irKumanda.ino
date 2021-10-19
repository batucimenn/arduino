#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTON0 0xFF6897
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF

int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    if(results.value == BUTON1){
      digitalWrite(led1, !digitalRead(led1));
    }
    if(results.value == BUTON2){
      digitalWrite(led2, !digitalRead(led2));
    }
    if(results.value == BUTON3){
      digitalWrite(led3, !digitalRead(led3));
    }
    if(results.value == BUTON4){
      digitalWrite(led4, !digitalRead(led4));
    }
    if(results.value == BUTON0){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    irrecv.resume();
  }
}
