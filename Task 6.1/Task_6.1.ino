#include <Wire.h>
#define IMU_ADDRESS 0x68
#define PWR_MGMT_1  0x6b
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1c
#define GYRO_ZOUT_H 0x47

// yaw_angle_prev variable stores value of Yaw Angle retrieved from register in degrees per second
int16_t yaw_angle_prev = 0;
// yaw_angle_new variable stores value of Yaw Angle in degrees
long yaw_angle_new = 0;
// Time variables
long prev_millis = 0;
long current_millis = millis();

void MPU_init()
{
  // Activate the MPU6050
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
}

void MPU_GyroCONFIG()
{
  // Configurate the Gyroscope
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_CONFIG);
  // set full-scale range = +- 2000 deg/second
  Wire.write(0x18);
  Wire.endTransmission();
}

void MPU_readGyro_Z()
{
  // Retrieving the Yaw Angle from register in degrees per second
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_ADDRESS, 2);

  while(Wire.available() < 2);
  yaw_angle_prev = Wire.read() << 8 | Wire.read();
}

void setup() {
  Wire.begin();

  Serial.begin(9600);

  MPU_init();
  MPU_GyroCONFIG();
}

void loop() {
  // Updating Time
  prev_millis = current_millis;
  current_millis = millis();

  // Calling Function To Update yaw_angle_prev Value
  MPU_readGyro_Z();

  // Multiplying yaw_angle_prev with change in time to obtain Yaw Angle in degress (Divided by 1000 to convert seconds to milliseconds)
  yaw_angle_prev = (yaw_angle_prev * (current_millis - prev_millis)) / 1000;
  // Update yaw_angle_new and increment it by Yaw Angle in degrees (integration)
  yaw_angle_new = yaw_angle_new + yaw_angle_prev;
  // Display Yaw Angle in degrees on serial monitor
  Serial.print("Yaw: ");
  Serial.print(yaw_angle_new);
  Serial.println(" degrees");

  delay(100);
}
