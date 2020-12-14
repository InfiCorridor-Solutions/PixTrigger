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

To run code you can select two options <br>
* You can run the code that geotags images when it detects a rising edge on the GPIO pin using the command<br>
  `make main` **(Raspberry PI ONLY)**<br><br>
* Or you can run a test code that geotags one image and exits <br>
  `make aux` **(General)**<br>
  
 Both commands create separate executable files called interrupt_capture and single_capture respectively<br>
 
 To delete the executables, simple run<br>
 `make delete_exe` <br>

To Run the EXIV2 API Install the exiv2 library: https://www.exiv2.org/download.html <br>
To Run the exiv2API use this <br>
`make exiv2` <br>
in the makefile in the *src/* folder <br>
This creates an executable file called exiv2api_capture <br>

Alternatively, you can use CMake to build the single_capture and the exiv2api_capture executables. *interrupt_capture will be included later* <br>
To build using cmake <br>
`mkdir build && cd build` in src <br>
`cmake ..` <br>
`make` <br>
This will install both single_capture and the exiv2api_capture executables in the build folder.

<br>
To Run the exiftool API use this <br>
`make exiftool exiftoolpipe taginfo main clean` <br>
in the makefile in the *src/temp_exif_test/* folder

Wiring PI is already present on the raspi, if not then follow this: http://wiringpi.com/download-and-install/


