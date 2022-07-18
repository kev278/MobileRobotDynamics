#include <Servo.h>


Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  myservo3.attach(11);
}

void loop() {
 int pos1[10] = {254,1,100,17,35,296,250,114,342,12};
  int pos3[10] = {158,137,276,286,67,76,160,233,255,272};
  int pos2[10] = {99,245,236,59,43,179,346,123,211,81};

  for (int i = 0; i < 10; i += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos1[i]);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2[i]);
    myservo3.write(pos3[i]);
    delay(200);                       // waits 15ms for the servo to reach the position
  }
}
