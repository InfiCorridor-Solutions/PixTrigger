# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/christo/Desktop/PixTrigger/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christo/Desktop/PixTrigger/src/build

# Include any dependencies generated for this target.
include CMakeFiles/single_capture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/single_capture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/single_capture.dir/flags.make

CMakeFiles/single_capture.dir/temp.cpp.o: CMakeFiles/single_capture.dir/flags.make
CMakeFiles/single_capture.dir/temp.cpp.o: ../temp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/single_capture.dir/temp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_capture.dir/temp.cpp.o -c /home/christo/Desktop/PixTrigger/src/temp.cpp

CMakeFiles/single_capture.dir/temp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_capture.dir/temp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christo/Desktop/PixTrigger/src/temp.cpp > CMakeFiles/single_capture.dir/temp.cpp.i

CMakeFiles/single_capture.dir/temp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_capture.dir/temp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christo/Desktop/PixTrigger/src/temp.cpp -o CMakeFiles/single_capture.dir/temp.cpp.s

CMakeFiles/single_capture.dir/temp.cpp.o.requires:

.PHONY : CMakeFiles/single_capture.dir/temp.cpp.o.requires

CMakeFiles/single_capture.dir/temp.cpp.o.provides: CMakeFiles/single_capture.dir/temp.cpp.o.requires
	$(MAKE) -f CMakeFiles/single_capture.dir/build.make CMakeFiles/single_capture.dir/temp.cpp.o.provides.build
.PHONY : CMakeFiles/single_capture.dir/temp.cpp.o.provides

CMakeFiles/single_capture.dir/temp.cpp.o.provides.build: CMakeFiles/single_capture.dir/temp.cpp.o


CMakeFiles/single_capture.dir/capture/capture.cpp.o: CMakeFiles/single_capture.dir/flags.make
CMakeFiles/single_capture.dir/capture/capture.cpp.o: ../capture/capture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/single_capture.dir/capture/capture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_capture.dir/capture/capture.cpp.o -c /home/christo/Desktop/PixTrigger/src/capture/capture.cpp

CMakeFiles/single_capture.dir/capture/capture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_capture.dir/capture/capture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christo/Desktop/PixTrigger/src/capture/capture.cpp > CMakeFiles/single_capture.dir/capture/capture.cpp.i

CMakeFiles/single_capture.dir/capture/capture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_capture.dir/capture/capture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christo/Desktop/PixTrigger/src/capture/capture.cpp -o CMakeFiles/single_capture.dir/capture/capture.cpp.s

CMakeFiles/single_capture.dir/capture/capture.cpp.o.requires:

.PHONY : CMakeFiles/single_capture.dir/capture/capture.cpp.o.requires

CMakeFiles/single_capture.dir/capture/capture.cpp.o.provides: CMakeFiles/single_capture.dir/capture/capture.cpp.o.requires
	$(MAKE) -f CMakeFiles/single_capture.dir/build.make CMakeFiles/single_capture.dir/capture/capture.cpp.o.provides.build
.PHONY : CMakeFiles/single_capture.dir/capture/capture.cpp.o.provides

CMakeFiles/single_capture.dir/capture/capture.cpp.o.provides.build: CMakeFiles/single_capture.dir/capture/capture.cpp.o


CMakeFiles/single_capture.dir/context/context.c.o: CMakeFiles/single_capture.dir/flags.make
CMakeFiles/single_capture.dir/context/context.c.o: ../context/context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/single_capture.dir/context/context.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/single_capture.dir/context/context.c.o   -c /home/christo/Desktop/PixTrigger/src/context/context.c

CMakeFiles/single_capture.dir/context/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/single_capture.dir/context/context.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/christo/Desktop/PixTrigger/src/context/context.c > CMakeFiles/single_capture.dir/context/context.c.i

CMakeFiles/single_capture.dir/context/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/single_capture.dir/context/context.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/christo/Desktop/PixTrigger/src/context/context.c -o CMakeFiles/single_capture.dir/context/context.c.s

