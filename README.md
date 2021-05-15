# electro-tongue-drum

A project to build an electronic version of a tongue drum featuring touch sensitive keys.

This repository contains the project's Arduino source code. A description of the project along with details of progress can be found on the [Electro-Tongue Drum](https://cahamo.github.io/tongue-drum/) page of the [Cahamo](https://cahamo.github.io/) website.

## Contents

The repo's source code is all contained in sub-directories of the `src` directory.

Code relating to research and experimentation is contained in sub-directories of the `research` sub-directory.

Current projects are:

### `research/SingleSensorRawDataLogger`

Uses Arduino Uno pins 2 and 3 to detect touches on a single attached touch sensor using the CapacitiveSensor library. Readings from the library are repeatedly taken and simply written out to the Uno's serial port.

The data is formatted into columns for display on a serial monitor - either the Arduino IDE's monitor or a 3rd party one. The data is also suitable for display on the Arduino IDE's Serial Plotter.

#### Development environment

* [Arduino IDE](https://www.arduino.cc/en/software)

#### Requires

* [CapacitiveSensor library](https://playground.arduino.cc/Main/CapacitiveSensor/)

#### Used by

* [Experiment #1](https://cahamo.github.io/tongue-drum/experiment-1.html)

#### License

* [MIT](https://cahamo.mit-license.org/)
