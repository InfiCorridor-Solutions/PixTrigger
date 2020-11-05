# PixTrigger
A free and open source tool to trigger cameras using Pixhawk and Raspberry Pi

Wiring PI is already present on the raspi, if not then follow this: http://wiringpi.com/download-and-install/

Compile the gpio.c file like this
> cc gpio.c -I/usr/local/include -L/usr/local/lib -lwiringPi
