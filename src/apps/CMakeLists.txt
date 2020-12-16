include_directories(src/include)

add_executable(pixtrigger main.cpp)

find_package(MAVSDK REQUIRED)
include_directories(/usr/local/Cellar/libgphoto2/2.5.26/include)
target_link_libraries(pixtrigger
    capture
    Geotag
    Usb
    MAVSDK::mavsdk_action
    MAVSDK::mavsdk_telemetry
    MAVSDK::mavsdk_manual_control
    MAVSDK::mavsdk
    gphoto2
    gphoto2_port
)
