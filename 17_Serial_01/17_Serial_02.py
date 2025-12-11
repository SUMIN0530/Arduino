from flask import Flask, request, jsonify
from flask_cors import CORS
import serial, time
# import time

SERIAL_PORT = 'COM4'
BAUD = 9600

arduino = serial.Serial(SERIAL_PORT, BAUD, timeout=1)
time.sleep(2)

app = Flask(__name__)
CORS(app) # 다른 출처(파일/로컬 서버)에서 접근할 수 있도록 허용하는 코드
state = "off" 

@app.post("/led")

def led():
    global state
    data = request.get_json(force=True)
    desired = data.get("state") # state 값이 on | off 로 저장

    if desired == "on":
        arduino.write(b'1') # 인코딩 바이트로 보내기 간략화
        state = "on"
    elif desired == "off":
        arduino.write(b'0')
        state = "off"
    else:
        return jsonify({"전송" : False, "에러" : "state는 'on'이나 'off'만 가능합니다."}), 400
    
    # led라는 함수의 return문 
    return jsonify({"전송" : True, "state" : state})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000) # 옵션 요소 debug=True, use_reload=False, thread=False -> 에러로 제거