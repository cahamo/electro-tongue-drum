/*
 * Electro Tongue Drum
 *
 * Single sensor data logger that guides the user through a preset test pattern of
 * touches on the sensor using a sequence of buzzer beeps.
 *
 * The capacitive sensing library takes a specified number of samples to determine each
 * sensor reading. The number of samples is specified by the SAMPLES symbol below.
 *
 * Each reading is sent to the serial report, foloowed by a new line.
 * The results can either be displayed in a serial Monitor or on a plotter.
 *
 */


// Import the CapacitiveSensor Library
#include <CapacitiveSensor.h>

// CapacitiveSensor Library takes SAMPLES samples per call
// ** Change this value to test different sample sizes: range is 1..255
#define SAMPLES 25

#define OUT_PIN     2 // pin that sends signal to be used for detection
#define IN_PIN      3 // pin that receives returned signal that is measured against sent signal
#define BUZZER_PIN 11 // PWM pin that is used to send tones to the buzzer

// Length of time segments used for pattern of guiding tones
#define TIME_LONG     700
#define TIME_SHORT    300
#define TIME_V_SHORT  230
#define TIME_TICK      50

// Pitch of tones used for guiding tones in Hz
#define TICK_TONE    1200
#define TOUCH_TONE    440
#define SILENCE         0   // special value used for silence

// Length of each segment of pattern of guiding tones and silence
long segments[] {
  TIME_TICK,    TIME_SHORT,   TIME_TICK,    TIME_SHORT,   TIME_TICK,    TIME_SHORT,
  TIME_LONG,    TIME_SHORT,   TIME_TICK,    TIME_SHORT,
  TIME_LONG,    TIME_SHORT,   TIME_TICK,    TIME_SHORT,
  TIME_LONG,    TIME_SHORT,   TIME_TICK,    TIME_SHORT,
  TIME_V_SHORT, TIME_SHORT,   TIME_V_SHORT, TIME_SHORT,   TIME_V_SHORT, TIME_LONG
};

// Pitch of tones played in each segment
long tones[] {
  TICK_TONE,    SILENCE,      TICK_TONE,    SILENCE,      TICK_TONE,    SILENCE,
  TOUCH_TONE,   SILENCE,      TICK_TONE,    SILENCE,
  TOUCH_TONE,   SILENCE,      TICK_TONE,    SILENCE,
  TOUCH_TONE,   SILENCE,      TICK_TONE,    SILENCE,
  TOUCH_TONE,   SILENCE,      TOUCH_TONE,   SILENCE,      TOUCH_TONE,   SILENCE
};

int segmentCount = int(sizeof tones / sizeof tones[0]);
long counter = 0;
long reading;
int index = -1;
unsigned long lastTime;
unsigned long elapsedTime;
unsigned long timeNow;

CapacitiveSensor cs = CapacitiveSensor(OUT_PIN, IN_PIN);

void setup() {
  pinMode(BUZZER_PIN,OUTPUT);
  Serial.begin(9600);
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
}

void loop() {
  timeNow = millis();
  elapsedTime = timeNow - lastTime;
  if (index < segmentCount) {
    reading = cs.capacitiveSensor(SAMPLES);
    Serial.println(reading);
    if (counter <= 0) {
      index++;
      counter = segments[index];
      makeSound(tones[index]);
    }
    else {
      counter -= elapsedTime;
    }
  }
  else {
    noTone(BUZZER_PIN);
  }
  lastTime = timeNow;
}

void makeSound(unsigned int freq) {
  if (freq > 0) {
    tone(BUZZER_PIN, freq);
  }
  else {
    noTone(BUZZER_PIN);
  }
}
