// 핀 나누는 이유 : 멀리 떨어진 대상 원격 조정같은 느낌
int switch1= 12; // 택트 스위치 1번과 연결된 12번 디지털 핀 번호
int switch2= 11;
int ledRed = 4;  // 택트 스위치 1번과 연결된 빨간색 LED
int ledGreen = 3;

void setup() {
   Serial.begin(9600); // 9600 속도로 시리얼 통신을 시작하겠다 
   pinMode(switch1, INPUT_PULLUP); // 스위치 1번 핀을 INPUT_PULLUP으로 사용
   pinMode(switch2, INPUT_PULLUP);
   pinMode(ledGreen , OUTPUT); // ledGreen번 디지털 핀으로 led를 켜기위해 전력을 출력하겠다
   pinMode(ledRed , OUTPUT);
}

void loop() 
{
  int SW1 = digitalRead(switch1); // 스위치 1의 상태를 저장한 변수
                                  // INPUT_PULLUP 모드를 사용했기 때문에
                                  // 기본적으로 1을 출력
                                  // 스위치가 눌리면 0을 출력
  int SW2 = digitalRead(switch2);

  digitalWrite(ledRed, LOW); // led는 OUTPUT 모드이므로 기본상태인 끈 상태는 LOW로 설정해야 한다
  digitalWrite(ledGreen, LOW); 

  if(SW1 == LOW){    // 만약 스위치 1이 LOW라면 == 스위치를 눌렀을 때
    Serial.println("Switch : RED");
    digitalWrite(ledRed, HIGH);  // 스위치가 눌렸으므로 led 켜기
  }
  if(SW2 == LOW){    // 스위치가 각각 독립적으로 동작해야 하므로 if문 두 개
    Serial.println("Switch : GREEN");
    digitalWrite(ledGreen, HIGH); 
  }
  delay(100);
}