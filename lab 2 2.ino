byte ledAceso = 6; /* Inicia acendendo o led 6 */
byte sentido = HIGH; /* valor de "sentido" define direção de rotação*/
volatile int tempo=100;
int a=0;

void setup() {
  for(byte i=6; i <= 10; i++)
  {
     pinMode(i, OUTPUT);
  } 
  PCMSK2 = (1<<PCINT19);
  PCICR = (1<<PCIE2);
 }

void loop() {
  digitalWrite(ledAceso, LOW); 
  if (sentido == HIGH){
     if(ledAceso == 6){   ledAceso = 10;  } 
     else             {   ledAceso--;     }
  } 
  else{
     if(ledAceso == 10){  ledAceso = 6;   }
     else              {  ledAceso++;     }
  }
  digitalWrite(ledAceso,HIGH); 
  delay(tempo); 
}

ISR(PCINT2_vect)
{
  a=(a+1)%2;
  if (a)
  sentido=!sentido;
 /* if (tempo==100)
  {
  	tempo=500;
  }
  else
  {
    tempo=100;
  }*/
}
