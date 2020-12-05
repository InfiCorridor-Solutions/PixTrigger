#include "capture.h"
#include "exif.h"
#include "path.h"
#include "usb.h"
#include <iostream>
using namespace std;
int main(){
	std::string path;
	std::string image_path;
	path = make_command();
	cout << path << "\n";
	image_path = capture_image(path, "foo");
	cout << image_path << "\n";
	tag_exif(image_path);
	std::cout << "TEST";
}
