byte gosterge[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
***// a-2, b-3, c-4, d-5, e-6, f-7, g-8, h-9 nolu pinlere bağlı //***
int rakam = 0;
byte disp[8];

void setup() {
  for(int j = 2; j < 9; j++) pinMode(j, OUTPUT);
}

void loop() {
  rakam++;
  if(rakam > 9) rakam = 0;
  for(int i = 0; i < 7; i++){
    disp[i] = bitRead(gosterge[rakam], i);
    digitalWrite((i+2), disp[i]);
  }
  delay(500);
}
