cmake_minimum_required(VERSION 2.8.9)

project(directory_test)
 
include_directories(headers)


#Can manually add the sources using the set command as follows:
set(SOURCES temp.cpp capture/capture.cpp context/context.c exif/exif.cpp path/path.cpp usb/usb.cpp)
set(SOURCE2 exiv2apitest.cpp capture/capture.cpp context/context.c exif/exif.cpp path/path.cpp usb/usb.cpp exiv2api/exiv2api.cpp conversion/conversion.cpp)
 
add_executable(single_capture ${SOURCES})
add_executable(exiv_test ${SOURCE2})

target_link_libraries(single_capture -lgphoto2 -lgphoto2_port)
target_link_libraries(exiv_test -lgphoto2 -lgphoto2_port -lexiv2)