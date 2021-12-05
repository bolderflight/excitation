/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#ifndef SRC_PULSE_H_
#define SRC_PULSE_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <cstddef>
#include <cmath>
#include "units.h"  // NOLINT

namespace bfs {

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
            freq_slope_(2.0f * BFS_PI<float> / dur_s_) {}
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

}  // namespace bfs

#endif  // SRC_PULSE_H_
