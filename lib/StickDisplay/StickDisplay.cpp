#include <StickDisplay.h>

StickDisplay::StickDisplay() {
  M5.begin();

  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("Display initialization ...");
}

StickDisplay::~StickDisplay() {}
