#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "LEDUtils.h"

namespace kaleidoscope {
class LEDRainbowEffect : public LEDMode {
 public:
  LEDRainbowEffect(void) {}
  void update(void) final;

  int8_t hue_steps = 1;
  uint8_t update_delay = 40;
  uint8_t saturation = 255;
  uint8_t brightness = 50;

 private:
  uint8_t hue = 0;
  uint16_t last_update = 0;
};


class LEDRainbowWaveEffect : public LEDMode {
 public:
  LEDRainbowWaveEffect(void) {}
  void update(void) final;

  int8_t hue_steps = 1;
  uint8_t update_delay = 40;
  uint8_t saturation = 255;
  uint8_t brightness = 50;

 private:
  uint8_t hue = 0;
  uint16_t last_update = 0;
};
}

extern kaleidoscope::LEDRainbowEffect LEDRainbowEffect;
extern kaleidoscope::LEDRainbowWaveEffect LEDRainbowWaveEffect;
