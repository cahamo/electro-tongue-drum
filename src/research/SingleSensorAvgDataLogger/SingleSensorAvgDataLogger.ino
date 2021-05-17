/*
 * Electro Tongue Drum
 * 
 * Single sensor avaeraged data logger
 * 
 * The capacitive sensing library takes a specified number of samples to determine each
 * sensor reading. The number of samples is specified by the SAMPLES symbol below. The
 * values returned from the library are averaged over the last AVG_SIZE results.
 * 
 * The results of each sensor reading are written to the serial port in comma delimited
 * format.
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
#define SAMPLES 20

// Number of results from the CapacitiveSensor Library to be averaged
// ** Change this value to test different numbers of results to be averaged
#define AVG_SIZE 4

// Used in getReading to average last AVG_SIZE results
long readings[AVG_SIZE];
int readIndex = 0;

CapacitiveSensor cs = CapacitiveSensor(OUT_PIN, IN_PIN);

void setup() {
  Serial.begin(9600);
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.println("Reading,Average");
}

void loop() {
  long reading = cs.capacitiveSensor(SAMPLES);
  long avg = getAvgReading(reading);
  Serial.print(reading);
  Serial.print(",");
  Serial.println(avg);
  delay(20);
}

long getAvgReading(long value) {
  
  static long total = 0;
  if (AVG_SIZE == 1) {
    return value;
  }
  
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = value;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex++;

  // if we're at the end of the array...
  if (readIndex >= AVG_SIZE) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  return total / AVG_SIZE;
}
