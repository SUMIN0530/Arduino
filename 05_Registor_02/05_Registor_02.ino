void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT); // LED를 조정 PWM인 핀만 가능(analog -> digital)
}

void loop() {
  int registor = analogRead(A0);
  Serial.println(registor);
  // map()이라는 내장 합수를 사용하여 입력값(0~1023)을 출력값(0~255)으로 변환
  // map(맵핑하려는 값, 입력범위의 최소값, 입력범위의 최대값, 출력범위의 최소값, 출력범위의 최대값)
  registor = map(registor, 0, 1023, 0, 255); // 입력값의 Mm 입력값, Mm 출력값 => 입력값을 출력값을로 변환
  analogWrite(6, registor);
  delay(100);
}
