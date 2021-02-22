/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
*/

#ifndef INCLUDE_EXCITATION_SAMPLED_H_
#define INCLUDE_EXCITATION_SAMPLED_H_

#include <array>
#include "Eigen/Core"
#include "Eigen/Dense"

namespace excitation {

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

}  // namespace excitation

#endif  // INCLUDE_EXCITATION_SAMPLED_H_
