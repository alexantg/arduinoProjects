
const int speakerPin= 8;
const int photoLedPin=A0;
const int ledPin= 4;

int sensorLow=1023;
int sensorHigh=-1;

int photoRead;

void setup() {
  photoRead= analogRead(photoLedPin);
  unsigned long time= millis();

  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT)

  //loop runs for 5 seconds//
  while(time<5000){
    if(photoRead>sensorHigh){
        sensorHigh= photoRead;  
    }
    if(photoRead<sensorLow){
      sensorLow= photoRead;
    }
  }
  digitalWrite(ledPin, HIGH);
  
}

void loop() {
  photoRead= analogRead(photoLedPin);

  delay(20)
}

int skaler(){
  
}
