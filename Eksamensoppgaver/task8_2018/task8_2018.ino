
 #include <Servo.h>
 Servo myServo;

  const int tempSensorPin=A0;
  const int servoPin= 6;


void setup() {

  Serial.begin(9600);
  
  pinMode(tempSensorPin, INPUT);
  pinMode(servoPin, OUTPUT);

  myServo.attach(servoPin);

}

void loop() {

  int servoValue= digitalRead(tempSensorPin);
  

}
