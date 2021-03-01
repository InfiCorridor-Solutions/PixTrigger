# PixTrigger
A free and open source tool to trigger cameras using Pixhawk and Raspberry Pi (Tested on raspberry pi 3 model b+ and pixhawk 4)

Depenedencies 
MavSDK
ExifTool
gphoto2
cmake

TO DO 
check performance of Exiftool vs Exiv2


USAGE

Install ExifTool to use the code

Download at: https://exiftool.org/Image-ExifTool-12.10.tar.gz
or
https://exiftool.org/index.html

Run these steps, adjust for version
<br>
`cd <your download directory>` <br>
`tar -xf Image-ExifTool-12.10.tar.gz` <br>
`cd Image-ExifTool-12.10` <br>

Now you can use `./exiftool` to run the program, but we need to run it from another piece of code <br>
So we run <br>
`perl Makefile.PL` <br>
`make test` <br>
`sudo make install`

Install libgphoto2 and gphoto2 using <br>
`make install`

To Run the raspi code you can select two options <br>
* You can run the code that geotags images when it detects a rising edge on the GPIO pin using the command <br>
  `make main` <br><br>
* Or you can run a test code that geotags one image and exits <br>
  `make aux`<br>
  
 Both commands create separate executable files called interrupt_capture and single_capture respectively<br>
 
 To delete the executables, simple run<br>
 `make delete_exe`

For Running the exif testing API use this <br>
`make exiftool exiftoolpipe taginfo main clean` <br>
in the *src/temp_exif_test/* folder
<<<<<<< HEAD
=======
=======

>>>>>>> upstream/cpp_testing
Wiring PI is already present on the raspi, if not then follow this: http://wiringpi.com/download-and-install/

Compile the gpio.c file like this <br>
`cc gpio.c -lwiringPi` <br>
or <br>
`cc gpio.c -I/usr/local/include -L/usr/local/lib -lwiringPi`
<<<<<<< HEAD
=======

| TELEM Cable  | BCM GPIO Pin Number | Board Pin Number 
| ------------- | ------------- | ------------- |
| 1 VCC  | -  | -  | (As per PX4 documentation you are strictly not supposed to connect this)
| 2 TX | GPIO 15  | 10  |
| 3 RX | GPIO 14  | 8  |
| 4 CTS | GPIO 17  | 11  |(Optional. Yet to be tested if this matters)
| 5 RTS | GPIO 16  | 36  |(Optional. Yet to be tested if this matters)
| 6 GND  | GND  | 6,14,20,30,34  |

>>>>>>> upstream/cpp_testing


On your drone (Using QGroundControl)
Follow the instructions listed here to setup your camera https://docs.px4.io/master/en/peripherals/camera.html. Set Trigger mode to 
4 (Distance, Mission Controlled) and set Trigger interface to GPIO

Follow the instructions listed here to setup telem2 port for mavlink https://docs.px4.io/master/en/companion_computer/pixhawk_companion.html

Connect the AUX pins set for triggering to board pin 16 (gpio 23) of the raspberry pi
Connect the telemetry cable between telem2 to port and raspberry pi as follows
| TELEM Cable  | BCM GPIO Pin Number | Board Pin Number 
| ------------- | ------------- | ------------- |
| 1 VCC  | -  | -  | (As per PX4 documentation you are strictly not supposed to connect this)
| 2 TX | GPIO 15  | 10  |
| 3 RX | GPIO 14  | 8  |
| 4 CTS | GPIO 17  | 11  |(Optional. Yet to be tested if this matters)
| 5 RTS | GPIO 16  | 36  |(Optional. Yet to be tested if this matters)
| 6 GND  | GND  | 6,14,20,30,34  

To Build (From the pixtrigger repo)
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON -DCMAKE_SHARED_LINKER_FLAGS='-latomic' -Bbuild/default -H.

To run (From the pixtrigger repo)
"./pixtrigger.sh"