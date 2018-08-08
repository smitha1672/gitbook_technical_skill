## [Getting started with the Raspberry Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-getting-started)
## [Sense-HAT-V1.0 Hardware](https://www.raspberrypi.org/documentation/hardware/sense-hat/images/Sense-HAT-V1_0.pdf)
## [Build Kernal](https://www.raspberrypi.org/documentation/linux/kernel/building.md)
## [github resource](https://github.com/raspberrypi)
### sense hat source

[getting started with the sense hat](https://projects.raspberrypi.org/en/projects/getting-started-with-the-sense-hat)
```text
./drivers/video/fbdev/rpisense-fb.c:2: * Raspberry Pi Sense HAT framebuffer driver
./drivers/video/fbdev/rpisense-fb.c:290:MODULE_DESCRIPTION("Raspberry Pi Sense HAT framebuffer driver");
./drivers/input/joystick/rpisense-js.c:2: * Raspberry Pi Sense HAT joystick driver
./drivers/input/joystick/rpisense-js.c:75:      rpisense_js->keys_dev->name = "Raspberry Pi Sense HAT Joystick";
./drivers/input/joystick/rpisense-js.c:151:MODULE_DESCRIPTION("Raspberry Pi Sense HAT joystick driver");
./drivers/mfd/rpisense-core.c:2: * Raspberry Pi Sense HAT core driver
./drivers/mfd/rpisense-core.c:77:                "Raspberry Pi Sense HAT firmware version %i\n", ret);
./drivers/mfd/rpisense-core.c:154:MODULE_DESCRIPTION("Raspberry Pi Sense HAT core driver");
./include/linux/mfd/rpisense/joystick.h:2: * Raspberry Pi Sense HAT joystick driver
./include/linux/mfd/rpisense/framebuffer.h:2: * Raspberry Pi Sense HAT framebuffer driver
./include/linux/mfd/rpisense/core.h:2: * Raspberry Pi Sense HAT core driver
```

