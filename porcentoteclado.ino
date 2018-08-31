#define led 5
#define _1s 62500  // PRSC em 256
#define _05s 31250-1 
#define temp ((duty*62500)/10)
byte duty;
void setup() {
   TCCR1A = 0; 
   TCCR1B  = ( 1 << CS12 );  // Prescaler em 256
   TCCR1B |= ( 1 << WGM12);  // Modo CTC
   OCR1A   = _1s; 
   OCR1B   = temp-1; 
   
   pinMode( led, OUTPUT );
   digitalWrite(led, HIGH); 
   TCNT1 = 0; 
   TIMSK1 = ( 1 << OCIE1A ) | 
            ( 1 << OCIE1B ) ;  // Habilita interrupções de comparação
  Serial.begin(9600);
}

ISR( TIMER1_COMPA_vect ){
   digitalWrite(led, !digitalRead(led) ); 
}

ISR( TIMER1_COMPB_vect ){
   digitalWrite(led, !digitalRead(led) ); 
}

void loop() {
  delay(1000); 
  Serial.println(OCR1B);
  Serial.println(duty);
  if (Serial.available())
  {
	 duty = Serial.read();
     duty=duty-48;
  	if ((duty<10) && (duty>0))
  	{
  	OCR1B=temp-1;
  	}
  }
}
