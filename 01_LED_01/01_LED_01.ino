int PIN = 3;

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  // 켜기
  digitalWrite(PIN, HIGH);
  delay(1000);

  // 끄기
  digitalWrite(PIN, LOW);
  delay(1000);
}
