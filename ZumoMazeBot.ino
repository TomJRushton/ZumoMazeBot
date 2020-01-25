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
Zumo32U4Encoders encoders;
Zumo32U4Buzzer buzzer;
//#define NUM_SENSORS 5
unsigned int lineSensorValues[5];
unsigned int proxSensorValues[4];
int countsLeft, countsRight;
int left_sensor, center_left_sensor, center_right_sensor, right_sensor;
int roomCounter = 0;
 
char a, w, s ,d, r, b, q, e, k, l;
bool moving = false;
bool movingRight = false;
bool movingLeft = false;
//int countsRight, countsLeft;
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
  //lcd.clear();
  lineSensors.initFiveSensors();
  proxSensors.initThreeSensors();
  //countsLeft = encoders.getCountsAndResetLeft();
  //countsRight = encoders.getCountsAndResetRight();
}

// --- Main program loop
void loop() {
  lineSensors.read(lineSensorValues);
  //Serial.println(lineSensorValues[0]);
  //Serial.println(lineSensorValues[1]);
  //Serial.println(lineSensorValues[2]);
  //Serial.println(lineSensorValues[3]);
  //Serial.println(lineSensorValues[4]);

  if (lineSensorValues[0] > 210){
    //stopBot();
    //reverseBot();
    //moveBotLeft();
  }


  //Serial.println(left_sensor);
  //Serial.println(center_left_sensor);
  //Serial.println(center_right_sensor);
  //Serial.println(right_sensor);
  
  // Read the sensors
  turnSensorUpdate();
  int32_t angle = getAngle();
  // Update the display
  //Serial.println(angle);
  //Serial.println(" ");
  char motor = (char) Serial.read();
  char movingBot;
  String name ="";
  switch (motor){
    case 'a': case 'A': movingBot = a; name = "Left Bot"; moveBotLeft(90); break;
    case 'w': case 'W': movingBot = w; name = "Forwards Bot"; moveBotForwards(); break;
    case 's': case 'S': movingBot = s; name = "Retreat Bot"; moveBotBackwards(); break;
    case 'd': case 'D': movingBot = d; name = "Right Bot"; moveBotRight(-90); break;
    case 'q': case 'Q': movingBot = q; name = "Search Room Left"; searchRoom(1); break;
    case 'e': case 'E': movingBot = e; name = "Search Room Right"; searchRoom(2); break;
    case 'b': case 'B': movingBot = b; name = "turn180"; turn180(); break;
    case 'k': case 'K': movingBot = k; name = "adjustLeft"; moveBotLeft(5); break;
    case 'l': case 'L': movingBot = l; name = "adjustRight"; moveBotRight(-5); break;
    }

}


void searchRoom(int direction1or2){
  roomCounter = roomCounter + 1;
  enterRoom(direction1or2);
  scanRight();
  scanLeft();
  scanRight();
  exitRoom(direction1or2);

  motors.setSpeeds(0,0);
  //motors.setSpeeds(0,0);
  //Serial.println(countsLeft);
}

void scanRight(){
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != -60){
    proxSensors.read();
    center_left_sensor = proxSensors.countsFrontWithLeftLeds();
    center_right_sensor = proxSensors.countsFrontWithRightLeds();
        //right_sensor = proxSensors.countsRightWithRightLeds();
    Serial.println(center_left_sensor);
    if (center_left_sensor > 3 || center_right_sensor > 3){
      Serial.println("Object Found");
    }   
    int32_t angle = getAngle();
    turnSensorUpdate();
    Serial.println(angle);
    int speed = 100;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed2);
    delay(2);
      if (angle == -60){
       Serial.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed);
       motors.setRightSpeed(speed2);
       turnSensorReset();
       break;
      }
    }

}

void scanLeft(){
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != 120){
    proxSensors.read();
    center_left_sensor = proxSensors.countsFrontWithLeftLeds();
    center_right_sensor = proxSensors.countsFrontWithRightLeds();
        //right_sensor = proxSensors.countsRightWithRightLeds();
    Serial.println(center_left_sensor);
    if (center_left_sensor > 3 || center_right_sensor > 3){
      Serial.println("Object Found");
    }   
    int32_t angle = getAngle();
    turnSensorUpdate();
    Serial.println(angle);
    int speed = 100;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed2);
    motors.setRightSpeed(speed);
    delay(2);
      if (angle == 120){
       Serial.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed2);
       motors.setRightSpeed(speed);
       turnSensorReset();
       break;
      }
    }}

