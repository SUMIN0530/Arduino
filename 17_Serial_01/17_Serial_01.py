# 아두이노와 연결 vs code에서 입력해서 arduino 제어

import serial
import time

# 아두이노 시리얼 연결
arduino = serial.Serial("COM4", 9600)
time.sleep(1) # 안정적인 통신을 위해 1초 딜레이

# 조건
# 1을 입력하면 LED 켜기
# 0을 입력하면 LED 끄기

print("'1'을 입력 => LED ON & '0'을 입력 => LED OFF")
print("다른 값을 입력하면 python 프로그램 종료")

while 1 :
    var = input() # 터미널에서 입력된 문자열 저장

    if var == '1':
        # 아두이노에게 값을 전달하기 위해 바이트 형식으로 인코딩
        var = var.encode("utf-8")
        arduino.write(var) # 아두이노의 바이트 형식으로 변환된 "1"을 보냄
        print("LED ON")
        time.sleep(1)
    elif var == '0':
        var = var.encode("utf-8")
        arduino.write(var) # 아두이노의 바이트 형식으로 변환된 "1"을 보냄
        print("LED OFF")
        time.sleep(1)
    else:
        break