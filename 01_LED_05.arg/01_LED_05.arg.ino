// 매개변수화
// 함수에는 매개변수를 사용하여 더 확장성 있는 함술르 선언할 수 있음

int leds[] = {12, 11, 10};
int count = 3;
int delayMs = 500;

void blinkAll(bool state) {   // state는 불리언 true, false만 변수로 들어갈 수 있음
  for (int i = 0; i < count; i++) {
    digitalWrite(leds[i], state ? HIGH : LOW); // state ? H : L => if 조건문
    delay(delayMs);
  }
}
void setup() {
  for (int i = 0; i < count; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  blinkAll(true);
  blinkAll(false);
}
