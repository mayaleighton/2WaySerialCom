/* 
 * Project 2WaySerialCom
 * Author: Dylan White and Emily 
 * Date: 10/07/2024
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
const pin_t onBoardLED = D6;



// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// setup() runs once, when the device is first turned on
void setup() {
  // Put initialization like pinMode and begin functions here
Serial1.begin(9600);

pinMode(onBoardLED, OUTPUT);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

String dataToSend = "Happy Birthday Maya";

Serial1.print(dataToSend);

digitalWrite(onBoardLED, HIGH);
delay(500);
digitalWrite(onBoardLED, LOW);

delay(1500);
  
  // Particle.publish("Hello world!");
  // delay( 10 * 1000 ); // milliseconds and blocking - see docs for more info!
}
