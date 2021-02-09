#include <exiv2/exiv2.hpp>
 
#include <iostream>
#include <iomanip>
#include <cassert>
#include "conversion.h"

float temp_lat,temp_lon,temp_alt;

int Exiv2Tag(std::string path)
{
try {

    std::string file(path);
    Exiv2::ExifData exifData;
    //DUMMY VALUES REPLACE LATER
    float latitude = temp_lat;
    float longitude = temp_lon;
    float altitude = temp_alt;
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

int main(int argc, char *argv[]){
    temp_lat = atof(argv[1]);
    temp_lon = atof(argv[2]);
    temp_alt = atof(argv[3]);
    Exiv2Tag("og1");
}