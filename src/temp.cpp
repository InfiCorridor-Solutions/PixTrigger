/*
This code creates a folder on the USB device, capture one image and geotags it.
*/
#include "headers/capture.h"
#include "headers/exif.h"
#include "headers/path.h"
#include "headers/usb.h"
#include <iostream>
using namespace std;
int main(){
	std::string path; // Path of the folder where the image will be saved
	std::string image_path; //Path of the image. This is fed to the geotagging function
	path = make_command();
	cout << path << "\n";
	image_path = capture_image(path, "foo"); //foo here is the image name. Replace it with suitable name
	cout << image_path << "\n";
	tag_exif(image_path);
}
