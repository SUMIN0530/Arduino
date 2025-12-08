const int melody[] = {
  // 도 -> 도
  262, 294, 330, 349, 392, 440, 494, 523
}
const int PIEZO_PIN = 8;

void setup() {
  for (int i = 0; i < 9; i++); {
    tone(PIEZO_PIN, melody[i], 500); delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
