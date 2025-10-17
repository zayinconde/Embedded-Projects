// this is a project showing how a joystick (HW-504) can be used (x and y direction) to control 2 servos (Tower Pro SG-90)
// included is serial ouput to visualize the lowest and highest values to map the joystick to the servos correctly.

// Note when get arduino libraries you must add "lib_deps = arduino-libraries/Servo@^1.2.1 " to platformio.ini

#include <Arduino.h>
#include <Servo.h>

Servo servo1;
Servo servo2;



const int SWpin = A2;

void setup() {
  Serial.begin(9600); // remember to add this if i want live output into VS code terminal
  servo1.attach(9); // attach to pwm pin 9
  servo2.attach(10); // attach to pwm pin 10
  pinMode(SWpin, INPUT_PULLUP);
}

void loop() {

  int vrx = analogRead(A0);
  int vry = analogRead(A1);
  int SWvalue  = digitalRead(A2);
  int xdir = map(vrx, 0, 1023, 0, 180); 
  int ydir = map(vry, 0, 1023, 0, 180); 
  // this works by choosing the Analog read value VRX and mapping the lowest value "0" and highest "1023" (10bit adc) -
  // then taking the smallest and biggest value you want then it will be mapped to that range
  Serial.print("VRX: ");
  Serial.println(vrx); 
  Serial.print("VRY: ");
  Serial.println(vry); //print"ln" to force line skip
  if(SWvalue == LOW){
    Serial.println("sw is pressed"); // add serial print ln to force a new line on next print
  }
  else{
    Serial.println("sw is NOT pressed"); // add serial print ln to force a new line on next print
  }
  Serial.println(); // adds line gap in print statements
  //delay(1000); will cause live servo delay so commented out. 
  
  
  servo1.write(xdir);
  servo2.write(ydir);
}
