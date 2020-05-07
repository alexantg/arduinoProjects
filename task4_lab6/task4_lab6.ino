

  const int C=260;
  const int D= 292;
  const int E= 328;
  const int F=348;
  const int G =392;
  const int A= 440;
  const int H=492;
  const int c=520;

  int speakerPin=12;
  int currentDuration=0;
  int sizeOfArray=0;

  int melodi[22] = {C,D,E,F,G,G,A,A,A,A,G,F,F,F,F,E,E,D,D,D,D,C};
  int duration[22] = {1,1,1,1,2,2,1,1,1,1,4,1,1,1,1,2,2,1,1,1,1,4};

  void setup() {

     Serial.begin(9600);
     
  }
  
  void loop() {

    sizeOfArray= (sizeof(melodi)/ sizeof(melodi[0]));
    
    for(int i=0; i<sizeOfArray; i++){
      currentDuration= duration[i]*500;
      Serial.println(melodi[i]);
      tone(speakerPin, melodi[i], currentDuration);
      delay(currentDuration+10);
      
    }
    
  }
