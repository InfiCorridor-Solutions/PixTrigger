CC = g++
CFLAGS = -Wall -g
LFLAGS = -lwiringPi -lgphoto2 -lgphoto2_port
main: interrupt.o capture.o context.o usb.o path.o exif.o
	$(CC) $(CFLAGS) -o v1 interrupt.o capture.o context.o usb.o path.o exif.o $(LFLAGS)
	
clean:
	rm -f *.o
