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
int roomWithObject[4];
int countsLeft, countsRight;
int left_sensor, center_left_sensor, center_right_sensor, right_sensor;
int roomCounter = 0, turnCounter = 0, stepCounter = 0, stops = 0;
bool returnTime = false;
 
char a, w, s ,d, r, b, q, e, k, l;

int32_t getAngle() {
  // turnAngle is a variable defined in TurnSensor.cpp
  //converts the number into degrees turned since the last sensor reset.
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}

// --- Setup Method
void setup() {
  Serial1.begin(9600);
  turnSensorSetup();
  delay(500);
  turnSensorReset();
  lineSensors.initFiveSensors();
  proxSensors.initThreeSensors();
  //countsLeft = encoders.getCountsAndResetLeft();
  //countsRight = encoders.getCountsAndResetRight();
}

// --- Main program loop
void loop() {
  lineSensors.read(lineSensorValues);

  if (lineSensorValues[0] > 300 && lineSensorValues[4] > 300){// && lineSensorValues[0] > 150 && lineSensorValues[4] > 150){
    //Serial1.println("Wall Encountered!");
    stopBot();
    reverseBot();
  }
  if (lineSensorValues[4] > 300 && lineSensorValues[0] < 160){
    moveBotLeft(5);
    //delay(75);
    moveBotForwards();}
  if (lineSensorValues[0] > 300 && lineSensorValues[4] < 160){
    moveBotRight(-5);
    moveBotForwards();} 

  // Read the sensors
  turnSensorUpdate();
  int32_t angle = getAngle();
  // Update the display
  //Serial1.println(angle);
  //Serial1.println(" ");
  char motor = (char) Serial1.read();
  char movingBot;
  String name ="";
  switch (motor){
    case 'a': case 'A': movingBot = a; name = "Left Bot"; turnLeft(); break;
    case 'w': case 'W': movingBot = w; name = "Forwards Bot"; moveBotForwards(); break;
    case 's': case 'S': movingBot = s; name = "Retreat Bot"; stopBot(); break;
    case 'd': case 'D': movingBot = d; name = "Right Bot"; turnRight(); break;
    case 'q': case 'Q': movingBot = q; name = "Search Room Left"; searchRoom(1); break;
    case 'e': case 'E': movingBot = e; name = "Search Room Right"; searchRoom(2); break;
    case 'b': case 'B': movingBot = b; name = "turn180"; turn180(); break;
    case 'k': case 'K': movingBot = k; name = "adjustLeft"; moveBotLeft(5); break;
    case 'l': case 'L': movingBot = l; name = "adjustRight"; moveBotRight(-5); break;
    }

//Attempting question  by recording the wheel turns from T junction and re tracing them but it didnt work
if (turnCounter == 2){
      countsLeft = encoders.getCountsLeft();
      countsRight = encoders.getCountsRight();
      stepCounter = countsRight;     
}
}

//Turns the bot 90 degrees to the right and makes it move forwards again
void turnRight(){
  moveBotRight(-90);
  moveBotForwards();
  if (turnCounter == 1){
      countsLeft = encoders.getCountsAndResetLeft();
      countsRight = encoders.getCountsAndResetRight();
  }

  turnCounter = turnCounter + 1;
}

//Moves bot 90 degrees to left and moves it fowards again
void turnLeft(){
  moveBotLeft(90);
  moveBotForwards();
  if (turnCounter == 1){
      countsLeft = encoders.getCountsAndResetLeft();
      countsRight = encoders.getCountsAndResetRight();
  }

  turnCounter = turnCounter + 1;
}

//Makes bot rotate 90 depending on which side the room is then enters the room using the wheel encoders
//then it calls the search functions
void searchRoom(int direction1or2){
  int counter = 0;
  //roomCounter = roomCounter + 1;
  enterRoom(direction1or2);
  scanRight(counter);
  //turnSensorReset();
  moveBotLeft(60);
  scanLeft(counter);
  //turnSensorReset();
  moveBotRight(-60);
  //scanRight(counter);
  counter = counter + 1;
  exitRoom(direction1or2);

  motors.setSpeeds(0,0);
  //motors.setSpeeds(0,0);
  //Serial1.println(countsLeft);
}


//Rotates the robot 60 degrees and records andything the proximity sensors pick up 
//Adding them to an array so it knows which room has had objects in for question 7
void scanRight(int counter){
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != -60){
    proxSensors.read();
    center_left_sensor = proxSensors.countsFrontWithLeftLeds();
    center_right_sensor = proxSensors.countsFrontWithRightLeds();
        //right_sensor = proxSensors.countsRightWithRightLeds();
    //Serial1.println(center_left_sensor);
    if (center_left_sensor > 3 || center_right_sensor > 3 && roomWithObject[counter] != 1){
      Serial1.println("Yes");
      roomWithObject[counter] = 1;
    }   
    int32_t angle = getAngle();
    turnSensorUpdate();
    //Serial1.println(angle);
    int speed = 75;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed2);
    delay(2);
      if (angle == -60){
       //Serial1.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed);
       motors.setRightSpeed(speed2);
       turnSensorReset();
       break;
      }
    }

}

