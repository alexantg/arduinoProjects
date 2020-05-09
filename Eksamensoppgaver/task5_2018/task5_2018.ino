void setup()
{
Serial.begin(9600);
}
void loop()
{
int antall = 42, verdi= 43;
char navn[5][20]={"Arne", "Monika","Fredrik","Veronika", "Ron"};
for (int i = 0; i <= 4 ; i++)
{
Serial.println(navn[i]);
Serial.println(strlen(navn[i]));
}
Serial.println(sizeof(int));
Serial.println(sizeof(float));
Serial.println(sizeof(navn[0]));
Serial.println(sizeof(navn));
strcat(navn[0]," og ");
strcat(navn[0],navn[1]);
Serial.println(navn[0]);
int k=0;
while ( navn[3][k] != '\x00')
{
Serial.println(navn[3][k]);
k++;
}
strcpy(navn[1],navn[4]);
Serial.println(navn[1]);
Serial.println( String (navn[2]) + " = " + String (antall));
Serial.println(" res = " + String (antall/verdi));
for(;;)
{}
}
