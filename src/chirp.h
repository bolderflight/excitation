/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2023 Bolder Flight Systems Inc
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

#ifndef EXCITATION_SRC_CHIRP_H_  // NOLINT
#define EXCITATION_SRC_CHIRP_H_

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <cstddef>
#include <cmath>
#endif

namespace bfs {

class LinearChirp {
 public:
  LinearChirp(const float dur_s, const float amp_start, const float amp_stop,
              const float freq_start, const float freq_stop)
              : dur_s_(dur_s), amp_start_(amp_start),
              amp_stop_(amp_stop), freq_start_(freq_start),
              freq_stop_(freq_stop),
              freq_slope_((freq_stop_ - freq_start_) / dur_s_),
              amp_slope_((amp_stop_ - amp_start_) / dur_s_) {}
  float Run(const float time_s);

 private:
  const float dur_s_;
  const float amp_start_, amp_stop_;
  const float freq_start_, freq_stop_;
  const float freq_slope_, amp_slope_;
  float freq_, amp_;
};

class LogChirp {
 public:
  LogChirp(const float dur_s, const float amp_start, const float amp_stop,
           const float freq_start, const float freq_stop)
           : dur_s_(dur_s), amp_start_(amp_start), amp_stop_(amp_stop),
           freq_start_(freq_start), freq_stop_(freq_stop),
           freq_slope_(powf(freq_stop_ / freq_start_, 1.0f / dur_s_)),
           freq_log_(logf(freq_slope_)),
           amp_slope_((amp_stop_ - amp_start_) / dur_s_) {}

  float Run(const float time_s);

 private:
  const float dur_s_;
  const float amp_start_, amp_stop_;
  const float freq_start_, freq_stop_;
  const float freq_slope_, freq_log_, amp_slope_;
  float freq_, amp_;
};

}  // namespace bfs

#endif  // EXCITATION_SRC_CHIRP_H_ NOLINT