CMakeFiles/single_capture.dir/context/context.c.o.requires:

.PHONY : CMakeFiles/single_capture.dir/context/context.c.o.requires

CMakeFiles/single_capture.dir/context/context.c.o.provides: CMakeFiles/single_capture.dir/context/context.c.o.requires
	$(MAKE) -f CMakeFiles/single_capture.dir/build.make CMakeFiles/single_capture.dir/context/context.c.o.provides.build
.PHONY : CMakeFiles/single_capture.dir/context/context.c.o.provides

CMakeFiles/single_capture.dir/context/context.c.o.provides.build: CMakeFiles/single_capture.dir/context/context.c.o


CMakeFiles/single_capture.dir/exif/exif.cpp.o: CMakeFiles/single_capture.dir/flags.make
CMakeFiles/single_capture.dir/exif/exif.cpp.o: ../exif/exif.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/single_capture.dir/exif/exif.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_capture.dir/exif/exif.cpp.o -c /home/christo/Desktop/PixTrigger/src/exif/exif.cpp

CMakeFiles/single_capture.dir/exif/exif.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_capture.dir/exif/exif.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christo/Desktop/PixTrigger/src/exif/exif.cpp > CMakeFiles/single_capture.dir/exif/exif.cpp.i

CMakeFiles/single_capture.dir/exif/exif.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_capture.dir/exif/exif.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christo/Desktop/PixTrigger/src/exif/exif.cpp -o CMakeFiles/single_capture.dir/exif/exif.cpp.s

CMakeFiles/single_capture.dir/exif/exif.cpp.o.requires:

.PHONY : CMakeFiles/single_capture.dir/exif/exif.cpp.o.requires

CMakeFiles/single_capture.dir/exif/exif.cpp.o.provides: CMakeFiles/single_capture.dir/exif/exif.cpp.o.requires
	$(MAKE) -f CMakeFiles/single_capture.dir/build.make CMakeFiles/single_capture.dir/exif/exif.cpp.o.provides.build
.PHONY : CMakeFiles/single_capture.dir/exif/exif.cpp.o.provides

CMakeFiles/single_capture.dir/exif/exif.cpp.o.provides.build: CMakeFiles/single_capture.dir/exif/exif.cpp.o


CMakeFiles/single_capture.dir/path/path.cpp.o: CMakeFiles/single_capture.dir/flags.make
CMakeFiles/single_capture.dir/path/path.cpp.o: ../path/path.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/single_capture.dir/path/path.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_capture.dir/path/path.cpp.o -c /home/christo/Desktop/PixTrigger/src/path/path.cpp

CMakeFiles/single_capture.dir/path/path.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_capture.dir/path/path.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christo/Desktop/PixTrigger/src/path/path.cpp > CMakeFiles/single_capture.dir/path/path.cpp.i

CMakeFiles/single_capture.dir/path/path.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_capture.dir/path/path.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christo/Desktop/PixTrigger/src/path/path.cpp -o CMakeFiles/single_capture.dir/path/path.cpp.s

CMakeFiles/single_capture.dir/path/path.cpp.o.requires:

.PHONY : CMakeFiles/single_capture.dir/path/path.cpp.o.requires

CMakeFiles/single_capture.dir/path/path.cpp.o.provides: CMakeFiles/single_capture.dir/path/path.cpp.o.requires
	$(MAKE) -f CMakeFiles/single_capture.dir/build.make CMakeFiles/single_capture.dir/path/path.cpp.o.provides.build
.PHONY : CMakeFiles/single_capture.dir/path/path.cpp.o.provides

CMakeFiles/single_capture.dir/path/path.cpp.o.provides.build: CMakeFiles/single_capture.dir/path/path.cpp.o


CMakeFiles/single_capture.dir/usb/usb.cpp.o: CMakeFiles/single_capture.dir/flags.make
CMakeFiles/single_capture.dir/usb/usb.cpp.o: ../usb/usb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/single_capture.dir/usb/usb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_capture.dir/usb/usb.cpp.o -c /home/christo/Desktop/PixTrigger/src/usb/usb.cpp

