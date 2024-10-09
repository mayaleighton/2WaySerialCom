/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);


// setup() runs once, when the device is first turned on
void setup() {
  // Initialize Serial1 for UART communication
  Serial1.begin(9600);   // Start UART communication with baud rate 9600

  // Initialize serial monitor communication
  Serial.begin(9600);    // Start Serial for printing to the monitor
}

void loop() {
  // Check if data is available to read from Serial1
  if (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');  // Read incoming data
    Serial.println(receivedData);                         // Print data to serial monitor
  }
}
