#ifndef NETWORK_H
#define NETWORK_H

#include <WiFi.h>

class Network {
 private:
  String ssid;
  String pass;

 public:
  Network(String ssid, String pass);
  void connect();
  void setupEvents();
  void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info);
  void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info);
  void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info);

  ~Network();
};

#endif  // NETWORK_H