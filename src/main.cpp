#include <Arduino.h>

#include "RobotConfig.hpp"
#include "MotorTB6612.hpp"
#include "DriveBase.hpp"




MotorTB6612 motorDriver(
  RobotConfig::Pins::PWMA, RobotConfig::Pins::AIN1,
  RobotConfig::Pins::PWMB, RobotConfig::Pins::BIN1,
  RobotConfig::Pins::STBY
);

// If forward/backward is reversed, flip invertRight/invertLeft to true.
DriveBase drive(motorDriver);

void setup() {
  drive.begin();

  delay(2000); // match ELEGOO demo behavior :contentReference[oaicite:6]{index=6}

  const uint8_t speed = 200; // safe default; you can try 255 later

  for (int i = 0; i < 9; i++) {
    auto motion = static_cast<DriveBase::Motion>(i);
    drive.motion(motion, speed);
    delay(1000);
  }

  drive.stop();
}

void loop() {
  // nothing (demo runs once)
}
