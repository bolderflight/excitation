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


#include <iostream>
#include "excitation.h"

int main() {
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
  // /* Multisine */
  float freq[5] = {0.6283185307179586, 4.360530603182633, 8.092742675647308, 11.824954748111981, 15.557166820576658};
  float phase[5] = {6.174200357528524, 5.448037839217776, 3.8454607850193847, 1.6650584957876886, 3.9242402680243402};
  float amp[5] = {0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396};
  bfs::MultiSine multisine(10.0f);
  /* Sampled */
  float samp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bfs::Sampled sampled(10, 1);
  return 0;
}
