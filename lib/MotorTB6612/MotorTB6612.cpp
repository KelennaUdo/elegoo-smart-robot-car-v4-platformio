#include "MotorTB6612.hpp"

MotorTB6612::MotorTB6612(uint8_t pwma, uint8_t ain1,
                         uint8_t pwmb, uint8_t bin1,
                         uint8_t stby)
  : _pwma(pwma), _ain1(ain1),
    _pwmb(pwmb), _bin1(bin1),
    _stby(stby) {}

void MotorTB6612::begin() {
  pinMode(_pwma, OUTPUT);
  pinMode(_pwmb, OUTPUT);
  pinMode(_ain1, OUTPUT);
  pinMode(_bin1, OUTPUT);
  pinMode(_stby, OUTPUT);

  stopAll();
}

void MotorTB6612::setStandby(bool enable) {
  digitalWrite(_stby, enable ? HIGH : LOW);
}

void MotorTB6612::set(Channel ch, Direction dir, uint8_t pwm) {
  // If we want any motion, ensure driver is enabled.
  if (dir != Direction::Stop && pwm > 0) {
    setStandby(true);
  }

  if (ch == Channel::A) setA(dir, pwm);
  else                 setB(dir, pwm);
}

void MotorTB6612::stopAll() {
  analogWrite(_pwma, 0);
  analogWrite(_pwmb, 0);
  setStandby(false);
}

void MotorTB6612::setA(Direction dir, uint8_t pwm) {
  switch (dir) {
    case Direction::Forward:
      digitalWrite(_ain1, HIGH);
      analogWrite(_pwma, pwm);
      break;
    case Direction::Backward:
      digitalWrite(_ain1, LOW);
      analogWrite(_pwma, pwm);
      break;
    case Direction::Stop:
    default:
      analogWrite(_pwma, 0);
      break;
  }
}

void MotorTB6612::setB(Direction dir, uint8_t pwm) {
  switch (dir) {
    case Direction::Forward:
      digitalWrite(_bin1, HIGH);
      analogWrite(_pwmb, pwm);
      break;
    case Direction::Backward:
      digitalWrite(_bin1, LOW);
      analogWrite(_pwmb, pwm);
      break;
    case Direction::Stop:
    default:
      analogWrite(_pwmb, 0);
      break;
  }
}
