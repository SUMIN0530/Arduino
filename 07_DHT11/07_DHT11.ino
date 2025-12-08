// #include : 외부 라이ㅡ러리를 불러오는 전처리기 지시문
#include "DHT.h"

// #define : 전처리기 매크로 (메모리 공간 사용 X)
#define DHTPIN 2
#define DHTTYPE DHT11

// DHT 센서를 제어하는 객체(오브젝트) 생성
// DHT : DHT 라이브러리에 정의된 클래스(class)
// 온습도를 읽는 기능이 담겨있음
// dht : 내가 만드는 객체 이름
// (DHTPIN, DHTTYPE) : dht 객체를 만들 때 전달하는 초기 설정값
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // 내가 만든 dht라는 객체를 시작
}

void loop() {
  delay(2000); // 측정 대기 시간 
  float h = dht.readHumidity(); // 습도
  float c = dht.readTemperature(); // 섭씨 온도
  float f = dht.readTemperature(true); // 화씨 온도

  if (isnan(h) || isnan(c) || isnan(f)) { // 측정 실패 시
    Serial.println('측정 실패'); // 시리얼 모니터에 "측정 실패" 출력
    return; // loop 함수를 처음부터 다시 실행
  }

  // 측정된 온습도 시리얼 모니터에 출력
  Serial.print("습도 : ");
  Serial.print(h);
  Serial.print("% | 섭씨 온도 : "); // 시리얼 모니터에 출력 - 습도 : (h값)%
  Serial.print(c);
  Serial.print("°C | 화씨 온도 : ");
  Serial.print(f);
  Serial.println("°F");

  // 한 줄로 작성하는 방법
  // Serial.println("습도 : " + String(h) + "% | 섭씨 온도 : " + String(c) + "°C | 화씨 온도 : " + String(f) + "°F")
}
