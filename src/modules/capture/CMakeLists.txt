add_library(capture capture.cpp context.cpp)

include_directories(/usr/local/Cellar/libgphoto2/2.5.26/include)
target_link_libraries(capture)