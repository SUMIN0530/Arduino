int LED_PIN = 3;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, 255); // 최대 출력 (digitalWtite_HIGH(5V)와 동일)
  delay(500);

  analogWrite(LED_PIN, 128); // 50% 출력 -> 2.5V
  delay(500);

  analogWrite(LED_PIN, 0); // 최소 출력 (digitalWtite_LOW(0V)와 동일)
  delay(500);
}
