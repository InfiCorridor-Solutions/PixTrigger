#include <exiv2/exiv2.hpp>
 
#include <iostream>
#include <iomanip>
#include <cassert>
#include "conversion.h"

int Exiv2Tag(std::string path)
{
try {

    std::string file(path);
    Exiv2::ExifData exifData;
    //DUMMY VALUES REPLACE LATER
    float latitude = 19.198802;
    float longitude = 72.838074;
    float altitude = 50.1245;
    std::string lat_ref = "N",lon_ref="E";
    if (latitude <=0){
        lat_ref = "S";
        latitude = latitude*-1;
    }
    if(longitude <=0){
        lon_ref = "W";
        longitude = longitude*-1;
    }
    exifData["Exif.GPSInfo.GPSAltitude"] = Altitude_convert(altitude);
    exifData["Exif.GPSInfo.GPSLatitude"] = convert_DD_to_Rational_DMS(double(latitude));
    exifData["Exif.GPSInfo.GPSLatitudeRef"] = lat_ref;
    exifData["Exif.GPSInfo.GPSLongitudeRef"] = lon_ref;
    exifData["Exif.GPSInfo.GPSLongitude"] = convert_DD_to_Rational_DMS(double(longitude));

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
}
