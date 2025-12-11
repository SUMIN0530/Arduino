/*조건
 1. 기본적으로 현재 온습도와 AO 출력값 출력
  -> 현재 가스농도는 깨끗한 공기 상태의 저항값을 측정해 코드에 반영
  -> AO 출력값 == ADO값 => 어려운 코드 -> 간단하게 AO출력값 출력
 2. 임의로 정한 AO 값을 기준으로 상태에 따라 LED 3개(빨, 초, 파)를 켜기
 3. 빨강 LED가 켜져 있을 때 
  -> 초음파 센서에 5cm이상 가까워지는 경우
  -> 초음파 센서와 연결된 빨강 LED를 0.1초 간격으로 깜빡이기
 4. 빨강 LED가 켜져있고, 초음파 센서에 5cm 이상 가까워진 상태에서 택트스위치를 누르면 피에조부저를 통해 경고음 출력
*/

// 순서
// 1. 온습도 센서와 가스 센서를 사용해 현재 온습도와 가스 AO 출력값을 시리얼 모니터에 출력하기
// 2. 가스 농도 기준으로 LED 3개(빨강, 초록, 파랑)을 켜 현재 가스 농도 보여주기
// 3. 초음파센서 연결하여 5cm 이내 물체 접근 여부 확인하기
// 4. 초음파센서를 통해 5cm 이내 물체 접근 시 LED 0.1초 간격으로 깜빡이기
// 5. 5cm 이내 물체 접근한 상황에서 택트 스위치가 눌릴 경우 피에조 부저로 경고음 출력 
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define GAS_A A0

#define LED_R 3
#define LED_G 4
#define LED_B 5

DHT mydht(DHTPIN, DHTTYPE);

void setup() {
  Seiral.begin(9600);
  mydht.begin();
  
  pinMode(GAS_A, INPUT);

  pinMode(LED_R, OUTPUT);
}

void loop() {
  delay(2000);
  float h = mydht.readHumidity();
  float c = mydht.readTemperature();
  float c = mydht.readTemperature(true);

  if (isnan(h) || isnan(c) || isnan(f)) { // 측정 실패 시
    Serial.println('측정 실패'); // 시리얼 모니터에 "측정 실패" 출력
    return; // loop 함수를 처음부터 다시 실행
  }
  Serial.println("습도 : " + String(h) + "% | 섭씨 온도 : " + String(c) + "°C | 화씨 온도 : " + String(f) + "°F");
}
