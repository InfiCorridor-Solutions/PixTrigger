CC = g++
CFLAGS = -Wall -g
# LFLAGS is the gphoto2 library and is used for the interrupt checking code
LFLAGS = -lwiringPi -lgphoto2 -lgphoto2_port
# XFLAGS is the gphoto2 library and is used for the non-interrupt checking code
XFLAGS = -lgphoto2 -lgphoto2_port
# EFLAG is the exiv2 library location
EFLAGS = -lexiv2

CAPTURE_LOC = ./capture
CONTEXT_LOC = ./context
HEADER_LOC = ./headers/
EXIF_LOC = ./exif
PATH_LOC = ./path
USB_LOC = ./usb
DEFINES_LOC = ./headers/
CONVERSION_LOC = ./conversion
EXIV2_LOC = ./exiv2api

main: build_main
	rm -f *.o

aux: build_aux
	rm -f *.o

exiv2: build_exiv
	rm -f *.o

delete_exe:
	@echo '\033[0;31m'"DELETING EXECUTABLES"'\033[0m'
	rm -f interrupt_capture single_capture exiv2api_capture

build_main: interrupt make_usb make_exif make_capture make_context  make_path 
	$(CC) $(CFLAGS) -o interrupt_capture interrupt.o capture.o context.o usb.o path.o exif.o $(LFLAGS) -I$(HEADER_LOC) -I$(DEFINES_LOC)
	@echo '\033[0;32m'"interrupt_capture.exe was made"'\033[0m'
	@echo "DELETING OBJECT FILES"

build_aux: temp make_usb make_exif make_capture make_context  make_path 
	$(CC) $(CFLAGS) -o single_capture temp.o capture.o context.o usb.o path.o exif.o $(XFLAGS) -I$(HEADER_LOC) -I$(DEFINES_LOC)
	@echo '\033[0;32m'"single_capture.exe was made"'\033[0m'
	@echo "DELETING OBJECT FILES"

build_exiv: exiv2apitest make_exiv2api make_conversion make_usb make_exif make_capture make_context  make_path 
	$(CC) $(CFLAGS) -o exiv2api_capture exiv2apitest.o exiv2api.o conversion.o capture.o context.o usb.o path.o exif.o $(XFLAGS) -I$(HEADER_LOC) $(EFLAGS)
	@echo '\033[0;32m'"exiv2api_capture.exe was made"'\033[0m'
	@echo "DELETING OBJECT FILES"

temp:
	$(CC) $(CFLAGS) -c temp.cpp

interrupt:
	$(CC) $(CFLAGS) -c interrupt.c

exiv2apitest:
	$(CC) $(CFLAGS) -c exiv2apitest.cpp

make_capture:
	$(CC) $(CFLAGS) -c $(CAPTURE_LOC)/capture.cpp -I$(DEFINES_LOC)

make_context:
	$(CC) $(CFLAGS) -c $(CONTEXT_LOC)/context.c -I$(DEFINES_LOC)

make_path:
	$(CC) $(CFLAGS) -c $(PATH_LOC)/path.cpp -I$(DEFINES_LOC)

make_usb:
	$(CC) $(CFLAGS) -c $(USB_LOC)/usb.cpp -I$(DEFINES_LOC)

make_exif:
	$(CC) $(CFLAGS) -c $(EXIF_LOC)/exif.cpp -I$(DEFINES_LOC)

make_exiv2api:
	$(CC) $(CFLAGS) -c $(EXIV2_LOC)/exiv2api.cpp -I$(DEFINES_LOC)

make_conversion:
	$(CC) $(CFLAGS) -c $(CONVERSION_LOC)/conversion.cpp -I$(DEFINES_LOC)

