// 실행 된다!! -> LED, 부저 직렬 연결
#define GAS_A A0
#define GAS_D 8

void setup() {
  Serial.begin(9600);
  Serial.print("히터 가열");
  delay(1000);
  pinMode(11, OUTPUT);
}

void loop() {
  float sensorAvalue = analogRead(GAS_A);
  float sensorDvalue = digitalRead(GAS_D);

  Serial.print("센서 입력 : ");
  Serial.print(sensorAvalue);


  if (sensorAvalue > 25) {
    Serial.print(" !!연기 감지!! ");
    Serial.print(" ");

    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(1000);
  }
    Serial.print(" 센서 디지털 : ");
    Serial.println(sensorDvalue);
    delay(1000);
}
