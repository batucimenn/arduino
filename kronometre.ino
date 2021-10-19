#include "SevSeg.h"

SevSeg sevseg;

void setup() {
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
  static unsigned long timer = millis();
  static int salise = 0;
  if(millis() >= timer){
    salise++; timer += 100; if(salise > 9999) salise = 0;
    sevseg.setNumber(salise, 1);
  }
  sevseg.refreshDisplay();
}
