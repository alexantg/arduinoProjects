void setup()
{
Serial.begin(9600);
}
void loop()
{
int test = 1;
int verdi = 3, total = 4;
float resultat = 1.0;
 resultat = verdi/total;
 Serial.print("resultat = ");
 Serial.println(resultat);
 resultat = (float) verdi/total;
 Serial.print("resultat = ");
 Serial.println(resultat);
 test = verdi%total;
 
 Serial.print("test = ");
 Serial.println(test);

 test = total >> 1;
 Serial.print("test = ");
 Serial.println(test);

 test = total & 1;
 Serial.print("test = ");
 Serial.println(test);
 test = total & 4;
 Serial.print("test = ");
 Serial.println(test);
 test = total | 0;
 Serial.print("test = ");
 Serial.println(test);
 test = total ^ 4;
 Serial.print("test = ");
 Serial.println(test);

for(;;)
{ }
}