void scanLeft(int counter){
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != 60){
    proxSensors.read();
    center_left_sensor = proxSensors.countsFrontWithLeftLeds();
    center_right_sensor = proxSensors.countsFrontWithRightLeds();
        //right_sensor = proxSensors.countsRightWithRightLeds();
    //Serial1.println(center_left_sensor);
    if (center_left_sensor > 3 || center_right_sensor > 3 && roomWithObject[counter] != 1){
      Serial1.println("Yes");
      roomWithObject[counter] = 1;
    }   
    int32_t angle = getAngle();
    turnSensorUpdate();
    //Serial1.println(angle);
    int speed = 75;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed2);
    motors.setRightSpeed(speed);
    delay(2);
      if (angle == 60){
       //Serial1.println("test");
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
  }  while(countsLeft<700&&countsRight<700);
  motors.setSpeeds(0,0);
}

void exitRoom(int direction1or2){
  countsLeft = encoders.getCountsAndResetLeft();
  countsRight = encoders.getCountsAndResetRight();
  motors.setSpeeds(-75,-75);
  do {
    countsLeft = encoders.getCountsLeft();
    countsRight = encoders.getCountsRight();
  }  while(countsLeft>-700&&countsRight>-700);
  motors.setSpeeds(0,0);
  if (direction1or2 == 1){moveBotRight(-90);}
  if (direction1or2 == 2){moveBotLeft(90);}
}


//stops the robot
void stopBot(){
   if (returnTime == false){
      int speed = 0;
      motors.setSpeeds(speed,speed);
      delay(2);   
   }
   if (returnTime == true){
    stops = stops + 1;
    if (stops == 1){
     Serial1.println("Passed Room"); 
      //int speed = 0;
      //motors.setSpeeds(speed,speed);
      //delay(2);       
    }
    if (stops == 2){
     Serial1.println("Passed Corridor");      
    }
    if (stops > 2){
      int speed = 0;
      motors.setSpeeds(speed,speed);
      delay(2);  
    }
   }

//Attemping question 7 again by recording the wheel spins to then be traced backwards
   if (turnCounter == 2){
    //stepCounter = countsRight;
    //tempStepCounter = stepCounter;
      stepCounter = stepCounter + countsRight; 
      //Serial1.println(countsRight);
      //Serial1.println(stepCounter);
      countsLeft = encoders.getCountsAndResetLeft();
      countsRight = encoders.getCountsAndResetRight(); 
      //Serial1.println(stepCounter);    
   }
  // temp = temp + 1;
  }


//Reverses the bot buy an amount of the wheel encoders
void reverseBot(){
  countsLeft = encoders.getCountsAndResetLeft();
  countsRight = encoders.getCountsAndResetRight();
  motors.setSpeeds(-75,-75);
  do {
    countsLeft = encoders.getCountsLeft();
    countsRight = encoders.getCountsRight();
  }  while(countsLeft>-75&&countsRight>-75);
  motors.setSpeeds(0,0);
}


//Spins the bot 180 degrees then it begins to traverse the corridor
void turn180(){
  returnTime = true;
  moveBotRight(-180);
  moveBotForwards();

  //Attempting to retrace steps from wheel decoders but couldnt get the two journeys to add togetehr between 
  //searching the room
  countsLeft = encoders.getCountsAndResetLeft();
  countsRight = encoders.getCountsAndResetRight();
  do{
    countsLeft = encoders.getCountsLeft();
    countsRight = encoders.getCountsRight();
  //Serial1.println(countsRight);
    //Serial1.println(stepCounter);
  }while(countsRight < stepCounter);
  //stopBot();
  } 

//Spins the bot y the given degree to the right, by calling turn sensor reset which sets the gyro back to 0 for 
//the robot to then spin on the spot until the gyro matches the given input
void moveBotRight(int degree){
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != degree){
    int32_t angle = getAngle();
    turnSensorUpdate();
    //Serial1.println(angle);
    int speed = 75;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed2);
    delay(2);
      if (angle == degree){
       //Serial1.println("test");
       int speed = 0;
       int speed2 = 0 - speed; 
       motors.setLeftSpeed(speed);
       motors.setRightSpeed(speed2);
       turnSensorReset();
       break;
      }
    }
  }  

//Same as the right turn but the opposite way
void moveBotLeft(int degree){
  //movingRight = true;
  int32_t angle = getAngle();
  turnSensorReset();
  while (angle != degree){
    int32_t angle = getAngle();
    turnSensorUpdate();
    //Serial1.println(angle);
    int speed = 75;
    int speed2 = 0 - speed; 
    motors.setLeftSpeed(speed2);
    motors.setRightSpeed(speed);
    delay(2);
      if (angle == degree){
       //Serial1.println("test");
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
    for (int speed = 0; speed <= 150; speed++)
    {
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(speed);
      delay(2);
    }
  } 

  
void moveBotBackwards(){
        int speed = 0;
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        delay(2);
    
  }
