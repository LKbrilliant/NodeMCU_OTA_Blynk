/* Code by - LKBrilliant
 * Date    - 26-Jul-2018
 * 
 * Description - For the first time the code needs to be uploaded using a method other than
 *               wifi(using serial). after the first upload, any other uploads can be done 
 *               Over the Air method.
 *               NodeMCU's inbuild LED is used for indicating the connection between the 
 *               ESP and Blynk cloud.
*/

#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <BlynkSimpleEsp8266.h>

#define LEDpin     16

// Blynk wifi credentials
char auth[] = "*******************************";
char ssid[] = "***********";
char pass[] = "***********";

long t = 0;

BlynkTimer statusCheck;

void setup() {
  pinMode(LEDpin, OUTPUT);
  Blynk.begin(auth, ssid, pass);

  // ArduinoOTA.setPort(8266);            // Port defaults to 8266
  ArduinoOTA.setHostname("NodeMCU");      // Hostname
  ArduinoOTA.setPassword("123");          // Authentication

  ArduinoOTA.begin();

  // the time interval should be grater than the total time it takes to run the EVENT, otherwise the device will restart
  statusCheck.setInterval(1000L, checker);
}

void loop() {
  ArduinoOTA.handle();
  Blynk.run();
  statusCheck.run();
}

void checker() {                       // Check whether a connection is established and indicate it with inbuild LED
  if (Blynk.connected()) {
    digitalWrite(LEDpin, LOW);
  }
  else {
    while ((millis() - t) < 600) {
      digitalWrite(LEDpin, LOW);
    }
    digitalWrite(LEDpin, HIGH);
  }
}
