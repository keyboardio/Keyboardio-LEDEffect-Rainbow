#include "Kaleidoscope-LEDEffect-Rainbow.h"

namespace kaleidoscope {

void LEDRainbowEffect::update(void) {
  uint16_t now = millis();
  if ((now - last_update) < update_delay) {
    return;
  } else {
    hue += hue_steps;
    last_update = now;
  }

  cRGB rainbow = hsvToRgb(hue, saturation, brightness);
  ::LEDControl.set_all_leds_to(rainbow);
}

// ---------

void LEDRainbowWaveEffect::update(void) {
  uint16_t now = millis();
  if ((now - last_update) < update_delay) {
    return;
  } else {
    hue += hue_steps;
    last_update = now;
  }

  for (uint8_t i = 0; i < LED_COUNT; i++) {
    uint16_t key_hue = hue + 16 * (i / 4);
    if (key_hue >= 255) {
      key_hue -= 255;
    }
    cRGB rainbow = hsvToRgb(key_hue, saturation, brightness);
    ::LEDControl.setCrgbAt(i, rainbow);
  }
}
}

kaleidoscope::LEDRainbowEffect LEDRainbowEffect;
kaleidoscope::LEDRainbowWaveEffect LEDRainbowWaveEffect;
