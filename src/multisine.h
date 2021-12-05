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

#ifndef SRC_MULTISINE_H_
#define SRC_MULTISINE_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <cstddef>
#include <array>
#include "eigen.h"  // NOLINT
#include "Eigen/Dense"

namespace bfs {

template<std::size_t N>
class MultiSine {
 public:
  MultiSine(float dur_s,
            const Eigen::Matrix<float, N, 1> &amp,
            const Eigen::Matrix<float, N, 1> &freq,
            const Eigen::Matrix<float, N, 1> &phase) :
            amp_(amp), freq_(freq), phase_(phase) {}
  inline float Run(const float time_s) {
    if (time_s < dur_s_) {
      return (amp_ * (freq_ * time_s + phase_).sinf()).sumf();
    } else {
      return 0.0f;
    }
  }

 private:
  float dur_s_;
  Eigen::Matrix<float, N, 1> amp_;
  Eigen::Matrix<float, N, 1> freq_;
  Eigen::Matrix<float, N, 1> phase_;
};

}  // namespace bfs

#endif  // SRC_MULTISINE_H_
