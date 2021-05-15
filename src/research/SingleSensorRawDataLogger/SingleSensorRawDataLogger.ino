/*
 * Electro Tongue Drum
 * 
 * Single sensor raw data logger
 * 
 * The capacitive sensing library takes a specified number of samples to determine each
 * sensor reading. The number of samples is specified by the SAMPLES symbol below.
 * 
 * The results of each sensor reading are written to the serial port using
 * OUTPUT_COLUMNS of data per line.
 * 
 * The result can either be displayed in a serial Monitor or on a plotter.
 * 
 */


// Import the CapacitiveSensor Library.
#include <CapacitiveSensor.h>

#define OUT_PIN 2   // pin that sends signal to be used for detection
#define IN_PIN 3    // pin that receives returned signal that is measured against sent signal

// CapacitiveSensor Library takes SAMPLES samples per call
// ** Change this value to test different sample sizes: range is 1..255
#define SAMPLES 200

// Number of columns of data to print
#define OUTPUT_COLUMNS 8 

CapacitiveSensor cs = CapacitiveSensor(OUT_PIN, IN_PIN);

void setup() {
  Serial.begin(9600);
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
}

void loop() {
  long reading = cs.capacitiveSensor(SAMPLES);
  static int col = 1;
  if (col < OUTPUT_COLUMNS) {
    Serial.print(reading);
    Serial.print("\t");
    col++;
  }
  else {
    Serial.println(reading);
    col = 1;
  }
}
