#include <Wire.h>
#include "TurnSensor.h"

uint32_t turnAngle = 0;

// turnRate is the current angular rate of the gyro, in units of
// 0.07 degrees per second.
int16_t turnRate;

// This is the average reading obtained from the gyro's Z axis
// during calibration.
int16_t gyroOffset;

// This variable helps us keep track of how much time has passed
// between readings of the gyro.
uint16_t gyroLastUpdate = 0;

void turnSensorSetup()
{
  Wire.begin();
  gyro.init();

  // 800 Hz output data rate,
  // low-pass filter cutoff 100 Hz
  gyro.writeReg(L3G::CTRL1, 0b11111111);

  // 2000 dps full scale
  gyro.writeReg(L3G::CTRL4, 0b00100000);

  // High-pass filter disabled
  gyro.writeReg(L3G::CTRL5, 0b00000000);

  // Turn on the yellow LED in case the LCD is not available.
  ledYellow(1);

  // Delay to give the user time to remove their finger.
  delay(500);

  // Calibrate the gyro.
  int32_t total = 0;
  for (uint16_t i = 0; i < 1024; i++)
  {
    // Wait for new data
    while(!gyro.readReg(L3G::STATUS_REG) & 0x08);
    gyro.read();
    total += gyro.g.z;
  }
  ledYellow(0);
  gyroOffset = total / 1024;

}

// This should be called to set the starting point for turn
void turnSensorReset()
{
  gyroLastUpdate = micros();
  turnAngle = 0;
}

// Read the gyro and update the angle.
void turnSensorUpdate()
{
  gyro.read();
  turnRate = gyro.g.z - gyroOffset;

  // Figure out how much time has passed since the last update (dt)
  uint16_t m = micros();
  uint16_t dt = m - gyroLastUpdate;
  gyroLastUpdate = m;

  //estimation of how much the robot has turned since the last update.
  // (angular change = angular velocity * time)
  int32_t d = (int32_t)turnRate * dt;

  // The units of d are gyro digits times microseconds.  We need
  // to convert those to the units of turnAngle, where 2^29 units
  // represents 45 degrees.  The conversion from gyro digits to
  // degrees per second (dps) is determined by the sensitivity of
  // the gyro: 0.07 degrees per second per digit.
  turnAngle += (int64_t)d * 14680064 / 17578125;
}
