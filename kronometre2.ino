#include "SevSeg.h"

int but_0 = A0;
int but_1 = A1;
boolean kont = 0;
SevSeg sevseg;

void setup() {
  pinMode(but_0, INPUT_PULLUP);
  pinMode(but_1, INPUT_PULLUP);
  byte numDigits = 4;
  byte digitPins[] = {13, 12, 11, 10};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_CATHODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros); 
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = 0;
  static int salise = 0;
  if(digitalRead(but_0) == LOW){
    kont = 1;
    timer = millis();
    salise = 0;
  }
  while(kont == 1){
    if(digitalRead(but_1) == LOW) kont = 0;
    if(millis() >= timer){
      salise++; timer += 100; if(salise > 9999) salise = 0;
      sevseg.setNumber(salise, 1);
    }
    sevseg.refreshDisplay();
  }
  sevseg.refreshDisplay();
}
