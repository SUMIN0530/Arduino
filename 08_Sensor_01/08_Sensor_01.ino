#define TRIG 9
#define ECHO 8

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT); // 초음파를 출력
  pinMode(ECHO, INPUT); // 초음파를 수신
}

void loop() {
  digitalWrite(TRIG, HIGH);
  // delay(10) === delayMicroseconds(10)이 더 올바른 형태
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW); // 송신부로 초음파를 10마이크로초 출력

  float duration = pulseIn(ECHO, HIGH); // ECHO와 연결된 8번 핀에서 입력을 시간으로 받겠다
  float distance = ((34000*duration)/1000000)/2; // 편도 시간을 기준으로 거리 계산식

  Serial.print(distance);
  Serial.println("cm"); // '' 안먹는데?
  delay(100);
}
