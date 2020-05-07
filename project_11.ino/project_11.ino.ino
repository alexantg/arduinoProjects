
  #include <LiquidCrystal.h>
  LiquidCrystal lcd (12,11,5,4,3,2);

  const int switchPin = 6;
  int switchState = 0;

    void setup() {

        Serial.begin(9600);
        lcd.begin(16,2);
        pinMode(switchPin, INPUT);
        
      }

          void loop() {

          switchState= digitalRead(switchPin);
          Serial.println(switchState);
          
          if(switchState==HIGH){        
             printSymbol();
         }
      }


      void printSymbol(){

            //knappen må trykkes på
            //ytterste loop styrer rad, mens innserste styrer kolonne//
              for(int j=0; j<2; j++){
                   for(int i=0; i<=15; i++){
                      if(digitalRead(switchPin)==LOW){
                        break;
                      }
                      lcd.setCursor(i,j);
                      lcd.print("#");
                      delay(250);
                      lcd.clear();
                  }
               
                }
            }
      
        
      
      


              
