# PixTrigger
A free and open source tool to trigger cameras using Pixhawk and Raspberry Pi


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

Wiring PI is already present on the raspi, if not then follow this: http://wiringpi.com/download-and-install/

Compile the gpio.c file like this <br>
`cc gpio.c -lwiringPi` <br>
or <br>
`cc gpio.c -I/usr/local/include -L/usr/local/lib -lwiringPi`

| TELEM Cable  | BCM GPIO Pin Number | Board Pin Number 
| ------------- | ------------- | ------------- |
| 1 VCC  | -  | -  |
| 2 TX | GPIO 15  | 10  |
| 3 RX | GPIO 14  | 8  |
| 4 CTS | GPIO 17  | 11  |
| 5 RTS | GPIO 16  | 36  |
| 6 GND  | GND  | 6,14,20,30,34  |

