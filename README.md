# Planet-Renewed
---
## **Task 1 ( C Programming )**

*1. Hello Gru*

A C/C++ program that prints the string ‘GRU’ in the output terminal.

*2. Counting Down*

A C/C++ program that takes the number to start the countdown from as input and prints the countdown text starting from that number.

*3. Task Manager*

A C/C++ program that allows users to add, view, and remove tasks, each task has an id/index and a description. The id is a positive unique integer.

*4. Kalman Missile*

A C/C++ program that takes two sensor measurements (just two arrays) and generates only one new array measurement with any averaging method, such as Kalman Filter.

• The two sensors have two different accuracies one has 79% and another one has 92%, (You should consider this information in your output formula).

• IMU sensor outputs the forces in all spatial coordinates x, y, z, but for the sake of simplicity we only work in one dimension which is y.

• Assume two sensors have the same sample frequency, (that means the two arrays have the same number of elements)

---
## **Task 2 ( Hardware )**

*1. Lightning The Dark*

• Design a circuit that takes 220V AC as input and the output is 5V DC and connects LED to the output (Hint: firstly, you need to step down the AC, then you need to convert AC to DC, and lastly connect the load).

• If the input power budget of your power supply is 1440W, and you use a current limiting resistor with each LED 330 ohm. Estimate how many LEDs could be put in parallel that is suitable for this power budget.

*2. Air Extraction To Fan*

• Design a simple H-bridge driver to control the direction of the DC motor using transistors.

*3. Box Of Shame*

If you have a simple circuit that drive high power 12V LED with current limiting resistor 3.3ohm and need to drive them with 80C liPo (lithium Polymer) batteries that have 5200mAh charge, assume that girls stay inside the box of shame for about 5 hours. How many batteries are connected in parallel to light up the LED for more than 5 hours

• Assume all batteries have equal voltage

• Assume the LED is ideal (deal with it as a short circuit in forward bias)

• The current limiting resistor is a high-power resistor.

---
## **Task 3 ( Embedded )**

*1. Signal To Engage*

• Write 2 Arduino codes, one that interface with two push buttons,
and the other one communicates with the first one by receiving
data about buttons state, using I2C communication protocol.

*2. Cookiebot*

You have the cookie bot with four ultrasnoic that
measure the distance each up to 8m positioned as
shown. Specifically, positioned at (0°, 90°, 180°, 270°) from
the Cookie headings.

The Shrink ray champer is (5m x 6m), and we
need to localize the position of the cookie bot on
that champer (localization in this problem
means to get (x,y) of the robot with respect to
the room).

• Assume the cookie bot only moves in forward
or lateral (there is no rotation).

• Assume the origin of the chamber on the left-down corner

---
## **Task 4 ( Python & ML )**

*1. Sky Clash*

Implement a Python program that simulates air battlefield
using OOP Methods:

- Game has multiple rounds and it ends when one of the villains
reaches 0 Health.

- During one round each villain could use a weapon to damage
the other or use a shield to protect himself from the other’s
weapons.

*2. Shrinkage Model*

1-Create Linear Regression Model, and train
this model on the give dataset:

- The knob of the Gun has a range from [0
MW, 300MW]

- Assume that shrinkage does not depend
on the volume of the target object.

2-If Gru needs to shrink the moon with a percentage 85% where
should he adjust the knob?

---
