# PixTrigger
A free and open source tool to trigger cameras using Pixhawk and Raspberry Pi

## Install exiv2 <br>

1.  cd ~/Downloads <br>
2.  wget https://www.exiv2.org/builds/exiv2-0.27.3-Source.tar.gz <br>
3.  tar -xf exiv2-0.27.3-Source.tar.gz <br>
4.  cd exiv2-0.27.3-Source/ <br>
5.  cmake . <br>

    ### IMPORTANT
    #### Before executing the next command
      1. Navigate into `~/Downloads/exiv2-0.27.3-Source/cmake` <br>
      2. Find the compilerFlags.cmake file <br>
      3. Edit the content of this file to the content at https://raw.githubusercontent.com/jtojnar/exiv2/bbe0b70840cf28b7dd8c0b7e9bb1b741aeda2efd/cmake/compilerFlags.cmake or check the `compilerFlags.cmake` in the repo

6.  make <br>
7.  sudo make install <br>
8.  sudo ldconfig <br>

#### You shoud find `exiv2` in `/usr/local/include` <br>

### To execute the code <br>

cd `PixTrigger/src` <br>
make exiv2 <br>
./exiv2api_capture
