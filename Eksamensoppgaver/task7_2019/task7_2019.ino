
const int speakerPin= 8;
const int photoLedPin=A0;
const int ledPin= 4;

int sensorLow=1023;
int sensorHigh=-1;

int lowFreq=100;
int highFreq= 4000;

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
  int freq=0;
  photoRead= analogRead(photoLedPin);

  freq= skaler(skaler(photoRead))

  tone(speakerPin, freq, 20);
  
  delay(20)
}

int skaler(int sensorValue){
  int frequency=0;

  frequency=(float (sensorValue-sensorLow)/(sensorHigh-sensorLow))(highFreq-lowFreq) + lowFreq;

  return frequency;
}
