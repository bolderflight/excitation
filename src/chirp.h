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

#ifndef SRC_CHIRP_H_
#define SRC_CHIRP_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <cstddef>
#include <cmath>

namespace bfs {

class LinearChirp {
 public:
  LinearChirp(float dur_s, float amp_start, float amp_stop, float freq_start,
              float freq_stop) : dur_s_(dur_s), amp_start_(amp_start),
              amp_stop_(amp_stop), freq_start_(freq_start),
              freq_stop_(freq_stop) {
    freq_slope_ = (freq_stop_ - freq_start_) / dur_s_;
    amp_slope_ = (amp_stop_ - amp_start_) / dur_s_;
  }
  inline float Run(const float time_s) {
    if (time_s < dur_s_) {
      freq_ = freq_start_ + freq_slope_ * time_s;
      amp_ = amp_start_ + amp_slope_ * time_s;
      return amp_ * sinf((freq_ / 2.0f) * time_s);
    } else {
      return 0.0f;
    }
  }

 private:
  float dur_s_;
  float amp_start_, amp_stop_;
  float freq_start_, freq_stop_;
  float freq_slope_, amp_slope_;
  float freq_, amp_;
};

class LogChirp {
 public:
  LogChirp(float dur_s, float amp_start, float amp_stop, float freq_start,
           float freq_stop) : dur_s_(dur_s), amp_start_(amp_start),
           amp_stop_(amp_stop), freq_start_(freq_start),
           freq_stop_(freq_stop) {
    freq_slope_ = powf(freq_stop_ / freq_start_, 1.0f / dur_s_);
    freq_log_ = logf(freq_slope_);
    amp_slope_ = (amp_stop_ - amp_start_) / dur_s_;
  }
  inline float Run(const float time_s) {
    if (time_s < dur_s_) {
      freq_ = freq_start_ * (powf(freq_slope_, time_s) - 1.0f) /
              (time_s * freq_log_);
      amp_ = amp_start_ + amp_slope_ * time_s;
      return amp_ * sinf(freq_ * time_s);
    } else {
      return 0.0f;
    }
  }

 private:
  float dur_s_;
  float amp_start_, amp_stop_;
  float freq_start_, freq_stop_;
  float freq_slope_, freq_log_, amp_slope_;
  float freq_, amp_;
};

}  // namespace bfs

#endif  // SRC_CHIRP_H_
