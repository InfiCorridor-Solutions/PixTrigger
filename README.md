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

To Run the raspi code you can select two options <br>
* You can run the code that geotags images when it detects a rising edge on the GPIO pin using the command <br>
  `make main clean` <br><br>
* Or you can run a test code that geotags one image and exits <br>
  `make aux clean`<br>
  
 Both commands result in an executable file called v1 which can then be executed using `./v1'

For Running the exif testing API use this <br>
`make exiftool exiftoolpipe taginfo main clean` <br>
in the *src/temp_exif_test/* folder
=======
Wiring PI is already present on the raspi, if not then follow this: http://wiringpi.com/download-and-install/

Compile the gpio.c file like this <br>
`cc gpio.c -lwiringPi` <br>
or <br>
`cc gpio.c -I/usr/local/include -L/usr/local/lib -lwiringPi`
