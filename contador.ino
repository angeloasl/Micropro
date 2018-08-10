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
    attachInterrupt(digitalPinToInterrupt(2), switchtempo , RISING ); 
  	attachInterrupt(digitalPinToInterrupt(3), switchordem , RISING ); 
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
  digitalWrite(ledAceso,HIGH);   
  delay(tempo); 
  contador= contador + 1;
  contador= contador % 10;
  delay(1000);
  Serial.println(contador);
}

void switchtempo(){
  if (tempo==100)
  {
  	tempo=500;
  	contador=0;
  }
  else
  {
    tempo=100;
    contador=0;
  }
}

void switchordem()
{
  sentido=!sentido;
  contador=0; 
}
