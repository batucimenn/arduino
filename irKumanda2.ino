#include <IRremote.h>

int a = 6; int b = 7; int c = 9;
int d = 10; int e = 11; int f = 5;
int g = 4; int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTON0 16593103
#define BUTON1 16582903
#define BUTON2 16615543
#define BUTON3 16599223
#define BUTON4 16591063
#define BUTON5 16623703
#define BUTON6 16607383
#define BUTON7 16586983
#define BUTON8 16619623
#define BUTON9 16603303

void setup(){
    pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT);
    pinMode(d, OUTPUT); pinMode(e, OUTPUT); pinMode(f, OUTPUT);
    pinMode(g, OUTPUT); Serial.begin(9600); irrecv.enableIRIn(); 
}

void loop(){
    if(irrecv.decode(&results)){
        Serial.println(results.value);
    if(results.value==BUTON0){
        digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
        digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH);
    }
    if(results.value==BUTON1){
      digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);
      digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); 
    }
    if(results.value==BUTON2){
      digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, LOW);
      digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, LOW);    
    }

    if(results.value==BUTON3){
      digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
      digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW);
    }
    if(results.value==BUTON4){
      digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);
      digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW);
    }
     if(results.value==BUTON5){
      digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW);
      digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW);
    }
    if(results.value==BUTON6){
      digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW);
      digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);
    }
    if(results.value==BUTON7){
      digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);
      digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH);
    }
     if(results.value==BUTON8){
      digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
      digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);    
    }
    if(results.value==BUTON9){
      digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
      digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW);
    }
       irrecv.resume();
  }   
}
