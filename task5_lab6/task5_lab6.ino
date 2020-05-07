

  const int ledOnePin= 2;
  const int ledTwoPin= 3;
  const int ledThreePin= 4;
  const int ledFourPin= 5;
  const int ledFivePin= 6;
  const int ledSixPin=7;
  const int ledSevenPin= 8;

  const int resetButtonPin= 10;
  const int randomButtonPin=11;

  int resetState=0;
  int randomState=0;
  int numberToPrint=0;
 
  void setup() {
    pinMode(ledOnePin, OUTPUT);
    pinMode(ledTwoPin, OUTPUT);
    pinMode(ledThreePin, OUTPUT);
    pinMode(ledFourPin, OUTPUT);
    pinMode(ledFivePin, OUTPUT);
    pinMode(ledSixPin, OUTPUT);
    pinMode(ledSevenPin, OUTPUT);

    pinMode(resetButtonPin, INPUT);
    pinMode(randomButtonPin, INPUT);

    Serial.begin(9600);
    
  }

  void loop() {

    randomState= digitalRead(randomButtonPin);
    resetState= digitalRead(resetButtonPin);

    if(randomState==HIGH){
      resetLeds();
      printRandom();
    }

    if(resetState==HIGH){
        resetLeds();
    }
     
    
  }

  void printRandom(){

    numberToPrint= random(1,7);

    if(numberToPrint==1){
      digitalWrite(ledOnePin, HIGH);
    }
    else if(numberToPrint==2){
      digitalWrite(ledOnePin, HIGH);
      digitalWrite(ledFourPin, HIGH);
    }
    else if(numberToPrint==3){
      digitalWrite(ledOnePin, HIGH);
      digitalWrite(ledFourPin, HIGH);
      digitalWrite(ledSevenPin, HIGH);  
      }

    else if(numberToPrint==4){
      digitalWrite(ledOnePin, HIGH);
      digitalWrite(ledFourPin, HIGH);
      digitalWrite(ledThreePin, HIGH);
      digitalWrite(ledSixPin, HIGH);
      
    }
    else if(numberToPrint==5){
      digitalWrite(ledOnePin, HIGH);
      digitalWrite(ledFourPin, HIGH);
      digitalWrite(ledThreePin, HIGH);
      digitalWrite(ledSixPin, HIGH);
      digitalWrite(ledSevenPin, HIGH); 
    }

    else if(numberToPrint==6){
      digitalWrite(ledOnePin, HIGH);
      digitalWrite(ledTwoPin, HIGH);
      digitalWrite(ledThreePin, HIGH);
      digitalWrite(ledFourPin, HIGH);
      digitalWrite(ledFivePin, HIGH);
      digitalWrite(ledSixPin, HIGH);
    }
    
  }
  

  void resetLeds(){
    digitalWrite(ledOnePin, LOW);
    digitalWrite(ledTwoPin, LOW);
    digitalWrite(ledThreePin, LOW);
    digitalWrite(ledFourPin, LOW);
    digitalWrite(ledFivePin, LOW);
    digitalWrite(ledSixPin, LOW);
    digitalWrite(ledSevenPin, LOW);  
  }
