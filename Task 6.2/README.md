# Every Step Matter Documentation
---
# Counting Train of Impulse from A and B Signals
### Defining Digital Pins A and B
```
#define Pin_A 2 // digital pin A of Encoder
#define Pin_B 3 // digital pin B of Encoder
```
### Defining count variable
```
// variable to store number of counts from the train of impulse from pin A and pin B signals
int count = 0;
```
### Interrupt Service Routines
The code defines two interrupt service routines that are executed due to changes in the encoder pins:
```
void isr_count_A() {
  // count increment if motion is clockwise and decrement if motion is anticlockwise
  if (digitalRead(Pin_A) != digitalRead(Pin_B))
    count++;
  else
    count--;
}

void isr_count_B() {
  // count increment if motion is clockwise and decrement if motion is anticlockwise
  if (digitalRead(Pin_A) == digitalRead(Pin_B))
    count++;
  else
    count--;
}
```
Each ISR increment the count variable if the encoder motion is clockwise and decrement the count variable if the encoder motion is anticlockwise.
### Setup
- Initiates the serial communication at a baud rate of 9600 using `Serial.begin(9600)`.
- Sets the pin modes of `Pin_A` and `Pin_B` to `INPUT` using `pinMode()`.
- Attaches the ISRs to the corresponding pins using the `attachInterrupt()` function and the `digitalPinToInterrupt()` parameter.
```
void setup() {

  Serial.begin(9600);

  // Set up Pin Modes
  pinMode(Pin_A, INPUT);
  pinMode(Pin_B, INPUT);
  
  // Interrupts
  attachInterrupt(digitalPinToInterrupt(Pin_A), isr_count_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Pin_B), isr_count_B, CHANGE);
}
```
### Loop
- Prints the count value using `Serial.print()` and `Serial.println()`.
```
void loop() {
  // display number of counts from the train of impulse from pin A and pin B signals on serial monitor
  Serial.print("COUNT: ");
  Serial.println(count);
}
```
---
# Software Practical Low Pass Filter (LPF)
### Defining Digital Pins A and B
```
#define Pin_A 2 // digital pin A of Encoder
#define Pin_B 3 // digital pin B of Encoder
```
### Defining Filter Variables for Pins A and B
```
// variables needed to calculate filtered pin A of Encoder
float prev_x_pin_A = 0, current_x_pin_A = 0;
float prev_y_pin_A = 0, filter_y_pin_A = 0;

// variables needed to calculate filtered pin B of Encoder
float prev_x_pin_B = 0, current_x_pin_B = 0;
float prev_y_pin_B = 0, filter_y_pin_B = 0;
```
### Equation 
Using python notebook from the sessions

- `pulse_per_rotation` stores number of pulses per one rotation
- `wheel_radius` stores radius of motorized wheel in cm
- `max_speed` stores maximum speed in m/s
- `angular_velocity` stores angular velocity in rad/s
- `rotation_per_second` stores angular velocity but in rotation per second
- `pulse_per_second` stores maximum number of pulses per second (Frequency for all pins)
- `pulse_per_second_one_pin` stores number of pulses in one pin
```python
# Givens
pulse_per_rotation = 540        # pulses per rotation (PPR)
wheel_radius = 0.2              # radius in centimeters (cm)
max_speed = 0.5                 # maximum speed in metres/second (m/s)

# Calculations
angular_velocity = max_speed / wheel_radius                 # angular velocity in radian per second (rad/s)

rotation_per_second = angular_velocity / (2 * np.pi)        # angular velocity in revolution per second (RPS)
pulse_per_second = pulse_per_rotation*rotation_per_second   # pulse per second (PPS)

pulse_per_second_one_pin = pulse_per_second / 2             # PPS in one pin
```
Setting cutoff frequency to a value greater than number of pulses in one pin:
```python
cutoff_frequency = pulse_per_second_one_pin * 3             # cutoff frequency in Hertz (Hz)
```
This yields us the following Equation:
```
filter_y_pin_# = -0.00621 y[n-1] + 0.503 x[n] + 0.503 x[n-1]
```
### Interrupt Service Routines
The code defines two interrupt service routines that are executed due to changes in the encoder pins:
```
// filter_y_pin_# = -0.00621 y[n-1] + 0.503 x[n] + 0.503 x[n-1]
void isr_filter_A() {
  // reading current signal of pin A of Encoder
  current_x_pin_A = digitalRead(Pin_A);
  // calculating filtered signal of pin A of Encoder after applying Low Pass Filter
  filter_y_pin_A = -0.00621*prev_y_pin_A + 0.503*current_x_pin_A + 0.503*prev_x_pin_A;
}

void isr_filter_B() {
  // reading current signal of pin B of Encoder
  current_x_pin_B = digitalRead(Pin_B);
  // calculating filtered signal of pin B of Encoder after applying Low Pass Filter
  filter_y_pin_B = -0.00621*prev_y_pin_B + 0.503*current_x_pin_B + 0.503*prev_x_pin_B;
}
```
Each ISR calculates the filtered signal for each pin using the equation.
### Setup
- Initiates the serial communication at a baud rate of 9600 using `Serial.begin(9600)`.
- Sets the pin modes of `Pin_A` and `Pin_B` to `INPUT` using `pinMode()`.
- Attaches the ISRs to the corresponding pins using the `attachInterrupt()` function and the `digitalPinToInterrupt()` parameter.
```
void setup() {

  Serial.begin(9600);

  // Set up Pin Modes
  pinMode(Pin_A, INPUT);
  pinMode(Pin_B, INPUT);

  // Interrupts
  attachInterrupt(digitalPinToInterrupt(Pin_A), isr_filter_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Pin_B), isr_filter_B, CHANGE);
}
```
### Loop
- Updates the variables for filtered pin A and B by assigning the current values to the previous variables.
- Prints the filtered value of pin A and B using `Serial.print()` and `Serial.println()`.
- Delay of 100 milliseconds using `delay()` before repeating the loop.
```
void loop() {
  // data update for pin A of Encoder
  prev_y_pin_A = filter_y_pin_A;
  prev_x_pin_A = current_x_pin_A;

  // display filtered pin A signal on serial monitor
  Serial.print("Pin A: ");
  Serial.println(filter_y_pin_A);

  // data update for pin B of Encoder
  prev_y_pin_B = filter_y_pin_B;
  prev_x_pin_B = current_x_pin_B;

  // display filtered pin B signal on serial monitor
  Serial.print("Pin B: ");
  Serial.println(filter_y_pin_B);

  delay(100);
}
```
