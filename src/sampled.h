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

#ifndef SRC_SAMPLED_H_
#define SRC_SAMPLED_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <cstddef>
#include <array>
#include "eigen.h"  // NOLINT
#include "Eigen/Dense"

namespace bfs {

template<std::size_t N>
class Sampled {
 public:
  Sampled(float dur_s, float dt_s, const std::array<float, N> &samp) :
          dur_s_(dur_s), dt_s_(dt_s), samp_(samp) {}
  inline float Run(const float time_s) {
    if (time_s < dur_s_) {
      return samp_[static_cast<std::size_t>(time_s / dt_s_)];
    } else {
      return 0.0f;
    }
  }

 private:
  float dur_s_, dt_s_;
  std::array<float, N> samp_;
};

}  // namespace bfs

#endif  // SRC_SAMPLED_H_
