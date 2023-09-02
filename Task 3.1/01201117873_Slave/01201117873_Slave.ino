#include <Wire.h>
//Setting Push Button "B1" pin which is pin 12
#define B1 12
//Setting Push Button "B2" pin which is pin 7
#define B2 7
//declare variables to store readings of push buttons
int myB1;
int myB2;
// declare the function called upon request from master
void sendButtons();

void setup() {
  //Setting Push Button "B1" as input pullup to ignore noise
  pinMode(B1, INPUT_PULLUP);
  //Setting Push Button "B2" as Input pullup to ignore noise
  pinMode(B2, INPUT_PULLUP);
  //For Slave, Initialize for communication
  Wire.begin(10);
  Wire.onRequest(sendButtons);
}

void loop() {
  //Read the Push Buttons Values
  myB1 = digitalRead(B1);
  myB2 = digitalRead(B2);
}

void sendButtons() {
  //Case B1=0 && B2=0
  if (myB1 == 1 && myB2 == 1)
    Wire.write(1);
  //Case B1=1 && B2=0
  else if (myB1 == 0 && myB2 == 1)
    Wire.write(2);
  //Case B1=0 && B2=1
  else if (myB1 == 1 && myB2 == 0)
    Wire.write(3);
  //Case B1=1 && B2=1
  else if (myB1 == 0 && myB2 == 0)
    Wire.write(4);
}
