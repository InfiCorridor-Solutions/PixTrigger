/*
This code creates a folder on the USB device, capture one image and geotags it.
g++ exiv2apitest.cpp context/context.c capture/capture.cpp path/path.cpp usb/usb.cpp ../thirdparty/exiv2_samples/exiv2API.cpp ../thirdparty/exiv2_samples/conversion.cpp -I./headers/ -lgphoto2 -lgphoto2_port -lexiv2
*/
#include "headers/capture.h"
#include "headers/exiv2API.h"
#include "headers/path.h"
#include "headers/usb.h"
#include <iostream>
using namespace std;
int main(){
    int i = 0;
	double time,tot_time = 0;
	std::string path; // Path of the folder where the image will be saved
	std::string image_path; //Path of the image. This is fed to the geotagging function
	path = make_command();
    clock_t begin, end;
	while(i<5){
    begin = clock();
	cout << path << "\n";
	image_path = capture_image(path, std::to_string(i)); //foo here is the image name. Replace it with suitable name
	cout << image_path << "\n";
	Exiv2Tag(image_path);
    end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
	tot_time = tot_time + time;
	i++;
    }
    printf("TOTAL Time taken is %f\n", tot_time);
}
