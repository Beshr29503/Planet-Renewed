//HC-SR04 ultrasonic sensor is not used as it has range limit of 4 metre and the room is 6mx5m
//UM-30 ultrasonic sensor is used as it has range limit of 6 metre 
// Setting Trigger Pin of Ultrasonic Sensors
#define trigpin1 7
#define trigpin2 2
#define trigpin3 8
#define trigpin4 12
// Setting Echo Pin of Ultrasonic Sensors
#define echopin1 6
#define echopin2 3
#define echopin3 9
#define echopin4 11

void setup() {
  //Initialize Serial Communication with the monitor
  Serial.begin(9600);
  //Setting Trigger Pin yforward as output
  pinMode(trigpin1, OUTPUT);
  //Setting Trigger Pin xright as output
  pinMode(trigpin2, OUTPUT);
  //Setting Trigger Pin ybackward as output
  pinMode(trigpin3, OUTPUT);
  //Setting Trigger Pin xleft as output
  pinMode(trigpin4, OUTPUT);
  //Setting Echo Pin yforward as input
  pinMode(echopin1, INPUT);
  //Setting Echo Pin xright as input
  pinMode(echopin2, INPUT);
  //Setting Echo Pin ybackward as input
  pinMode(echopin3, INPUT);
  //Setting Echo Pin xleft as input
  pinMode(echopin4, INPUT);
}

void loop() {
  //declare variables to store duration and distance in the x-direction
  long duration_xleft, xleft, duration_xright, xright;
  //obtaining distance in the xleft direction from ultrasonic 4
  digitalWrite(trigpin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin4, LOW);
  duration_xleft = pulseIn(echopin4, HIGH);
  xleft = dist_to_wall(duration_xleft);
  //obtaining distance in the xright direction from ultrasonic 2
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2, LOW);
  duration_xright = pulseIn(echopin2, HIGH);
  xright = dist_to_wall(duration_xright);
  //calculating x position of cookie
  long xerror, xaverage;
  if (xleft > xright)
    xerror = xleft - xright;
  else
    xerror = xright - xleft;
  if (xerror <= 0.1)
    xaverage = (xleft + xright) / 2.0;
  else
    xaverage = xleft;
  //declare variables to store duration and distance in the y-direction
  long duration_yforward, yforward, duration_ybackward, ybackward;
  //obtaining distance in the yforward direction from ultrasonic 1
  digitalWrite(trigpin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);
  duration_yforward = pulseIn(echopin1, HIGH);
  yforward = dist_to_wall(duration_yforward);
  //obtaining distance in the ybackward direction from ultrasonic 3
  digitalWrite(trigpin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin3, LOW);
  duration_ybackward = pulseIn(echopin3, HIGH);
  ybackward = dist_to_wall(duration_ybackward);
  //calculating y position of cookie
  long yerror, yaverage;
  if (yforward > ybackward)
    yerror = yforward - ybackward;
  else
    yerror = ybackward - yforward;
  if (yerror <= 0.1)
    yaverage = (yforward + ybackward) / 2.0;
  else
    yaverage = ybackward;
  //printing coordinates of cookie in the room
  Serial.print(xaverage);
  Serial.print(",");
  Serial.println(yaverage);
  delay(100);
}
//function to calculate distance from duration and speed which is 330m/s
long dist_to_wall(long duration) {
  duration = duration / 2.0;
  return 0.00033 * duration;
}
