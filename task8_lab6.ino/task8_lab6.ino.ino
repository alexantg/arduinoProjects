    int sensorOneValue;
    int sensorTwoValue;
    int sensorThreeValue;

    float temperatureOne; 
    float temperatureTwo;
    float temperatureThree;
    
    float averageTemp;
    float voltagePerDegree;


  void setup() {
    voltagePerDegree= 5.0/300.0;
    Serial.begin(9600);
  }

  void loop() {

    sensorOneValue=analogRead(simulateTemp(150));
    sensorTwoValue= analogRead(simulateTemp(5));
    sensorThreeValue= analogRead(simulateTemp(10));

    temperatureOne= checkTemp(sensorOneValue);
    temperatureTwo= checkTemp(sensorTwoValue); 
    temperatureThree= checkTemp(sensorThreeValue);

    compareTemp(temperatureOne, temperatureTwo, temperatureThree);

    for(;;){}
    delay(2000);
  }

  float simulateTemp(float value){
    //finner økningen i antall grader fra 0
    float degreesFromZero= value+ 100;
    //finner antall volt per grad//
   
    return degreesFromZero * voltagePerDegree; 
  }

  float checkTemp(int sensorValue){
      float voltagePerBit= 5.0/1023;
      float currentVoltage= voltagePerBit* sensorValue;
      float degreesFromZero= currentVoltage/voltagePerDegree;

      float finalTemp;
      
      if(degreesFromZero>0){
         finalTemp=degreesFromZero-100;
      }
      if(degreesFromZero<0){
        finalTemp= 0 -(degreesFromZero-100);
      }

      return finalTemp;
  }

  void compareTemp(float temperatureOne, float temperatureTwo,float temperatureThree) {
     averageTemp= (temperatureOne+ temperatureTwo+ temperatureThree)/3;
     
    if((temperatureOne-temperatureTwo)> 0.6 || (temperatureOne-temperatureThree)>0.6 || (temperatureTwo- temperatureThree)>0.6){
      Serial.println("En eller flere av sensorene er utenfor spesifikasjon. Må undersøkes");
    }
    else{
      Serial.println("Sensorene er OK");
      Serial.print("Gjennomsnittstemperatur:" );
      Serial.println(averageTemp);
    }
  }

  
