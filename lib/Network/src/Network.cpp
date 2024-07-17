#include <Network.h>

Network::Network(String ssid, String pass) {
  this->ssid = ssid;
  this->pass = pass;
}

void Network::connect() {
  Serial.print("Connecting to ");
  Serial.print(ssid);

  this->setupEvents();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}

void Network::setupEvents() {
  WiFi.disconnect(true);
  delay(1000);
  WiFi.onEvent(
    [this](WiFiEvent_t event, WiFiEventInfo_t info) { this->WiFiStationConnected(event, info); },
    WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED);

  WiFi.onEvent([this](WiFiEvent_t event, WiFiEventInfo_t info) { this->WiFiGotIP(event, info); },
               WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_GOT_IP);

  WiFi.onEvent(
    [this](WiFiEvent_t event, WiFiEventInfo_t info) { this->WiFiStationDisconnected(event, info); },
    WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);
}

void Network::WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println("Connected to AP successfully!");
}

void Network::WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println("WiFi connected. Obtained IP.");
  Serial.println("Local IP address: ");
  Serial.println(WiFi.localIP());
}

void Network::WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println("Disconnected from WiFi access point");
  Serial.print("WiFi lost connection. Reason: ");
  Serial.println(info.wifi_sta_disconnected.reason);
  Serial.println("Trying to Reconnect");
  WiFi.begin(ssid, pass);
}

Network::~Network() {}