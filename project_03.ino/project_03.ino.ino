
const int sensorPin= A0;
const float baselineTemp= 19.0;


void setup() {
  
  Serial.begin(9600); //lager en connection mellom arduino og pc
                      //argumentet anngir hastigheten på connection//


  for( int pinNumber=2; pinNumber<5; pinNumber++){

      pinMode( pinNumber,OUTPUT);
      digitalWrite(pinNumber, LOW);
   
  }
  
  

}

void loop() {

    int sensorVal= analogRead(sensorPin); // leser verdien på pin A0
    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);

    float voltage= (sensorVal/1024.0)  * 5.0; //konverterer verdien på ADC inngangen tilbake til en voltverdi//
    Serial.print(" , Volts: ");
    Serial.print(voltage);

    Serial.print(" , degrees C: ");
    float temperature= (voltage- .5) *100;
    Serial.println(temperature);

    //hvis temperaturen er mindre enn baseline skru av alle LED-dioder//
    if(temperature<baselineTemp){
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    }

    //hvis temperaturen er 2 grader mer enn baseline og samtidig 4 grader mindre enn baseline//
    else if(temperature >= baselineTemp+2 && temperature<baselineTemp+4){
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    }

       else if(temperature >= baselineTemp+4 && temperature<baselineTemp+6){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
    }

       else if(temperature >= baselineTemp+6){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
    }

    delay(1);
    
}
