#define TRIG 9
#define ECHO 8

void setup() {
  Serial.begin(9600);
  pinMode(TRIH, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  float duration = pulseIn(ECHO, HIGH);
  float distance = ((34000*duration)/1000000)/2;

  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  if (distance < 15) {

  }
}
