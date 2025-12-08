int BTN1 = 12;
int ledRed = 4;

void setup() {
  Serial.begin(9600);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  int BTNState = digitalRead(BTN1);
  digitalWrite(ledRed, LOW);
  Serial.println(BTNState);

  if(BTNState == LOW) {
    Serial.println('Btn : Green');
    digitalWrite(ledRed, HIGH);
  }
  delay(100);
}
