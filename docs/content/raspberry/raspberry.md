## Resource
[Getting started with the Raspberry Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-getting-starteda) <br>
[Sense-HAT-V1.0 Hardware](https://www.raspberrypi.org/documentation/hardware/sense-hat/images/Sense-HAT-V1_0.pdf) <br>
[Build Kernal](https://www.raspberrypi.org/documentation/linux/kernel/building.md)

## Exploring Raspberry pi
[Book](http://porn.jules-aubert.info/cul/humble_ebooks/DIY%20Electronics/exploring_raspberry_pi.pdf) <br>
[The website for this book](http://exploringrpi.com/) <br>
[derekmolly blog](www.derekmolloy.ie) <br>
[example](https://github.com/derekmolloy/exploringrpi)

## Hardware Moudule/Equiement

+ [GPIO Extension Board](https://www.taiwaniot.com.tw/product/gpio-t-cobbler-plus/) <br>
<img src="https://www.taiwaniot.com.tw/wp-content/uploads/2015/12/TB2Sf6UbXXXXXaXXXXXXXXXXXXX_811505400.jpg"
width="50%"
height="50%"
alt="GPIO Extension Board"
align=center />

+ [Digilent Analog Discovery 2](https://makehub.tw/spot/tol-13929) <br>
<img src="https://cdn.sparkfun.com/assets/parts/1/1/6/0/0/13929-09.jpg"
width="50%"
height="50%"
alt="GPIO Extension Board"
align=center />

+ a port-scanning tool

```text
nmap -T4 -F 172.16.3.*
```
+ Raspiberry ssh login

```bash
ssh pi@192.168.1.115
pi@192.168.1.115's password: raspberry
```

## sense hat source

+ [getting started with the sense hat](https://projects.raspberrypi.org/en/projects/getting-started-with-the-sense-hat) <br>
+ [sense hat user space example.1](https://github.com/moshegottlieb/libsense)
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

## Note

+ Bash script code to calcuate the execution duration of each program

```bash
Duration="5000000"
echo -e "\nThe C/C++ Code Example"
T="$(date +%s%N)"
./n-body $Duration
T="$(($(date +%s%N)-T))"
T=$((T/1000000))
echo "It took ${T} milliseconds to run the C/C++ test"
```

+ 


