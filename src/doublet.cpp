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

#if defined(ARDUINO)
#include <Arduino.h>
#endif

#include "doublet.h"  // NOLINT

namespace bfs {

float Doublet::Run(const float time_s) const {
  if (time_s < dur_s_) {
    return amp_;
  } else if (time_s < 2.0f * dur_s_) {
    return -amp_;
  } else {
    return 0.0f;
  }
}

float Doublet121::Run(const float time_s) const {
  if (time_s < dur_s_) {
    return amp_;
  } else if (time_s < 3.0f * dur_s_) {
    return -amp_;
  } else if (time_s < 4.0f * dur_s_) {
    return amp_;
  } else {
    return 0.0f;
  }
}

float Doublet3211::Run(const float time_s) const {
  if (time_s < 3.0f * dur_s_) {
    return amp_;
  } else if (time_s < 5.0f * dur_s_) {
    return -amp_;
  } else if (time_s < 6.0f * dur_s_) {
    return amp_;
  } else if (time_s < 7.0f * dur_s_) {
    return -amp_;
  } else {
    return 0.0f;
  }
}

}  // namespace bfs