CMakeFiles/single_capture.dir/usb/usb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_capture.dir/usb/usb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christo/Desktop/PixTrigger/src/usb/usb.cpp > CMakeFiles/single_capture.dir/usb/usb.cpp.i

CMakeFiles/single_capture.dir/usb/usb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_capture.dir/usb/usb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christo/Desktop/PixTrigger/src/usb/usb.cpp -o CMakeFiles/single_capture.dir/usb/usb.cpp.s

CMakeFiles/single_capture.dir/usb/usb.cpp.o.requires:

.PHONY : CMakeFiles/single_capture.dir/usb/usb.cpp.o.requires

CMakeFiles/single_capture.dir/usb/usb.cpp.o.provides: CMakeFiles/single_capture.dir/usb/usb.cpp.o.requires
	$(MAKE) -f CMakeFiles/single_capture.dir/build.make CMakeFiles/single_capture.dir/usb/usb.cpp.o.provides.build
.PHONY : CMakeFiles/single_capture.dir/usb/usb.cpp.o.provides

CMakeFiles/single_capture.dir/usb/usb.cpp.o.provides.build: CMakeFiles/single_capture.dir/usb/usb.cpp.o


# Object files for target single_capture
single_capture_OBJECTS = \
"CMakeFiles/single_capture.dir/temp.cpp.o" \
"CMakeFiles/single_capture.dir/capture/capture.cpp.o" \
"CMakeFiles/single_capture.dir/context/context.c.o" \
"CMakeFiles/single_capture.dir/exif/exif.cpp.o" \
"CMakeFiles/single_capture.dir/path/path.cpp.o" \
"CMakeFiles/single_capture.dir/usb/usb.cpp.o"

# External object files for target single_capture
single_capture_EXTERNAL_OBJECTS =

single_capture: CMakeFiles/single_capture.dir/temp.cpp.o
single_capture: CMakeFiles/single_capture.dir/capture/capture.cpp.o
single_capture: CMakeFiles/single_capture.dir/context/context.c.o
single_capture: CMakeFiles/single_capture.dir/exif/exif.cpp.o
single_capture: CMakeFiles/single_capture.dir/path/path.cpp.o
single_capture: CMakeFiles/single_capture.dir/usb/usb.cpp.o
single_capture: CMakeFiles/single_capture.dir/build.make
single_capture: CMakeFiles/single_capture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christo/Desktop/PixTrigger/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable single_capture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/single_capture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/single_capture.dir/build: single_capture

.PHONY : CMakeFiles/single_capture.dir/build

CMakeFiles/single_capture.dir/requires: CMakeFiles/single_capture.dir/temp.cpp.o.requires
CMakeFiles/single_capture.dir/requires: CMakeFiles/single_capture.dir/capture/capture.cpp.o.requires
CMakeFiles/single_capture.dir/requires: CMakeFiles/single_capture.dir/context/context.c.o.requires
CMakeFiles/single_capture.dir/requires: CMakeFiles/single_capture.dir/exif/exif.cpp.o.requires
CMakeFiles/single_capture.dir/requires: CMakeFiles/single_capture.dir/path/path.cpp.o.requires
CMakeFiles/single_capture.dir/requires: CMakeFiles/single_capture.dir/usb/usb.cpp.o.requires

.PHONY : CMakeFiles/single_capture.dir/requires

CMakeFiles/single_capture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/single_capture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/single_capture.dir/clean

CMakeFiles/single_capture.dir/depend:
	cd /home/christo/Desktop/PixTrigger/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christo/Desktop/PixTrigger/src /home/christo/Desktop/PixTrigger/src /home/christo/Desktop/PixTrigger/src/build /home/christo/Desktop/PixTrigger/src/build /home/christo/Desktop/PixTrigger/src/build/CMakeFiles/single_capture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/single_capture.dir/depend

