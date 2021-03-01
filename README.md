# PixTrigger
A free and open source tool to trigger cameras using Pixhawk and Raspberry Pi (Tested on raspberry pi 3 model b+ and pixhawk 4)

# Depenedencies 
MavSDK (To get telemetry info from the drone to geotag) https://mavsdk.mavlink.io/develop/en/index.html <br>
ExifTool (To geotag images) https://exiftool.org/ <br>
wiringpi (To read triggers) http://wiringpi.com/ <br>
gphoto2 (To trigger the camera and transfer images) http://www.gphoto.org/ <br>
cmake https://cmake.org/ <br>

# To Do 
Check performance of Exiftool vs Exiv2

# Usage

Install and Build ExifTool as follows

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

Install libgphoto2 and gphoto2 by following https://github.com/gphoto/libgphoto2/blob/master/INSTALL

On your drone (Using QGroundControl)
Follow the instructions listed here to setup your camera https://docs.px4.io/master/en/peripherals/camera.html. <br> 
Set Trigger mode to 4 (Distance, Mission Controlled) and set Trigger interface to GPIO

Follow the instructions listed here to setup telem2 port for mavlink https://docs.px4.io/master/en/companion_computer/pixhawk_companion.html

Connect the AUX pins set for triggering to board pin 16 (gpio 23) of the raspberry pi <br>
Connect the telemetry cable between telem2 to port and raspberry pi as follows
| TELEM Cable  | BCM GPIO Pin Number | Board Pin Number | Remarks  
| ------------- | ------------- | ------------- | ------------- |
| 1 VCC  | -  | -  | (As per PX4 documentation you are strictly not supposed to connect this)
| 2 TX | GPIO 15  | 10  |
| 3 RX | GPIO 14  | 8  |
| 4 CTS | GPIO 17  | 11  |(Optional. Yet to be tested if this matters)
| 5 RTS | GPIO 16  | 36  |(Optional. Yet to be tested if this matters)
| 6 GND  | GND  | 6,14,20,30,34  

To Build (From the pixtrigger repo) <br>
`cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON -DCMAKE_SHARED_LINKER_FLAGS='-latomic' -Bbuild/default -H.`

To run (From the pixtrigger repo) <br>
`./pixtrigger.sh`
