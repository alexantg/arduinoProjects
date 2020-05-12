
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

  int angle=0;
 
  float area= 5.0;
  int servoValue= digitalRead(tempSensorPin);
  float voltageValue= (servoValue/1024) *area;
  float tempValue= (servoValue/1024.0) *150.0 - 50.0;

  Serial.print("Bitverdien til sensoren er: ");
  Serial.println(servoValue);
  Serial.print("Spenningen på utgangen til sensoren er: ");
  Serial.println(voltageValue);
  Serial.print("Temperaturen sensoren måler er: ");
  Serial.println(tempValue);

  //Styring av lufteluke//

  if(tempValue<20){
    angle=0;
    myServo.write(angle);
  }

  else if(tempValue>=50){
    angle=90;
    myServo.write(angle);
  }

  else if(tempValue>20 &&tempValue<50){
    angle= (tempValue-20)/30 *90;
    myServo.write(angle) //proposjonal med temperaturen
  }

  Serial.print("Vinkelen er: ");
  Serial.println(angle);
  
  delay(6000);
}

void stats(float temperature){
  int teller=0;
  int minutes=1439;

  static float tempSum= 0.0, maxTemp= -274.0, minTemp= 1000.0;
  float tempSnitt= 0.0;
  
  float tempArray[]= {0.0};
  tempArray[k]= temperature;
  tempSum +=temperature;
  k++;


  if(temperature>maxTemp){
    maxTemp= temperature;
  }
  
  if(temperature<minTemp){
    minTemp= temperature
  }

  if(teller==minutes){
    tempSnitt= tempSum/minutes;

    //Kjøre utskrifter her//

    teller= 0;
    tempSum= 0.0;
    maxTemp=-274.0;
    minTemp= 1000.0;
  }
   
}


 
