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
- Attaches the ISRs to the corresponding pins using the `attachInterrupt()` function and the `digitalPinToInterrupt()` parameter. This ensures that the ISRs are called when a change is detected on the specified pins.
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
### 
