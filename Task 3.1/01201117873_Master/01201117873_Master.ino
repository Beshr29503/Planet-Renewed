#include <Wire.h>
//Setting LED pin which is 11
#define LED 11
//Declare variable to recieve status of Push Buttons
int buttonStatus;

void setup() {
  //Initialize Serial Communication with the monitor
  Serial.begin(9600);
  //For Master, Initialize communication
  Wire.begin();
  //Setting LED as output
  pinMode(LED, OUTPUT);
}

void loop() {
  //Request Data from Address 10 of size 2 Bytes ( Size of int )
  Wire.requestFrom(10, 2);
  //Check if there is available data in the reciever buffer
  if (Wire.available()) {
    //Read the data and store it in buttonStatus
    buttonStatus = Wire.read();
  }
  //Case B1=0 && B2=0
  if (buttonStatus == 1) {
    analogWrite(LED, 0);
    Serial.println("No Message");
  }
  //Case B1=1 && B2=0
  else if (buttonStatus == 2) {
    analogWrite(LED, 127);
    Serial.println("Vector Focused");
  }
  //Case B1=0 && B2=1
  else if (buttonStatus == 3) {
    analogWrite(LED, 191);
    Serial.println("Vector Distracted");
  }
  //Case B1=1 && B2=1
  else if (buttonStatus == 4) {
    analogWrite(LED, 255);
    Serial.println("Glitch");
  }
}