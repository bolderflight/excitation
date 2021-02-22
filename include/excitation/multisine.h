/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
*/

#ifndef INCLUDE_EXCITATION_MULTISINE_H_
#define INCLUDE_EXCITATION_MULTISINE_H_

#include <array>
#include "Eigen/Core"
#include "Eigen/Dense"

namespace excitation {

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

}  // namespace excitation

#endif  // INCLUDE_EXCITATION_MULTISINE_H_
