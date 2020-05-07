

 #include <TimerOne.h> 
 const int speakerPin= 12;

  const int C=260;
  const int D= 292;
  const int E= 328;
  const int F=348;
  const int G =392;
  const int A= 440;
  const int H=492;
  const int c=520;

  int onTone;
  int onName; 

  //definerer en array med toner//
  int tones[]= {C,D,E,F,G,A,H,c};
  char names[]= {'C', 'D', 'E', 'F', 'G', 'A', 'H', 'c'};
  
    void setup() {  
      Timer1.initialize(400000);
      Timer1.attachInterrupt(changeTone);
      int onTone=0;
      Serial.begin(9600);
        
    } 
  
    void loop() {   
     onName=onTone-1; 
     Serial.println(names[onName]);
     Serial.println(); 
     onName++;
     delay(400);
     
    }

     void changeTone(){ 
      
     int elements= (sizeof(tones)/ sizeof(tones[0]))-1;
    
     if(onTone>elements){
      onTone=0;
     }
        
      tone(speakerPin, tones[onTone],390);
      onTone++;
      
    }



    
