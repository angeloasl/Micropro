
#define ledr 5               // led conectado ao pino 5
#define ledg 3
#define ledy 4
volatile int x=1;

void setup() {
   TCNT1 = 0;   
   TCCR1A = 0;              // Limpa registrador que Arduino altera
   TCCR1B = ( 1 << CS12 );  // Prescaler em 256
   pinMode( ledr, OUTPUT );  // Pino 5 como saída 
   pinMode( ledg, OUTPUT );
   pinMode( ledy, OUTPUT );
   Serial.begin(9600);
}

void loop() {
  Serial.println(TCNT1);
  Serial.println(x);
  x=x+1;
  if (( TCNT1 > 31250 )&&(x>0)&&(x<5))
  {
     digitalWrite(ledg, HIGH);
  	 digitalWrite(ledr, LOW);
     digitalWrite(ledy, LOW);
  }
   if((x>5)&&(x<8))
  {
 	 digitalWrite(ledr, LOW); 
 	 digitalWrite(ledy, HIGH);
     digitalWrite(ledg, LOW);
  }
	if((x>8)&&(x<13))
  {
 	 digitalWrite(ledg, LOW); 
 	 digitalWrite(ledr, HIGH);
     digitalWrite(ledy, LOW);
  }
     if((x>13))
       {
        x=0;
       }

   if ( TCNT1 > 62500 )      TCNT1 = 0; 
   delay(1000);  // Truque para acelerar a simulação no TinkerCAD
}
