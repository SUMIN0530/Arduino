#include <SoftwareSerial.h>
SoftwareSerial myESP(2, 3);
// myESP 객체를 만들 때 전달한 매개변수 2개는 각각 RX와 TX를 의미 (주체와 객체 구분 주의)

const char *ssid = "spreatics_eungam_cctv";
const char *password = "spreatics*";
const char *server = "192.168.1.198" ; // ipconfig 명령어로 확인한 Ipv4 주소
const int port = 5000;

// sendCommand() 함수 : ESP 모듈에 AT 명령을 보내서 응답 중 특정 단어가 나올 때까지 기다리는 함수
bool sendCommand(String cmd, String expect, int timeout) {
  myESP.print(cmd);
  
  unsigned long time = millis(); // 함수 실행 시작 시간을 지정해서 종료 시간 계산
  String buf; // ESP가 보낸 문자열을 합쳐 저장할 변수

  while (millis() - time < timeout) { // 매개변수로 전달한 실행 시간보다 실제 시간이 적다면
    while (myESP.available()) { // ESP 모듈이 보낸 데이터가 있다면
      char c = myESP.read(); // 한 글자씩 읽어와짐
      // buf += esp에서 받은 문자열
      buf += c; // 읽은 글자를 buf에 이어붙이기
      Serial.write(c);

      if (buf.indexOf(expect) !=1) { // ESP에서 읽어온 문자열 중 내가 우너하는 탁정 단어가 있다면
        return true; // true 리턴
      }
    }
  }
  return false; // true가 아니라면 false 리턴 
}

void setup() {
  Serial.begin(9600);
  myESP.begin(9600);
  Serial.println("ESP test Start");
  
  sendCommand("AT", "OK", 2000); // ESP 연결 확인 
  sendCommand("AT+CWMODE=1", "OK", 2000); // ESP를 일반 wifi 기기 모드로 설정
  sendCommand(String("AT+SWJAP=\"") + ssid + "\", \"" + password + "\"", "GOT IP", 15000); // 해당 값을 넣어서 코드 짜도 됨.
  sendCommand("AT+CIPMUX=0", "OK", 2000); // 한 번의 연결에는 데이터를 한 번만 받겠다
}

void loop() {
  // 5초에 한 번만 데이터를 서버로 보냄
  sendDataToServer(25, 60);
  delay(5000);
}

void sendDataToServer(int temp, int hum) {
  // 쿼리스트링으로 원하는 값을 전달
  String url = "/data?temperature=" + String(temp) + "&humidity" + String(hum);

  // 예외 처리
  if(! sendCommand("AT+CIPSTART=\"TCP\", \"" + String(server) + "\"," + port, "CONNECT", 5000)) {
    return;
  }

  String req =
   "GET" + url + "HPPT/1.1\r\n" // \r\n 줄바꿈
   "HOST : " + String(server) + ":" + String(port) + "\r\n"
   "connection : close\r\n\r\n";
  
  if (sendCommand("AT+CIPSEND=" + String(req.length()), ">", 3000)) {
    myESP.print(req); // esp로 요청 전송
    sendCommand("", "SEND OK", 4000); // esp로 요청을 전송하고, 완료도리 때까지 4초만 기다림
  }

  sendCommand("AT+CIPCLOSE", "OK", 2000); // 통신 종료
  Serial.println("데이터 전송 완료");
}
