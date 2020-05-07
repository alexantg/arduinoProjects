void setup()
{
Serial.begin(9600);
}
void loop()
{
char bokstav = 'A';
char *pkrBokstav = &bokstav;
char fruktTyper[5][20] = {"Eple", "Banan", "Drue", "Mango", "Sitron"};
char *pkrFrukt = "Ananas";
Serial.println(*pkrBokstav);
*pkrBokstav = *pkrBokstav + 1;
Serial.println(*pkrBokstav);
Serial.println(fruktTyper[3]);
Serial.println(strlen(fruktTyper[3]));
strcpy(fruktTyper[4], pkrFrukt);
Serial.println(fruktTyper[4]);
strcat(fruktTyper[1]," og ");
strcat(fruktTyper[1],fruktTyper[4]);
Serial.println(fruktTyper[1]);
fruktFunksjon ( fruktTyper );
Serial.println(fruktTyper[2]);

for (;;)
{}
}
void fruktFunksjon ( char frukter[5][20] )
{
 strcpy(frukter[2], "Plomme");
 Serial.println(frukter[2]);
}
