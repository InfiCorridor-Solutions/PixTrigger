cmake_minimum_required(VERSION 3.18.4)

project(pixtrigger)

# SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
# if(MSVC)
#     add_definitions("-std=c++11 -WX -W2 ")
# else()
#     add_definitions("-std=c++11 -Wall -Wextra -Werror ")
# endif()
add_definitions("-std=c++11")
include_directories(src/include)
include_directories(/usr/local/Cellar/libgphoto2/2.5.26/include)
add_subdirectory(src)