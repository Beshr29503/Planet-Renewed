#define Pin_A 2 // digital pin A of Encoder
#define Pin_B 3 // digital pin B of Encoder

// variables needed to calculate filtered pin A of Encoder
float prev_x_pin_A = 0, current_x_pin_A = 0;
float prev_y_pin_A = 0, filter_y_pin_A = 0;

// variables needed to calculate filtered pin B of Encoder
float prev_x_pin_B = 0, current_x_pin_B = 0;
float prev_y_pin_B = 0, filter_y_pin_B = 0;

// variable to store number of counts from the train of impulse from pin A and pin B signals
int count = 0;

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

void setup() {

  Serial.begin(9600);

  // Set up Pin Modes
  pinMode(Pin_A, INPUT);
  pinMode(Pin_B, INPUT);

  // Interrupts
  attachInterrupt(digitalPinToInterrupt(Pin_A), isr_count_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Pin_B), isr_count_B, CHANGE);

  attachInterrupt(digitalPinToInterrupt(Pin_A), isr_filter_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Pin_B), isr_filter_B, CHANGE);
}

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

  // display number of counts from the train of impulse from pin A and pin B signals on serial monitor
  Serial.print("COUNT: ");
  Serial.println(count);

  delay(100);
}
