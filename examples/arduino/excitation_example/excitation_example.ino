/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
*/

#include "excitation.h"

void setup() {
  /* Pulse */
  bfs::Pulse pulse(10.0f, 2.0f);
  /* 1-cos Pulse */
  bfs::Pulse1Cos pulse1cos(10.0f, 2.0f, 2.0f);
  /* Doublet */
  bfs::Doublet doublet(5.0f, 2.0f);
  /* 1-2-1 Doublet */
  bfs::Doublet121 doublet121(5.0f, 2.0f);
  /* 3-2-1-1 Doublet */
  bfs::Doublet3211 doublet3211(5.0f, 2.0f);
  /* Linear Chirp */
  bfs::LinearChirp linear_chirp(5.0f, 2.0f, 0.5f, 1.0f, 6.0f);
  /* Log Chirp */
  bfs::LogChirp log_chirp(5.0f, 2.0f, 0.5f, 1.0f, 6.0f);
  /* Multisine */
  Eigen::Matrix<float, 5, 1> frequency; 
  frequency << 0.6283185307179586, 4.360530603182633, 8.092742675647308, 11.824954748111981, 15.557166820576658;
  Eigen::Matrix<float, 5, 1> phase; 
  phase << 6.174200357528524, 5.448037839217776, 3.8454607850193847, 1.6650584957876886, 3.9242402680243402;
  Eigen::Matrix<float, 5, 1> amplitude; 
  amplitude << 0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396;
  bfs::MultiSine<5> multisine(10.0f, amplitude, frequency, phase);
  /* Sampled */
  std::array<float, 10> samp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bfs::Sampled<10> sampled(10, 1, samp);
}

void loop() {}
