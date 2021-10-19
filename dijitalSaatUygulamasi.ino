#include <LiquidCrystal.h>

int sa = 0, dk = 0, sn = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16, 2);
}

void loop(){  
  sn = sn + 1;
  if(sn == 60){
    dk = dk + 1; sn = 0;
  }  
  if(dk==60){
    dk=0; sa=sa+1;
  }
  lcd.print("Saat: "); lcd.print(sa); lcd.setCursor(10, 0);
  lcd.print("Dk: "); lcd.print(dk); lcd.setCursor(0, 1);
  lcd.print("Saniye: "); lcd.print(sn); delay(1000);
  lcd.clear(); 
}
