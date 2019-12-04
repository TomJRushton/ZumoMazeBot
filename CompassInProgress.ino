#include <Zumo32U4.h>
#include "TurnSensor.h"
#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

L3G gyro;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;

char a, w, s ,d;
bool moving = false;

// --- Helper functions
int32_t getAngle() {
  // turnAngle is a variable defined in TurnSensor.cpp
  // This fancy math converts the number into degrees turned since the
  // last sensor reset.
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}

// --- Setup Method
void setup() {
  Serial.begin(9600);
  turnSensorSetup();
  delay(500);
  turnSensorReset();
  lcd.clear();
}

// --- Main program loop
void loop() {
  
  // Read the sensors
  turnSensorUpdate();
  int32_t angle = getAngle();
  // Update the display
  Serial.println(angle);
  Serial.println(" ");

  char motor = (char) Serial.read();
  char movingTimmy;
  String name ="";
    switch (motor){
    case 'a': case 'A': movingTimmy = a; name = "Left Timmy"; moveTimmyLeft(); break;
    case 'w': case 'W': movingTimmy = w; name = "Forwards Timmy"; moveTimmyForwards(); break;
    case 's': case 'S': movingTimmy = s; name = "Retreat Timmy"; moveTimmyBackwards(); break;
    case 'd': case 'D': movingTimmy = d; name = "Right Timmy"; moveTimmyRight(angle); break;
    }
}

void moveTimmyLeft(){}

void moveTimmyRight(int angle){
  
  int startAngle = angle;
  int desiredAngle = angle + 90;
  Serial.println("angle is");
  Serial.println(startAngle);
    for (int speed = 0; speed <= 125; speed++)
    {
      turnSensorUpdate();
      int32_t angle2 = getAngle();
      Serial.println(angle2); 
      motors.setLeftSpeed(speed);
      delay(2);
    }
    for (int speed = 125; speed >= 0; speed--)
    {
      motors.setLeftSpeed(speed);
      delay(2);
    }
    for (int speed = 0; speed >= -125; speed--)
    {
      turnSensorUpdate();
      int32_t angle2 = getAngle();
      Serial.println(angle2); 
      motors.setRightSpeed(speed);
      delay(2);
    }
    for (int speed = -125; speed <= 0; speed++)
    {
      motors.setRightSpeed(speed);
      delay(2);
    }
//    while (startAngle < desiredAngle)
//    {
//      turnSensorUpdate();
//      startAngle = getAngle();
//      
//    }
  }
  





void moveTimmyForwards(){
  if (moving == false){
    for (int speed = 0; speed <= 50; speed++)
    {
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(speed);
      delay(2);
    }
    moving = true;}  
  } 
  
void moveTimmyBackwards(){
    if (moving == true){
        int speed = 0;
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        delay(2);
        moving = false;
    }
    //if (moving == false){
    else {  
      for (int speed = 0; speed >= -50; speed--)
      {
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        delay(2);
      }
    }
  } 
