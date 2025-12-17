// include/RobotConfig.hpp
#pragma once
#include <Arduino.h>

// Minimal config: only what you need to drive TB6612 motors right now.
// (Pins match ELEGOO Smart Robot Car V4.0 TB6612 mapping.)
namespace RobotConfig {

  namespace Pins {
    // TB6612
    constexpr uint8_t STBY = 3;   // standby enable
    constexpr uint8_t PWMA = 5;   // speed (PWM) motor channel A
    constexpr uint8_t PWMB = 6;   // speed (PWM) motor channel B
    constexpr uint8_t AIN1 = 7;   // direction motor channel A
    constexpr uint8_t BIN1 = 8;   // direction motor channel B
  }

  namespace Motor {
    // Arduino PWM range
    constexpr uint8_t PWM_MAX = 255;

    // Minimum PWM that usually overcomes friction (stiction); tune later.
    constexpr uint8_t PWM_MIN_MOVING = 10;
  }

} // namespace RobotConfig
