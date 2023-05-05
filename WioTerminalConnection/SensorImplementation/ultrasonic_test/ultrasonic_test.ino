#include <Ultrasonic.h>

const int ULTRASONIC_PIN_1 = 0;
const int ULTRASONIC_PIN_2 = 2;

Ultrasonic ultrasonic_1(ULTRASONIC_PIN_1);
Ultrasonic ultrasonic_2(ULTRASONIC_PIN_2);

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  // simple code for the first ultrasonic ranger
  Serial.print("The distance to the first object is ");
  long RangeInCentimeters_1 = ultrasonic_1.MeasureInCentimeters();
  Serial.print(RangeInCentimeters_1);
  Serial.print(" cm");
  // simple code for the second ultrasonic ranger
  Serial.print(" and the distance to the second object is ");
  long RangeInCentimeters_2 = ultrasonic_2.MeasureInCentimeters();
  Serial.print(RangeInCentimeters_2);
  Serial.println(" cm.");
  delay(250);
}
