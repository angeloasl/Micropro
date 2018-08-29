#define ledr 5               // led conectado ao pino 5
#define ledg 3
#define ledy 4
#define ledgp 6
#define ledrp 7
#define botao 8
volatile int x=1;
int Nc = 15625;

void setup() { 
   TCNT1= 0;   
   TCCR1A = 0;              // Limpa registrador que Arduino altera
   TCCR1B = ( 1 << CS12 );  // Prescaler em 256
   pinMode( ledr, OUTPUT );  // Pino 5 como saída 
   pinMode( ledg, OUTPUT );
   pinMode( ledy, OUTPUT );
   pinMode( ledgp, OUTPUT );
   pinMode( ledrp, OUTPUT );
   pinMode( botao, INPUT );   
   Serial.begin(9600);
}

void loop() {
  Serial.println(TCNT1);
  Serial.println(x);
  if(TCNT1 > 62499)           
  {
  digitalWrite(ledr, !digitalRead(ledr));
  TCNT1=0;
  }
  delay(10);// Truque para acelerar a simulação no TinkerCAD
}
