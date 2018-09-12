#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define led 5
#define _1s 62500  // PRSC em 256
volatile int contm=2;
volatile int conts=59;
byte duty;
#define ledb 8
#define ledy 9
#define buzzer 10
int portasOut[]   = {8,9,10};
int portasIn[]    = {};
const int nroOuts = 3;
const int nroIns  = 0;

void setup() 
{
   TCCR1A = 0; 
   TCCR1B  = ( 1 << CS12 );  // Prescaler em 256
   TCCR1B |= ( 1 << WGM12);  // Modo CTC
   OCR1A   = _1s; 
   OCR1B   = _1s-1; 
   TCNT1 = 0; 
   TIMSK1 = ( 1 << OCIE1A ) | 
            ( 1 << OCIE1B ) ;  // Habilita interrupções de comparação
  
  Serial.begin(9600); 

  for (int i=0; i < nroIns; i++)
  pinMode(portasIn[i], INPUT);
}

ISR( TIMER1_COMPA_vect ){
  conts = conts-1; 
}

ISR( TIMER1_COMPB_vect ){
}

void updateDisplay() {
  if(contm>-1)
  {
   lcd.setCursor(0,0);
   lcd.print("Tempo: ");
   lcd.print(contm);
   lcd.print(":");
   lcd.print(conts);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("BOOOOOOOOOOM");
  }
}

void loop() { 
  if(conts==0)
  {
  contm=contm-1;
  conts=59;
  }  
  updateDisplay();  
  Serial.println(OCR1B);
  Serial.println(conts);
  delay(1000); 
}
