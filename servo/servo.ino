/*
MIT License
Copyright 2021 Michael Schoeffler (https://www.mschoeffler.com)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/*
* Example source code of an Arduino tutorial on how to control an MG 996R servo motor. 
*/

#include <Servo.h> 

// servo pin
const int servoPin = 3;

// pushbutton pin
const int buttonPin = 7;

Servo servo; // servo object representing the MG 996R servo

void setup() {
  // servo is wired to Arduino on digital pin 3
  servo.attach(servoPin); 

  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);

  servo.write(45); // move MG996R's shaft to angle 45°
}

void loop() {
  // local variable to hold the pushbutton states
  int buttonState;  

  // read the digital state of buttonPin with digitalRead() function and store the value in buttonState variable
  buttonState = digitalRead(buttonPin);

  //if the button is pressed then released, make the servo turn once
  if (buttonState == HIGH)
  {
    servo.write(5); // move MG996R's shaft to angle 5°
    delay(200); // wait for one second
    servo.write(15); // move MG996R's shaft to angle 30°
    delay(1000); // wait for one second 
  }

}