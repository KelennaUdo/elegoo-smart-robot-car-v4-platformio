#include "DriveBase.hpp"

DriveBase::DriveBase(MotorTB6612& driver)
  : _driver(driver) {}

void DriveBase::begin() {
  _driver.begin();
}



void DriveBase::setRight(MotorTB6612::Direction dir, uint8_t pwm) {
  _driver.set(MotorTB6612::Channel::A, dir, pwm); // A = Right :contentReference[oaicite:2]{index=2}
}

void DriveBase::setLeft(MotorTB6612::Direction dir, uint8_t pwm) {
  _driver.set(MotorTB6612::Channel::B, dir, pwm);  // B = Left  :contentReference[oaicite:3]{index=3}
}

void DriveBase::stop() {
  _driver.stopAll();
}

void DriveBase::motion(Motion m, uint8_t speed) {
  // Implements the same motion patterns as ELEGOO’s ConquerorCarMotionControl switch. 

  switch (m) {
    case Motion::Forward:
      setRight(MotorTB6612::Direction::Forward,  speed);
      setLeft (MotorTB6612::Direction::Forward,  speed);
      break;

    case Motion::Backward:
      setRight(MotorTB6612::Direction::Backward, speed);
      setLeft (MotorTB6612::Direction::Backward, speed);
      break;

    case Motion::Left:
      // Right forward, Left backward
      setRight(MotorTB6612::Direction::Forward,  speed);
      setLeft (MotorTB6612::Direction::Backward, speed);
      break;

    case Motion::Right:
      // Right backward, Left forward
      setRight(MotorTB6612::Direction::Backward, speed);
      setLeft (MotorTB6612::Direction::Forward,  speed);
      break;

    case Motion::LeftForward:
      // Right faster, Left slower (arc left)
      setRight(MotorTB6612::Direction::Forward,  speed);
      setLeft (MotorTB6612::Direction::Forward,  speed / 2);
      break;

    case Motion::LeftBackward:
      setRight(MotorTB6612::Direction::Backward, speed);
      setLeft (MotorTB6612::Direction::Backward, speed / 2);
      break;

    case Motion::RightForward:
      setRight(MotorTB6612::Direction::Forward,  speed / 2);
      setLeft (MotorTB6612::Direction::Forward,  speed);
      break;

    case Motion::RightBackward:
      setRight(MotorTB6612::Direction::Backward, speed / 2);
      setLeft (MotorTB6612::Direction::Backward, speed);
      break;

    case Motion::Stop:
    default:
      stop();
      break;
  }
}
