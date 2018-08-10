byte ledAceso = 6; /* Inicia acendendo o led 6 */
byte sentido = HIGH; /* valor de "sentido" define direção de rotação*/
volatile int tempo=100;
volatile int contador=0;


void setup() {
  for(byte i=6; i <= 10; i++)
  {
     pinMode(i, OUTPUT);
  } 
  	pinMode(2, INPUT);
    Serial.begin(9600);
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
  if (contador==0) 
  {
    Serial.println(contador);
    contador= contador +1;
  }
  else
  {
    Serial.println(contador);
    delay(1000);
    contador= contador +1;
  	contador= contador %10;
  }

}
