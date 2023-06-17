[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Excitation
This library contains functions to create excitation waveforms for exciting a system and measuring its response. This library is compatible with Arduino and with CMake build systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Installation

## Arduino
Use the Arduino Library Manager to install this library or clone to your Arduino/libraries folder. In addition, this library requires the [Bolder Flight Systems Units library](https://github.com/bolderflight/units) to be installed. This library is added as:

```C++
#include "excitation.h"
```

An example Arduino executable is located at *examples/arduino/excitation_example/excitation_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other devices.

## CMake
CMake is used to build this library, which is exported as a library target called *excitation*. The header is added as:

```C++
#include "excitation.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *excitation_example*. The example executable source file is located at *examples/cmake/excitation_example.cc*.

# Namespace
This library is within the namespace *bfs*.

# Pulse
This class implements a pulse.

**Pulse(const float dur_s, const float amp)** Creates a pulse, specifying the pulse duration (seconds) and amplitude.

```C++
/* Creates a 10 second pulse, amplitude of 2 */
bfs::Pulse pulse(10.0f, 2.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = pulse.Run(3.0f);
```

# Pulse1Cos
This class implements a 1-cos pulse.

**Pulse1Cos(const float dur_s, const float pause_s, const float amp)** Creates a pulse, specifying the duration of the 1-cos (seconds), pause time at peak amplitude (seconds), and amplitude. The total duration of the pulse is the 1-cos duration plus the pause time.

```C++
/* Creates a 10 second 1-cos pulse, a 2 second pause, amplitude of 2 */
bfs::Pulse1Cos pulse(10.0f, 2.0f, 2.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = pulse.Run(3.0f);
```

# Doublet
This class implements a doublet.

**Doublet(const float dur_s, const float amp)** Creates a doublet give the duration of one of the steps (seconds) and amplitude. The total duration of the excitation is 2 times the step duration.

```C++
/* Creates a 5 second doublet, amplitude of 2 */
bfs::Doublet doublet(5.0f, 2.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = doublet.Run(3.0f);
```

# Doublet121
This class implements a 1-2-1 doublet.

**Doublet121(const float dur_s, const float amp)** Creates a 1-2-1 doublet give the duration of one of the steps (seconds) and amplitude. The total duration of the excitation is 4 times the step duration.

```C++
/* Creates a 5 second doublet, amplitude of 2 */
bfs::Doublet121 doublet(5.0f, 2.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = doublet.Run(3.0f);
```

# Doublet3211
This class implements a 3-2-1-1 doublet.

**Doublet3211(const float dur_s, const float amp)** Creates a 3-2-1-1 doublet give the duration of one of the steps (seconds) and amplitude. The total duration of the excitation is 7 times the step duration.

```C++
/* Creates a 5 second doublet, amplitude of 2 */
bfs::Doublet3211 doublet(5.0f, 2.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = doublet.Run(3.0f);
```

# LinearChirp
This class implements a linear chirp.

**LinearChirp(const float dur_s, const float amp_start, const float amp_stop, const float freq_start, const float freq_stop)** Creates a linear chirp given the chirp duration (seconds), starting and stopping amplitude, and starting and stoping frequency (rad/s).

```C++
/* Creates a 5 second chirp, amplitude from 2 to 0.5 and frequency from 1 rad/s to 6 rad/s */
bfs::LinearChirp chirp(5.0f, 2.0f, 0.5f, 1.0f, 6.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = chirp.Run(3.0f);
```

# LogChirp
This class implements a log chirp.

**LogChirp(const float dur_s, const float amp_start, const float amp_stop, const float freq_start, const float freq_stop)** Creates a log chirp given the chirp duration (seconds), starting and stopping amplitude, and starting and stoping frequency (rad/s).

```C++
/* Creates a 5 second chirp, amplitude from 2 to 0.5 and frequency from 1 rad/s to 6 rad/s */
bfs::LogChirp chirp(5.0f, 2.0f, 0.5f, 1.0f, 6.0f);
```

**float Run(const float time_s)** Computes the excitation output given the time since the start of the excitation.

```C++
/* Get the excitation output at 3 seconds */
float y = chirp.Run(3.0f);
```

# MultiSine
This class implements a multisine.

**MultiSine(const float dur_s)** Creates a multisine excitation given the duration.

```C++
  /* 10 second multisine */
  bfs::MultiSine multisine(10.0f);
```

**float Run(const float time_s, float &ast; const amp, float &ast; const freq, float &ast; const phase, const size_t len)** Computes the excitation output given the time since the start of the excitation, pointers to arrays and of the amplitude, frequency (rad/s), and phase (rad) and the length of the arrays. Note that the arrays must all be the same length.

```C++
float freq[5] = {0.6283185307179586, 4.360530603182633, 8.092742675647308, 11.824954748111981, 15.557166820576658};
float phase[5] = {6.174200357528524, 5.448037839217776, 3.8454607850193847, 1.6650584957876886, 3.9242402680243402};
float amp[5] = {0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396, 0.19810717087274396};
/* Get the excitation output at 3 seconds */
float y = multisine.Run(3.0f, amp, freq, phase, 5);
```

# Sampled
This class implements a user-defined excitation.

**Sampled(const float dur_s, const float dt_s)** Creates a user-defined excitation specifying the excitation duration (seconds) and sample rate of the provided data (seconds).

```C++
/* 10 second duration excitation defined by the array samp, which is spaced at 1 second intervals */
bfs::Sampled<10> sampled(10, 1);
```

**float Run(const float time_s, float &ast; const data, const size_t len)** Computes the excitation output given the time since the start of the excitation and an array of output values. Note that this class simply computes the appropriate index in the array of output values, based on the input time and sample rate, and outputs that value. No interpolation or extrapolation is used.

```C++
/* Get the excitation output at 3 seconds */
float samp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float y = sampled.Run(3.0f, samp, 10);
```
