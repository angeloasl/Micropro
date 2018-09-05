#define ledr 5               // led conectado ao pino 5
#define ledg 3
#define ledy 4
#define ledgp 6
#define ledrp 7
#define botao 8
volatile int x=1;
int Nc = 15625;
unsigned long time1;
unsigned long time2;
unsigned long time3;

void setup() {
   pinMode( ledr, OUTPUT );  // Pino 5 como saída 
   pinMode( ledg, OUTPUT );
   pinMode( ledy, OUTPUT );
   pinMode( ledgp, OUTPUT );
   pinMode( ledrp, OUTPUT );
   pinMode( botao, INPUT );
   Serial.begin(10126);
}

void loop() {
  time1 = millis();
  Serial.print("Tempo para envio desta mensagem:");
  time2 = millis();
  time3 = time2 - time1;
  Serial.println(time3);
}
