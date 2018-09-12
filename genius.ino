int tons[5] = { 310, 415, 209, 252, 42 };
int jogadas[20];
int now = 0;
int ate = 0;
int buzzer = 12 ;
int pinosLeds[] = { 11, 6, 0, 3 };
int pinosBotoes[] = { 1, 2, 10, 5 };
int press = 0;
int gameover = false;
int portasOut[]   = {0,3,6,11,12};
int portasIn[]    = {1,2,5,10};
const int nroOuts = 5;
const int nroIns  = 4;

void setup() 
{ 
for (int p=0; p < nroOuts; p++)

pinMode(portasOut[p], OUTPUT);

for (int i=0; i < nroIns; i++)

pinMode(portasIn[i], INPUT);
  
randomSeed(analogRead(0));
}
void loop() {
  if (gameover) 
  {
    int jogadas[20];
    now = 0;
    ate = 0;
    gameover = false;
  }
  proximaRodada();
  reproduzirSequencia();
  aguardarJogador();
  delay(1000);
}

void proximaRodada() 
{
  int rnum = random(0, 4);
  jogadas[now++] = rnum;
}

void reproduzirSequencia() {
  for (int i = 0; i < now; i++) {
    tone(12, tons[jogadas[i]]);
    digitalWrite(pinosLeds[jogadas[i]], HIGH);
    delay(500);
    noTone(buzzer);
    digitalWrite(pinosLeds[jogadas[i]], LOW);
    delay(100);
  }
  noTone(buzzer);
}

void aguardarJogador() {
  for (int i = 0; i < now; i++) {
    aguardarJogada();
    verificarJogada();
 
    if (gameover) {
      break;
    }
 
    ate++;
  }
 
  ate = 0;
}

void aguardarJogada() {
  boolean jogada_efetuada = false;
  while (!jogada_efetuada) {
    for (int i = 0; i <= 3; i++) {
      if (digitalRead(pinosBotoes[i]) == HIGH) {
        
        press = i;
 
        tone(buzzer, tons[i]);
        digitalWrite(pinosLeds[i], HIGH);
        delay(300);
        digitalWrite(pinosLeds[i], LOW);
        noTone(buzzer);
 
        jogada_efetuada = true;
      }
    }
    delay(10);
  }
}

void verificarJogada() {
  if (jogadas[ate] != press) 
  {
    for (int i = 0; i <= 3; i++) 
    {
      tone(buzzer, tons[4]);
      digitalWrite(pinosLeds[i], HIGH);
      delay(200);
      digitalWrite(pinosLeds[i], LOW);
      noTone(buzzer);
    }
 
    tone(buzzer, tons[4]);
    for (int i = 0; i <= 3; i++) {
      digitalWrite(pinosLeds[0], HIGH);
      digitalWrite(pinosLeds[1], HIGH);
      digitalWrite(pinosLeds[2], HIGH);
      digitalWrite(pinosLeds[3], HIGH);
      delay(100);
      digitalWrite(pinosLeds[0], LOW);
      digitalWrite(pinosLeds[1], LOW);
      digitalWrite(pinosLeds[2], LOW);
      digitalWrite(pinosLeds[3], LOW);
      delay(100);
    }
    noTone(buzzer);
 
    gameover = true;
  }
}
