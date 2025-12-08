void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);

  // 조도 센서는 빛이 강하면 저항값이 작아짐 -> 전압(출력값)이 커짐
  // 조도 센서는 빛이 강하면 저항값이 커짐 -> 전압(출력값)이 작아짐
  if (light > 980) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
    
