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
