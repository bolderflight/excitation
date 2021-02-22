# excitation
This library contains airdata functions.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *excitation*. The header is added as:

```
#include "excitation/excitation.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *excitation_example*. The example executable source file is located at *examples/excitation_example.cc*.

## Namespace
This library is within the namespace *excitation*.

### Pulse
This class implements a pulse.

**Pulse(float dur_s, float amp)** Creates a pulse, specifying the pulse duration (seconds) and amplitude.

```C++
/* Creates a 10 second pulse, amplitude of 2 */
excitation::Pulse pulse(10.0f, 2.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = pulse.Run(3.0f);
```

### Pulse1Cos
This class implements a 1-cos pulse.

**Pulse1Cos(float dur_s, float amp)** Creates a pulse, specifying the duration of the 1-cos (seconds), pause time at peak amplitude (seconds), and amplitude. The total duration of the pulse is the 1-cos duration plus the pause time.

```C++
/* Creates a 10 second 1-cos pulse, a 2 second pause, amplitude of 2 */
excitation::Pulse1Cos pulse(10.0f, 2.0f, 2.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = pulse.Run(3.0f);
```

### Doublet
This class implements a doublet.

**Doublet(float dur_s, float amp)** Creates a doublet give the duration of one of the steps (seconds) and amplitude. The total duration of the excitation is 2 times the step duration.

```C++
/* Creates a 5 second doublet, amplitude of 2 */
excitation::Doublet doublet(5.0f, 2.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = doublet.Run(3.0f);
```

### Doublet121
This class implements a 1-2-1 doublet.

**Doublet121(float dur_s, float amp)** Creates a 1-2-1 doublet give the duration of one of the steps (seconds) and amplitude. The total duration of the excitation is 4 times the step duration.

```C++
/* Creates a 5 second doublet, amplitude of 2 */
excitation::Doublet121 doublet(5.0f, 2.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = doublet.Run(3.0f);
```

### Doublet3211
This class implements a 3-2-1-1 doublet.

**Doublet3211(float dur_s, float amp)** Creates a 3-2-1-1 doublet give the duration of one of the steps (seconds) and amplitude. The total duration of the excitation is 7 times the step duration.

```C++
/* Creates a 5 second doublet, amplitude of 2 */
excitation::Doublet3211 doublet(5.0f, 2.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = doublet.Run(3.0f);
```

### LinearChirp
This class implements a linear chirp.

**LinearChirp(float dur_s, float amp_start, float amp_stop, float freq_start, float freq_stop)** Creates a linear chirp given the chirp duration (seconds), starting and stopping amplitude, and starting and stoping frequency (rad/s).

```C++
/* Creates a 5 second chirp, amplitude from 2 to 0.5 and frequency from 1 rad/s to 6 rad/s */
excitation::LinearChirp chirp(5.0f, 2.0f, 0.5f, 1.0f, 6.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = chirp.Run(3.0f);
```

### LogChirp
This class implements a log chirp.

**LogChirp(float dur_s, float amp_start, float amp_stop, float freq_start, float freq_stop)** Creates a log chirp given the chirp duration (seconds), starting and stopping amplitude, and starting and stoping frequency (rad/s).

```C++
/* Creates a 5 second chirp, amplitude from 2 to 0.5 and frequency from 1 rad/s to 6 rad/s */
excitation::LogChirp chirp(5.0f, 2.0f, 0.5f, 1.0f, 6.0f);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = chirp.Run(3.0f);
```

### MultiSine
This class implements a multisine.

**MultiSine(float dur_s, const Eigen::Matrix<float, N, 1> &amp, const Eigen::Matrix<float, N, 1> &freq, const Eigen::Matrix<float, N, 1> &phase)** Creates a multisine excitation given the duration and vectors of the amplitude, frequency (rad/s), and phase (rad). Note that these vectors must be the same length and the length is specified via a template parameter on the class.

```C++
  Eigen::Matrix<float, 5, 1> frequency; 
  frequency << 0.6283185307179586, 4.360530603182633, 8.092742675647308, 11.824954748111981, 15.557166820576658;
  Eigen::Matrix<float, 5, 1> phase; 
  phase << 6.174200357528524, 5.448037839217776, 3.8454607850193847, 1.6650584957876886, 3.9242402680243402;
  Eigen::Matrix<float, 5, 1> amplitude; 
  amplitude << 0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396;
  /* 10 second multisine with the given amplitude, frequency, and phase vectors */
  excitation::MultiSine<5> multisine(10.0f, amplitude, frequency, phase);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = multisine.Run(3.0f);
```

### Sampled
This class implements a user-defined excitation.

**Sampled(float dur_s, float dt_s, const std::array<float, N> &samp)** Creates a user-defined excitation specifying the excitation duration (seconds), sample rate of the provided data (seconds), and an array of output values. Note that this class simply computes the appropriate index in the array of output values, based on the input time and sample rate, and outputs that value. No interpolation or extrapolation is used.

```C++
/* 10 second duration excitation defined by the array samp, which is spaced at 1 second intervals */
std::array<float, 10> samp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
excitation::Sampled<10> sampled(10, 1, samp);
```

**float Run(float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = sampled.Run(3.0f);
```
