Intel Edison examples
=====================

The Intel Edison board uses an Atom CPU running Linux Yocto as the operating system. It is designed for DIY Iot (internet of things) applications using the same GPIO setup of the Arduino boards e.g. Arduino UNO.

To get started with the Edison board installing the flashing software and the IDE of your choice you can also check this [gist](https://gist.github.com/tappoz/52901a130c4e892f8d47).

- example involving [a light sensor and a LED](./A_lightSensorWithLEDExample)
- example involving [a sound sensor, a button, an LCD display and a LED](./B_soundSensorEnabledByButton)

To run the code you could use the Arduino IDE making sure the right board and port are selected (from the __Tools__ dropdown menu), then clicking on the __upload__ button.

On my Thinkpad Edge E530, using Linux Ubuntu, the USB ports are not all the same for some reason not strictly related to the USB protocol version (USB 2.0, USB 3.0).
I found myself struggling to connect to the serial port of the board using commands like `screen` even if I was connecting both the J16 and J3 board ports to the laptop USB 3.0 ports.
I found that changing the USB 3.0 ports (I have 3 of them on my laptop) makes the `screen` command work again. 
Say the 3 USB 3.0 ports are on the left side of the laptop (bottom to top):

- J3 connected to the 2nd USB port;
- J16 connected to the 3rd USB port.

