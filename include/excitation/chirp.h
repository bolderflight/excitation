/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
*/

#ifndef INCLUDE_EXCITATION_CHIRP_H_
#define INCLUDE_EXCITATION_CHIRP_H_

#include <cmath>

namespace excitation {

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

}  // namespace excitation

#endif  // INCLUDE_EXCITATION_CHIRP_H_
