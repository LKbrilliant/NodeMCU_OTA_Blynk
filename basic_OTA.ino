#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <BlynkSimpleEsp8266.h>

// Blynk and wifi credentials
char auth[] = "*******************************";
char ssid[] = "***********";
char pass[] = "***********";

void setup() {
  Blynk.begin(auth, ssid, pass);

  // ArduinoOTA.setPort(8266);            // Port defaults to 8266
  ArduinoOTA.setHostname("NodeMCU");      // Hostname
  //ArduinoOTA.setPassword("123");          // Authentication

  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();
  Blynk.run();
}
