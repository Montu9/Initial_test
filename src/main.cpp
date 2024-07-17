#include <Arduino.h>
#include <Network.h>
#include <StickDisplay.h>
#include "config.h"

Network* network;
StickDisplay* display;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Setting up ...");

  display = new StickDisplay();

  network = new Network(WIFI_SSID, WIFI_PASS);
  network->connect();
}

void loop() {}
