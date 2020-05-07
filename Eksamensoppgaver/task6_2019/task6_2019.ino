#define TEST 1
void setup()
{
Serial.begin(9600);
Serial.print("Arduino Test har startet: ");
Serial.println(TEST);
}
void loop(){
  
  int resultat = 0, antall = 4, bokser = 8;
  float verdi = 0.0;
  char tekst1[30] = "Sommer";
  char tekst2[30] = "2019";
  
  resultat = antall/bokser;
  Serial.println("resultat = " + (String) resultat);
  resultat = antall%bokser;
  Serial.println("resultat = " + (String) resultat);
  verdi = antall/(float) bokser;
  Serial.println("verdi = " + (String) verdi);
  strcat(tekst1," ");
  strcat(tekst1,tekst2);
  Serial.println(tekst1);
  Serial.println(strlen(tekst1));
  funksjonTest(antall, &bokser);
  Serial.println("bokser = " + (String) bokser);

  while(1)
  { }
}

void funksjonTest(int ant, int *pkr){
  
  int res = 0;
  res = ant+(*pkr);
  Serial.println("res = " + (String) res);
  *pkr = 42;
  
}
