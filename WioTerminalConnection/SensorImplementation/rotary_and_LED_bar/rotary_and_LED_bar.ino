#include <Grove_LED_Bar.h>

/* the clock pin and data pin are used for serial communication with the LED bar. 
The data pin sends the data in a serial stream, bit by bit, to the LED bar, while 
the clock pin signals when to read each bit of data. */

int const LED_BAR_CLOCK_PIN = 1; //the digital pin number for the LED_bar clock pin 
int const LED_BAR_DATA_PIN = 0; //the digital pin number for LED_bar data pin
int const LED_BAR_ORIENTATION = 0; //if the bar is oriented horizontally use 0 and if oriented vertically use 1
int const LED_SEGMENTS = 10; //the number of LED's on the LED_bar

/* The ADC (analog-to-digital converter) is a component that converts an analog voltage input signal 
to a digital value that can be processed by the microcontroller. The ADC needs a reference voltage to 
determine the range and precision of its output. which is ADC_REF in our code. */

/* In the case of the Grove interface, VCC is the pin that provides power to the Grove module. 
The standard voltage for the Grove VCC pin is 5 volts. This means that the module is designed 
to be powered by a voltage source that provides 5 volts. According to the rotary angle sensor 
specifications the typical VDC voltage is 5V meaning we can use a VCC of 5V for the sensor. 
NOTE: VDC and VCC are different terms in electronics but in our case they are kinda the same thing.
we use 3.3V instead of 5V because all the available plugs on the WIO terminal chasis are 3.3V and not 5V
this doesn't damage the sensor since it doesn't go above the maximum voltage(5.25V) of the sensor. */

int const ROTARY_ANGLE_PIN = 2; //the analog pin number for the Rotary angle sensor
float const ADC_REF = 3.3; //The Wio Terminal has a built-in ADC with a reference voltage of 3.3V
float const GROVE_VCC = 3.3;
int const FULL_ANGLE = 300; //this is the maximum angle of the rotary angle

/* the last argument (LED_BAR_10) is a predefined variable in the library to show that
the LED_BAR used here is the one that has 10 LED's in the bar */
Grove_LED_Bar bar(LED_BAR_CLOCK_PIN, LED_BAR_DATA_PIN, LED_BAR_ORIENTATION, LED_BAR_10);

void setup() {
  // a pinMode to show that the rotary angle sensor is used as INPUT
  pinMode(ROTARY_ANGLE_PIN, INPUT);
  bar.begin();
}

void loop() {
  
  int sensor_value = analogRead(ROTARY_ANGLE_PIN);
  /* calculates the voltage read by the sensor by using the sensor_value and ADC_REF.
  NOTE: 1023 represents the maximum value of the analog to digital converter (ADC) that 
  is used to read the voltage from the rotary angle sensor. The analogRead() function returns 
  a value between 0 and 1023, which is then scaled to the ADC reference voltage (ADC_REF) to 
  obtain the voltage reading from the sensor. */
  float voltage = (float)sensor_value * ADC_REF / 1023;
  //turn voltage to degrees with the accuracy of the VCC voltage
  float degrees = (voltage * FULL_ANGLE) / GROVE_VCC;
  //simple print command to be sure that the rotary angle sensor is working
  Serial.print("The current angle is ");
  Serial.println(degrees);

  //map the angle to a level value between 0 and 10 for the LED bar
  int level = map(degrees, 0, FULL_ANGLE, 0 , LED_SEGMENTS);
  //sets the level of the LED bar in other words turns on each LED of the bar according to current level
  bar.setLevel(level);
  delay(200);
}
