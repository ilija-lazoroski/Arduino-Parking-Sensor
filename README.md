# Arduino-Parking-Sensor
This is a simple source code of a parking sensor simulation for a college project .
For this project I used Arduino UNO, Buzzer, Ultrasonic Distance sensor and one LED RGB.

The LED RGB is changing between red, green and blue colors as the sensor is detecting
that some object is near him.

For example: if the distance is less then 25cm the LED RGB will be red, 
if the distance is less less then 50cm and greater than 25cm it will be blue,
if the distance is greater then 50cm it will be green.

The buzzer is changing frequencies regarding the distance. That was done with map function.
If the distance is between 0 and 200, then mapping will be from 600 to 300 so if a distance 
is less then 25cm the sound of the buzzer will be stronger.
