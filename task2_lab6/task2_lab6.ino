

    const int redPin=9;
    const int yellowPin=10;
    const int greenPin= 11;
    const int interruptPin= 2;

    int activePin=redPin;
  
      void setup() {

        pinMode(redPin, OUTPUT);
        pinMode(yellowPin, OUTPUT);
        pinMode(greenPin, OUTPUT);
        pinMode(interruptPin, INPUT);

        attachInterrupt(digitalPinToInterrupt(interruptPin),shiftActive,CHANGE);
      }

      void loop() {

       for(int i=0; i<=255; i++){
          analogWrite(activePin, i);
          delay(15);
        }

        for(int j=255; j>=0; j--){
          analogWrite(activePin, j);
          delay(15);
        }

      }


    void resetPins(){  
        digitalWrite(redPin,LOW); 
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin,LOW);

    }

      

      void shiftActive(){

         static unsigned long lastInterruptedTime = 0;
         unsigned long interrupt_time = millis();

          if (interrupt_time - lastInterruptedTime > 1000){
        
           if(activePin==redPin){
             activePin= greenPin;
           }
           else if(activePin==greenPin){
              activePin=yellowPin;
           }

           else if(activePin==yellowPin){
                activePin =redPin;
           }       
        }
        resetPins();
        lastInterruptedTime  = interrupt_time;
        }
   
      
      
