CC = g++
CFLAGS = -Wall -g
# LFLAGS is used for the interrupt checking code
LFLAGS = -lwiringPi -lgphoto2 -lgphoto2_port
# XFLAGS is used for non-interrupt checking code
XFLAGS = -lgphoto2 -lgphoto2_port
main: interrupt.o capture.o context.o usb.o path.o exif.o
	$(CC) $(CFLAGS) -o v1 interrupt.o capture.o context.o usb.o path.o exif.o $(LFLAGS)

aux: temp.o capture.o context.o usb.o path.o exif.o
	$(CC) $(CFLAGS) -o v1 temp.o capture.o context.o usb.o path.o exif.o $(XFLAGS)
clean:
	rm -f *.o
