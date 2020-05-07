
int switchState=0;

void setup() {
  //LED-dioder som er utganger//
  pinMode(3,OUTPUT); 
  pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT);
  
  pinMode(2,INPUT); //knappen er en inngang//

}

void loop() {

  switchState= digitalRead(2);

  //hvis knappen ikke blir trykket på//
  if(switchState==LOW){
    
    digitalWrite(3, HIGH); //grønn LED skrur seg på//
    digitalWrite(4, LOW); //en rød LED er av//
    digitalWrite(5, LOW); //andre røde LED er av//
  }

  //knappen blir trykket på//
  else{
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(50); //anngir en stopp i programmet i ms//

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(50);
    
  }

}
