/*
 * Electro Tongue Drum
 * 
 * ESP built-in touch sensor raw data logger
 * 
 * This code uses one of the ESP32's built in touch sensor to read input.
 * 
 * We use touch pin 0, which is GPIO pin 4.
 * 
 * The results of each sensor reading are written to the serial port, one
 * reading per line.
 * 
 * The result can either be displayed in a serial Monitor or on a plotter.
 *
 * Adapted from code taken copied from the DroneBot Workshop:
 *   https://dronebotworkshop.com/esp32-intro/
 */

#define TOUCH_PIN T0
#define PAUSE_BETWEEN_READINGS_MS 10

void setup()
{
  Serial.begin(115200);
  delay(1000); // wait for serial monitor
}

void loop()
{
  // Read sensor & output reading
  Serial.println(touchRead(TOUCH_PIN));
  // Wait a bit
  delay(PAUSE_BETWEEN_READINGS_MS);
}
