#pragma once
#include <Arduino.h>

/*
  MotorTB6612
  ----------
  Low-level motor driver for the TB6612 (ELEGOO V4.0 shield).

  This layer:
  - knows pins
  - writes digital direction pins + PWM pins
  - controls STBY (standby enable)
*/

class MotorTB6612 {
public:
  // ELEGOO code treats channel A as RIGHT and channel B as LEFT. :contentReference[oaicite:0]{index=0}
  enum class Channel : uint8_t { A, B };

  enum class Direction : uint8_t {
    Forward,
    Backward,
    Stop
  };

  MotorTB6612(uint8_t pwma, uint8_t ain1,
              uint8_t pwmb, uint8_t bin1,
              uint8_t stby);

  void begin();

  // Set one TB6612 channel (A or B)
  void set(Channel ch, Direction dir, uint8_t pwm);

  // Stop both channels and disable the driver (STBY LOW)
  void stopAll();

  // Enable/disable TB6612 driver
  void setStandby(bool enable);

private:
  void setA(Direction dir, uint8_t pwm);
  void setB(Direction dir, uint8_t pwm);

  uint8_t _pwma, _ain1, _pwmb, _bin1, _stby;
};
