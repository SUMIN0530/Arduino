int LED_PIN = 3;

void analogOn() {
  for (int i = 0; i < 255; i++) {
    analogWrite(LED_PIN, i);
    delay(5);
  }

  analogWrite(LED_PIN, 0);
  delay(5);
}


void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogOn();
}
