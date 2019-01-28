byte pins[] = {2, 3, 4, 5, 6, 7};
static int counter = 0;
int state;
bool runTimer = false;
static int buttonYes = HIGH;
bool freezeTime = false;
bool firstPressA0 = true;
bool firstPressA1 = true;
bool firstPressA2 = true;
void setup() {
  for(int i = 0; i < 6; i++) {
    pinMode(pins[i], OUTPUT);
  }
  /*for(int i=0; i<=2; i++){
    pinMode("A" + i, INPUT);
  }*/

    //  Config Timer:
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536) 1 sec = 15624; 0,5s = 7812
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
}

void loop() {
  if(digitalRead(A0) == LOW && firstPressA0){
    startButton();
    firstPressA0 = false;
  }
  else if (digitalRead(A0) == HIGH){
    firstPressA0 = true;
  }

  if(digitalRead(A1) == LOW && firstPressA1){
    takeTime();
    firstPressA1 = false;
  }
  else if (digitalRead(A1) == HIGH){
    firstPressA1 = true;
  }
  if(digitalRead(A2) == LOW && firstPressA2){
    resetTimer();
    firstPressA2 = false;
  }
  else if (digitalRead(A2) == HIGH){
    firstPressA2 = true;
  }
}

void startButton(){
  runTimer = !runTimer;
}

void takeTime(){
  String storedTime = String(counter, BIN);
  freezeTime = !freezeTime;
}

void resetTimer(){
  if(!runTimer){
    counter = 0;
    for(int i = 2; i < 8; i++)
    {
      digitalWrite(i, LOW);
    }
  }
}

ISR(TIMER1_COMPA_vect){
  if(runTimer){
    String binNumber = String(counter, BIN);
    int binLength = binNumber.length();
    for(int i = 0, x = 1; i < binLength; i++, x+=2) { 
      if(binNumber[i] == '0') state = LOW;
      if(binNumber[i] == '1') state = HIGH;
      if(!freezeTime){
        digitalWrite(pins[i] + binLength - x, state);
      } 
    }
    counter++;
    if(counter > 64){
      counter = 0;
      for(int i = 2; i < 8; i++)
        {
          digitalWrite(i, LOW);
        }
    }
  }
}

