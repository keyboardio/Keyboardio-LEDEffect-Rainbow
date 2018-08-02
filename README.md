# Kaleidoscope-LEDEffect-Rainbow

![status][st:stable] [![Build Status][travis:image]][travis:status]

 [travis:image]: https://travis-ci.org/keyboardio/Kaleidoscope-LEDEffect-Rainbow.svg?branch=master
 [travis:status]: https://travis-ci.org/keyboardio/Kaleidoscope-LEDEffect-Rainbow

 [st:stable]: https://img.shields.io/badge/stable-✔-black.svg?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.svg?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.svg?style=flat&colorA=dfb317&colorB=494e52

Two colorful rainbow effects are implemented by this plugin: one where the
rainbow waves through the keys, and another where the LEDs breathe though the
colors of a rainbow. The difference is that in the first case, we have all the
rainbow colors on display, and it waves through the keyboard. In the second
case, we have only one color at a time, for the whole board, and the color
cycles through the rainbow's palette.

## Using the extension

To use the plugin, include the header, and tell the firmware to use either (or
both!) of the effects:

```c++
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LEDEffect-Rainbow.h>

KALEIDOSCOPE_INIT_PLUGINS(LEDRainbowEffect, LEDRainbowWaveEffect);

void setup() {
  Kaleidoscope.setup();

  LEDRainbowEffect.breathe = true;
  LEDRainbowEffect.hue_update_interval = 128;
  // to get a full hue cycle in ‘n’ breath cycles,
  // set the hue_update_interval to ‘n × 16’

  LEDRainbowWaveEffect.saturation = 200;
  LEDRainbowWaveEffect.hue_steps = -1;
  LEDRainbowWaveEffect.brightness = 150;
}
```

## Plugin properties

The plugin provides two objects: `LEDRainbowEffect`, and `LEDRainbowWaveEffect`,
both of which provide the following properties:

### `.hue_steps`

> The number of steps the hue is changed every `hue_update_interval`
> milliseconds. Smaller values make smoother rainbows. Negative values make
> reverse rainbows.
>
> Defaults to +1.

### `.hue_update_interval`

> The number of milliseconds between hue updates. Smaller values make faster
> rainbows.
>
> Defaults to 40.

### `.saturation`

> The saturation of the rainbow colors. Lesser values result in more pastel
> colors and greater ones result in more vibrant colors.
>
> Defaults to 255 (max).

### `.breathe`

> Whether the rainbow effect is to be mixed with a "breathe" effect or not.
>
> Defaults to `false`.

### `.brightness`

> The LED brightness for the effect if breathing is not enabled.
>
> Defaults to 50.

## Dependencies

* [Kaleidoscope-LEDControl](https://github.com/keyboardio/Kaleidoscope-LEDControl)
