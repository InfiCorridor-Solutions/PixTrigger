#include <exiv2/exiv2.hpp>
 
#include <iostream>
#include <iomanip>
#include <cassert>
 
int main(int argc, char* const argv[])
try {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " file\n";
        return 1;
    }
    std::string file(argv[1]);
 
    Exiv2::ExifData exifData;

    exifData["Exif.GPSInfo.GPSAltitude"] = "501251/10000";
    exifData["Exif.GPSInfo.GPSLatitude"] = "18/1 11/1 55662/1000";
    exifData["Exif.GPSInfo.GPSLongitude"] = "72/1 50/1 170/10";

    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(file);
    assert(image.get() != 0);
 
    image->setExifData(exifData);
    image->writeMetadata();
 
    return 0;
}
catch (Exiv2::AnyError& e) {
    std::cout << "Caught Exiv2 exception '" << e << "'\n";
    return -1;
}