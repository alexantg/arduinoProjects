
const int roedBilPin=3;
const int gulBilPin=4;
const int groennBilPin=5;
const int roedFotgjengerPin= 6;
const int groennFotgjengerPin= 7;
const int startPin= 8;
const int stoppPin= 9;

const int overHekken= 2;

int extendedTime=0;


void setup() {

  pinMode(roedBilPin, OUTPUT);
  pinMode(gulBilPin, OUTPUT);
  pinMode(groennBilPin, OUTPUT);
  pinMode(roedFotgjengerPin, OUTPUT);
  pinMode(groennFotgjengerPin, OUTPUT);

  pinMode(startPin, INPUT);
  pinMode(stoppPin, INPUT);
  pinMode(overHekken, INPUT);

  attachInterrupt(digitalPinToInterrupt(overHekken), fotgjenger, RISING);
    
}

void loop() {
  
  int startState= analogRead(startPin);
  int stopState= analogRead(stoppPin);

  if(startState==0 || stopState==1 ){
    yellowBlink();
    digitalWrite(roedFotgjengerPin, LOW);
    digitalWrite(groennFotgjengerPin, LOW);
  }

  if(startState==1){
    digitalWrite(roedBilPin, HIGH);
    delay(10000);
    digitalWrite(gulBilPin, HIGH);
    delay(4000);
    digitalWrite(roedBilPin, LOW);
    digitalWrite(gulBilPin, LOW);
    digitalWrite(groennBilPin, HIGH);
    delay(10000);

   
  }
 
}

//skille ut de overnevnte i egne funksjoner//

void fotgjenger(){
  extendedTime= 1;
}




void yellowBlink(){
    digitalWrite(gulBilPin, HIGH);
    delay(1000);
    digitalWrite(gulBilPin,LOW);
    delay(1000);
}
