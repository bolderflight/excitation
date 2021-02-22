/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
*/

#ifndef INCLUDE_EXCITATION_DOUBLET_H_
#define INCLUDE_EXCITATION_DOUBLET_H_

namespace excitation {

class Doublet {
 public:
  Doublet(float dur_s, float amp) : dur_s_(dur_s), amp_(amp) {}
  inline float Run(const float time_s) const {
    if (time_s < dur_s_) {
      return amp_;
    } else if (time_s < 2.0f * dur_s_) {
      return -amp_;
    } else {
      return 0.0f;
    }
  }

 private:
  float dur_s_, amp_;
};

class Doublet121 {
 public:
  Doublet121(float dur_s, float amp) : dur_s_(dur_s), amp_(amp) {}
  inline float Run(const float time_s) const {
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

 private:
  float dur_s_, amp_;
};

class Doublet3211 {
 public:
  Doublet3211(float dur_s, float amp) : dur_s_(dur_s), amp_(amp) {}
  inline float Run(const float time_s) const {
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

 private:
  float dur_s_, amp_;
};

}  // namespace excitation

#endif  // INCLUDE_EXCITATION_DOUBLET_H_
