# NodeMCU_OTA_Blynk
Over the Air firmware upload to NodeMCU (ESP8266)

This code can be used to upload codes using Arduino IDE Over the Air to NodeMCU(ESP8266). Because of using Blynk, NodeMCU can connect to a router using Blynk.begin() function.

Use the basic_OTA.ino as the base code and develop on top of it.

Commands in the basic_OTA.ino must be included in every update. Otherwise, OTA function will not be available after the upload