void enterRoom(int direction1or2){
  if (direction1or2 == 1){moveBotLeft(90);}
  if (direction1or2 == 2){moveBotRight(-90);}
  countsLeft = encoders.getCountsAndResetLeft();
  countsRight = encoders.getCountsAndResetRight();
  motors.setSpeeds(75,75);
  do {
    countsLeft = encoders.getCountsLeft();
    countsRight = encoders.getCountsRight();
  }  while(countsLeft<500&&countsRight<500);
  motors.setSpeeds(0,0);
}

void exitRoom(int direction1or2){
  countsLeft = encoders.getCountsAndResetLeft();
  countsRight = encoders.getCountsAndResetRight();
  motors.setSpeeds(-75,-75);
  do {
    countsLeft = encoders.getCountsLeft();
    countsRight = encoders.getCountsRight();
  }  while(countsLeft>-500&&countsRight>-500);
  motors.setSpeeds(0,0);
  if (direction1or2 == 1){moveBotRight(90);}
  if (direction1or2 == 2){moveBotLeft(-90);}
}

void stopBot(){
   int speed = 0;
   motors.setSpeeds(speed,speed);
  // motors.setLeftSpeed(speed);
   //motors.setRightSpeed(speed);
   delay(2);        
  }


void reverseBot(){
  int speed = -150;
  for (speed; speed < 0; speed++)
    {
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(speed);
      delay(2);
   }
}



void turn180(){//int angle){
  //movingRight = true;
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != -180){
    int32_t angle = getAngle();
    turnSensorUpdate();
    Serial.println(angle);
    int speed = 100;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed2);
    delay(2);
      if (angle == -180){
       Serial.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed);
       motors.setRightSpeed(speed2);
       turnSensorReset();
       break;
      }
    }
  } 

  
void moveBotRight(int degree){//int angle){
  //movingRight = true;
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != degree){
    int32_t angle = getAngle();
    turnSensorUpdate();
    Serial.println(angle);
    int speed = 100;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed2);
    delay(2);
      if (angle == degree){
       Serial.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed);
       motors.setRightSpeed(speed2);
       turnSensorReset();
       break;
      }
    }
  }  


void moveBotLeft(int degree){
  //movingRight = true;
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != -90){
    int32_t angle = getAngle();
    turnSensorUpdate();
    Serial.println(angle);
    int speed = 100;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed2);
    motors.setRightSpeed(speed);
    delay(2);
      if (angle == 90){
       Serial.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed2);
       motors.setRightSpeed(speed);
       turnSensorReset();
       break;
      }
    }
  }  


void moveBotForwards(){
  if (moving == false){
    for (int speed = 0; speed <= 75; speed++)
    {
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(speed);
      delay(2);
    }
    moving = true;}  
  } 

  
void moveBotBackwards(){
    if (moving == true){
        int speed = 0;
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        delay(2);
        moving = false;
    }
    //if (moving == false){
    else {  
      for (int speed = 0; speed >= -75; speed--)
      {
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        delay(2);
      }
    }
  }



   //void moveBotRight(int angle){
//  
//  int startAngle = angle;
//  int desiredAngle = angle + 90;
//  Serial1.println("angle is");
//  Serial1.println(startAngle);
//    for (int speed = 0; speed <= 125; speed++)
//    {
//      turnSensorUpdate();
//      int32_t angle2 = getAngle();
//      Serial1.println(angle2); 
//      motors.setLeftSpeed(speed);
//      delay(2);
//    }
//    for (int speed = 125; speed >= 0; speed--)
//    {
//      motors.setLeftSpeed(speed);
//      delay(2);
//    }
//    for (int speed = 0; speed >= -125; speed--)
//    {
//      turnSensorUpdate();
//      int32_t angle2 = getAngle();
//      Serial1.println(angle2); 
//      motors.setRightSpeed(speed);
//      delay(2);
//    }
//    for (int speed = -125; speed <= 0; speed++)
//    {
//      motors.setRightSpeed(speed);
//      delay(2);
//    }
//    while (startAngle < desiredAngle)
//    {
//      turnSensorUpdate();
//      startAngle = getAngle();
//      
//    }
//  }
