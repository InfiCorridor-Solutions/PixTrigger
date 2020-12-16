/*
This function is responsible for executing the exiftool system command
*/
#include <iostream>
using namespace std;
#include <chrono>

/*
Edit the metadata of the image
param path: Absolute path of the image whose metadata will be updated
*/
void tag_exif(std::string path, double lat, double lon, double alt) {
  string command =
      "exiftool -overwrite_original " 
      + path
      +" -gpslatitude='"+ to_string(lat)+"'" 
      + " -gpslongitude='" + to_string(lon)+"'"
      + " -gpsaltitude='" + to_string(alt) +"'";
  // auto start = chrono::steady_clock::now();
  system(command.c_str());
  // auto end = chrono::steady_clock::now();
  // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end
  // - start ).count(); std::cout << duration << "\n";
  return;
}
