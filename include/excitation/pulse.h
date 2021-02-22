/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
*/

#ifndef INCLUDE_EXCITATION_PULSE_H_
#define INCLUDE_EXCITATION_PULSE_H_

#include <cmath>
#include "units/units.h"

namespace excitation {

class Pulse {
 public:
  Pulse(const float dur_s, const float amp) : dur_s_(dur_s), amp_(amp) {}
  inline float Run(const float time_s) const {
    if (time_s < dur_s_) {
      return amp_;
    } else {
      return 0.0f;
    }
  }

 private:
  const float dur_s_, amp_;
};

class Pulse1Cos {
 public:
  Pulse1Cos(const float dur_s, const float pause_s, const float amp) :
            dur_s_(dur_s), pause_s_(pause_s), amp_(amp),
            freq_slope_(2.0f * constants::PI<float> / dur_s_) {}
  inline float Run(const float time_s) const {
    if (time_s < dur_s_ + pause_s_) {
      if (time_s < 0.5f * dur_s_) {
        return amp_ * 0.5f * (1.0f - cosf(freq_slope_ * time_s));
      } else if (time_s < 0.5f * dur_s_ + pause_s_) {
        return amp_;
      } else {
        return amp_ * 0.5f * (1.0f - cosf(freq_slope_ * (time_s - pause_s_)));
      }
    } else {
      return 0.0f;
    }
  }

 private:
  const float dur_s_, pause_s_, amp_;
  const float freq_slope_;
};

}  // namespace excitation

#endif  // INCLUDE_EXCITATION_PULSE_H_
