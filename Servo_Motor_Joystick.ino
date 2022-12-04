/*
  Purpose of this program is to know how to use and understand how a servo motors function with a joystick..
  Servo motor connects to digital pin 9 of the ardunio.
  The direction of servo motor is being changed using the X axis of the joystick.
  Joystick connects to analog pin A1 of the ardunio.
  Joystick ground connects to analog pin A2, 5V pin connects to analog pin A3.
*/

#include <Servo.h>

#define SERVO_PIN 9  //Servo motor will connect to ardunio digital pin 9
#define GROUND_JOY_PIN A3  //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2  //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1  //X axis reading from joystick will go into analog pin A1

Servo myservo ;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(VOUT_JOY_PIN, OUTPUT); //pin A3 used as output
  pinMode(GROUND_JOY_PIN, OUTPUT); //pin A2 used as output
  digitalWrite(VOUT_JOY_PIN, HIGH); //set pin A3 to high (+5V)
  digitalWrite(GROUND_JOY_PIN, LOW); //set pin A3 to low (ground)
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(200);
  int joystickXVal = analogRead(XJOY_PIN); //read joystick input on pin A1
  Serial.print(joystickXVal); //print the value from A1
  Serial.println(" = input from joystick"); //print text " = input from joystick"
  Serial.print((joystickXVal + 520) / 10); //print a from A1 calculated, scaled value
  Serial.println(" = output to servo"); //print " = output to servo"
  Serial.println() ;
  myservo.write((joystickXVal + 520) / 10); //write the calculated value to the servo
}
