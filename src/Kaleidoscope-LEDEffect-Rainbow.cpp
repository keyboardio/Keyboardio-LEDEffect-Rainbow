#include "Kaleidoscope-LEDEffect-Rainbow.h"

namespace kaleidoscope {

void LEDRainbowEffect::update(void) {
  uint16_t now = millis();
  if ((now - last_hue_update) < hue_update_interval) {
    if (!breathe) { // no updates either due to hue change or breathing
      return;
    }
  } else {
    hue += hue_steps;
    last_hue_update = now;
  }

  cRGB rainbow = breathe ?
                 breath_compute_helper(hue, saturation, now) :
                 hsvToRgb(hue, saturation, brightness);
  ::LEDControl.set_all_leds_to(rainbow);
}

// ---------

void LEDRainbowWaveEffect::update(void) {
  uint16_t now = millis();
  if ((now - last_hue_update) < hue_update_interval) {
    if (!breathe) { // no updates either due to hue change or breathing
      return;
    }
  } else {
    hue += hue_steps;
    last_hue_update = now;
  }

  for (uint8_t i = 0; i < LED_COUNT; i++) {
    uint16_t key_hue = hue + 16 * (i / 4);
    if (key_hue >= 255) {
      key_hue -= 255;
    }
    cRGB rainbow = breathe ?
                   breath_compute_helper(key_hue, saturation, now) :
                   hsvToRgb(key_hue, saturation, brightness);
    ::LEDControl.setCrgbAt(i, rainbow);
  }
}

}

kaleidoscope::LEDRainbowEffect LEDRainbowEffect;
kaleidoscope::LEDRainbowWaveEffect LEDRainbowWaveEffect;
