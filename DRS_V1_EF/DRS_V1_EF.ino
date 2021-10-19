#include <Servo.h>

int pos = 0;
int S = 0;
const int numS = 10;
int avrgArrS[numS];
int avrgS = 0;
Servo myServo;
void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  myServo.attach(9);
  for (int x = 0; x < numS; x++) {
    avrgArrS[x] = 0;
  }
  myServo.write(0);
}

void loop() {
  itterate();

  int buttonState = digitalRead(7);
  //Serial.println(buttonState);
  if(buttonState==0)
  {
      myServo.write(100);
      while(800<avrgS || avrgS<200)
      {
          itterate();
          delay(50);
      }
      delay(50);
  }
  else if(800<avrgS || avrgS<200)
  {
    myServo.write(100);
    while(800<avrgS || avrgS<200)
      {
          itterate();
          delay(50);
      }  
  }
  else
  {
    myServo.write(0);
    delay(50);
  }
}


void itterate() {
  S = analogRead(A0);
  avrgS = 0;
  for (int x = 0; x < (numS - 1); x++) {
    avrgArrS[x + 1] = avrgArrS[x];
    avrgS += avrgArrS[x + 1];
  }

  avrgArrS[0] = S;
  avrgS += avrgArrS[0];
  avrgS /= numS;
  Serial.println(avrgS);
}

 
