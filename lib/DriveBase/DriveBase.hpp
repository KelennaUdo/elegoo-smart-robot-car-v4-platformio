#pragma once
#include <Arduino.h>
#include "MotorTB6612.hpp"

/*
  DriveBase
  ---------
  Robot-level motion commands (Forward/Left/Right/etc.)
  built on top of MotorTB6612.

  Assumption (matching ELEGOO reference):
  - TB6612 Channel A = RIGHT side
  - TB6612 Channel B = LEFT side :contentReference[oaicite:1]{index=1}
*/

class DriveBase {
public:
  enum class Motion : uint8_t {
    Forward,
    Backward,
    Left,
    Right,
    LeftForward,
    LeftBackward,
    RightForward,
    RightBackward,
    Stop
  };

  // If your robot drives backward when you command forward, flip these flags.
  DriveBase(MotorTB6612& driver);

  void begin();
  void motion(Motion m, uint8_t speed);
  void stop();


private:
  MotorTB6612& _driver;


  void setRight(MotorTB6612::Direction dir, uint8_t pwm); // Channel A
  void setLeft (MotorTB6612::Direction dir, uint8_t pwm); // Channel B
};
