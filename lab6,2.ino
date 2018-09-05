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
char mensagem[] = "Bom dia"; 
byte i = 0; 

void setup() 
{
   pinMode( ledr, OUTPUT );  // Pino 5 como saída 
   pinMode( ledg, OUTPUT );
   pinMode( ledy, OUTPUT );
   pinMode( ledgp, OUTPUT );
   pinMode( ledrp, OUTPUT );
   pinMode( botao, INPUT );
   Serial.begin(9600);
}

void loop()
{
  if(mensagem[i]!= NULL){
   UDR0 = mensagem[i]; 
   i++; 
  }else{
   UDR0 = 0x0A;
   i=0;}
   delay(1);                        // Importante! Aguarda término do envio do caractere
}
