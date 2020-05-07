

 #include <Servo.h>
 Servo myServo;
 int const potPin= A0;
 long potVal;
 int angle;

   void setup() {

    myServo.attach(9);
    Serial.begin(9600);
   
   }

   void loop() {

     potVal=analogRead(potPin); 
     Serial.print("potVal: ");
     Serial.print(potVal);

     angle= scale(potVal, 0,1023, 0, 179);
     Serial.print(" , angle: ");
     Serial.println(angle);

     myServo.write(angle);
     delay(15);
    

   }


  long scale(long potVal, long scaleLow, long scaleHigh, 
                long angleLow, long angleHigh){

    int value= (potVal-scaleLow) *(angleHigh- angleLow) /
                  (scaleHigh-scaleLow) + angleLow;

    return value;
    
  }
