
  const int tempSensorPin= A0;
  const int levelSensorPin= A1;
  const int alarmPin= 2;
  const int enablePin= 4;
  const int speakerPin= 8;



  void setup() {

    Serial.begin(9600);

    pinMode(tempSensorPin, INPUT);
    pinMode(levelSensorPin, INPUT);
    pinMode(alarmPin, INPUT);
    pinMode(enablePin, INPUT);
    pinMode(speakerPin, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(alarmPin), alarm, RISING);

  }

  void loop() {

    int tempSensor= analogRead(tempSensorPin);
    int waterLevel= analogRead(levelSensorPin);
    int 
    Serial.println("Temperaturen er " + getTemp(tempSensor))
    
    

    delay(4000);

  }


  void alarm(){
    int stateOfSystem= analogRead(enablePin);

    if(stateOfSystem==LOW){
      noTone(speakerPin);
    }
    if(stateOfSystem==HIGH){
      gsmVarsel();
      tone(speakerPin, 1000, 300000); //300000 millisek tilsvarer 5 minutter//
    }
  }

  void gsmVarsel(){}

  float getTemp(int sensorBitValue){

    //området spenner seg slik//
    int area= 150;

    float temp= (sensorBitValue/1024)*150;

    return temp;
    
  }

  float getWaterLevel(float sensorBitValue){
     int area= 20;

     float waterLevel= (sensorBitValue/1024)*area;

     return waterLevel;
  }
