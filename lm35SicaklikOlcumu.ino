#include <LiquidCrystal.h>

int lm35Pin = A0;
//*** lcd(rs, en, d4, d5, d6, d7); ***//
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  lcd.print("Sicaklik Olcumu: ");
}

void loop() {
  int s_Volt = analogRead(lm35Pin);
  float s_C = s_C = s_Volt / 9.31;
  lcd.setCursor(0, 1);
  lcd.print(s_C);
  lcd.setCursor(6, 1);
  lcd.print("\337C");
  delay(100);
}
