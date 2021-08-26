# electro-tongue-drum

A project to build an electronic version of a tongue drum featuring touch sensitive keys.

This repository contains the project's Arduino source code. A description of the project along with details of progress can be found on the [Electro-Tongue Drum](https://cahamo.github.io/tongue-drum/) page of the [Cahamo](https://cahamo.github.io/) website.

## Contents

The repo's source code is all contained in sub-directories of the `src` directory.

Code relating to research and experimentation is contained in sub-directories of the `research` sub-directory.

Current projects are:

### `research/SingleSensorRawDataLogger`

Uses Arduino Uno pins 2 and 3 to detect touches on a single attached touch sensor using the CapacitiveSensor library. Readings from the library are repeatedly taken and simply written out to the Uno's serial port.

The data are formatted into columns for display on a serial monitor - either the Arduino IDE's monitor or a 3rd party one. The data is also suitable for display on the Arduino IDE's Serial Plotter.

#### Development environment

* [Arduino IDE](https://www.arduino.cc/en/software)

#### Requires

* [CapacitiveSensor library](https://playground.arduino.cc/Main/CapacitiveSensor/)

#### Used by

* [Experiment #1](https://cahamo.github.io/tongue-drum/experiment-1)
* [Experiment #2](https://cahamo.github.io/tongue-drum/experiment-2)
* [Experiment #3](https://cahamo.github.io/tongue-drum/experiment-3)

#### License

* [MIT](https://cahamo.mit-license.org/)

### `research/SingleSensorAvgDataLogger`

Like `SingleSensorRawDataLogger` this project uses Arduino Uno pins 2 and 3 to detect touches on a single attached touch sensor using the CapacitiveSensor library. However, in this sketch the the average of a specified number of readings is reported over the serial port.

Each reading and its associated rolling average is written in the form of a table on the serial port in a form suitable for a display as text or on the Arduino serial plotter.

#### Development environment

* [Arduino IDE](https://www.arduino.cc/en/software)

#### Requires

* [CapacitiveSensor library](https://playground.arduino.cc/Main/CapacitiveSensor/)

#### Used by

* [Experiment #2](https://cahamo.github.io/tongue-drum/experiment-2)

#### License

* [MIT](https://cahamo.mit-license.org/)

### `research/GuidedSensorTouchDataLogger`

One of the problems encountered when using `SingleSensorRawDataLogger` and `SingleSensorAvgDataLogger` to compare different runs of readings was in getting uniform patterns of sensor touches in each test run.

This sketch was developed to guide the user during each test by emitting a sequence of beeps that count in the test and then indicate when each touch is required.

This script again uses the CapactiveSensor library to detect touches on a single attached touch sensor. Like `SingleSensorRawDataLogger` the number of samples read each time can be configured. Unlike `SingleSensorAvgDataLogger` this sketch does not take average readings, since these were not found to be useful.

Each reading is simply written to the Arduino's serial port, one reading per line. This simplified output makes it easier to import data into spreadsheets and to plot on the Arduino serial plotter.

#### Development environment

* [Arduino IDE](https://www.arduino.cc/en/software)

#### Requires

* [CapacitiveSensor library](https://playground.arduino.cc/Main/CapacitiveSensor/)

#### Used by

* [Experiment #4](https://cahamo.github.io/tongue-drum/experiment-4)
* [Experiment #5](https://cahamo.github.io/tongue-drum/experiment-5)

#### License

* [MIT](https://cahamo.mit-license.org/)
