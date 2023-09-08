# Precise Self-Localizing
---
## Hardware
1. Arduino Board
2. IMU sensor ( MPU6050 )
## Hardware Setup
1. Connect Arduino Board to the MPU6050 using the I2C communication protocol.
2. Connect MPU6050 specificed pins to VCC and GND.
---
## Software 
### Dependencies
- Wire.h library to implement I2C communication protocol between Arduino and MPU6050.
```
#include <Wire.h>
```
### Pin Definition
- `IMU_ADDRESS`: Address of the MPU6050.
- `PWR_MGMT_1` , `GYRO_CONFIG`, `ACCEL_CONFIG`, `GYR0_ZOUT_H`: Register addresses for configuring the MPU6050.
```
#define IMU_ADDRESS 0x68
#define PWR_MGMT_1  0x6b
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1c
#define GYRO_ZOUT_H 0x47
```
### Variables
- `yaw_angle_prev`: stores value of Yaw Angle retrieved from register in degrees per second.
- `yaw_angle_new`: stores value of Yaw Angle in degrees.
- `prev_millis`, `current_millis`: time variables.
```
// yaw_angle_prev variable stores value of Yaw Angle retrieved from register in degrees per second
int16_t yaw_angle_prev = 0;
// yaw_angle_new variable stores value of Yaw Angle in degrees
long yaw_angle_new = 0;
// Time variables
long prev_millis = 0;
long current_millis = millis();
```
### Functions
- `MPU_INIT()`: Initializes the MPU6050 by configuring the power management register.
```
void MPU_init()
{
  // Activate the MPU6050
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
}
```
- `MPU_GyroConfig()`: Configures the gyroscope of the MPU6050.
```
void MPU_GyroCONFIG()
{
  // Configurate the Gyroscope
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_CONFIG);
  // set full-scale range = +- 2000 deg/second
  Wire.write(0x18);
  Wire.endTransmission();
}
```
- `MPU_readGyro_Z()`: Reads gyroscope data along the z-axis from the MPU6050 and converts it to degrees per second.
```
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
```
### Setup
- Initializes the Wire.h Library.
- Initializes Serial Communication.
- Configures the MPU6050.
```
void setup() {
  Wire.begin();

  Serial.begin(9600);

  MPU_init();
  MPU_GyroCONFIG();
}
```
### Loop
- Updates the time variables.
- Call `MPU_readGyro_Z` to update `yaw_angle_prev` value in degrees per second.
- Multiply `yaw_angle_prev` by change in time to obtain Yaw Angle in degrees.
- Update `yaw_angle_new` and increment it by `yaw_angle_prev` to perform integration.
- Display the Yaw angle on the Serial Monitor using `Serial.print` and `Serial.println`.
- Apply Delay by 100 milliseconds before repeating the loop.
```
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
```
---
# Question
If sensor is surrounded by a noisy environment `Low Pass Filter` should be used, according to datasheet, sensor supports I2C communication up to 400 KHz so the recommended cutoff frequency is `400 / sqrt(2) = 282.8 KHz`.
