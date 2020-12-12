CC = g++
CFLAGS = -Wall -g
SRC_DIR := $(shell dirname "$(realpath $(lastword $(MAKEFILE_LIST)))")
EXIF_LOC := $(CURDIR)/../../thirdparty/cpp_exiftool/src
HEADER_LOC := $(CURDIR)/../../thirdparty/cpp_exiftool/inc

main: temp.o exif_api.o ExifTool.o ExifToolPipe.o TagInfo.o
	$(CC) $(CFLAGS) -o v1 temp.o exif_api.o ExifTool.o ExifToolPipe.o TagInfo.o -I$(HEADER_LOC)/

exif_api.o: exif_api.cpp
	$(CC) -c exif_api.cpp -I$(HEADER_LOC)/

exiftool:
	$(CC) -c $(EXIF_LOC)/ExifTool.cpp -I$(HEADER_LOC)/

exiftoolpipe:
	$(CC) -c $(EXIF_LOC)/ExifToolPipe.cpp -I$(HEADER_LOC)/
	
taginfo:
	$(CC) -c $(EXIF_LOC)/TagInfo.cpp -I$(HEADER_LOC)/
	
clean:
	rm -f *.o
	
