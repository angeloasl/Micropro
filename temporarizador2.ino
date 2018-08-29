#define ledr 5               // led conectado ao pino 5
#define ledg 3
#define ledy 4
#define ledgp 6
#define ledrp 7
#define botao 8
volatile int x=1;
int Nc = 15625;

void setup() {
   OCR1A=Nc-1; 
   TCNT1= 0;   
   TCCR1A = 0;              // Limpa registrador que Arduino altera
   TCCR1B = ( 1 << CS12 );  // Prescaler em 256
   TIMSK1 |= (1 << TOIE1);  // enable timer overflow interrupt
   pinMode( ledr, OUTPUT );  // Pino 5 como saída 
   pinMode( ledg, OUTPUT );
   pinMode( ledy, OUTPUT );
   pinMode( ledgp, OUTPUT );
   pinMode( ledrp, OUTPUT );
   pinMode( botao, INPUT );
   interrupts();
   Serial.begin(9600);
}

ISR(TIMER1_OVF_vect)        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  TCNT1 = 15625;            // preload timer
  digitalWrite(ledr, !digitalRead(ledr));
}

void loop() {
  Serial.println(TCNT1);
  Serial.println(x);
 delay(10);// Truque para acelerar a simulação no TinkerCAD
}
