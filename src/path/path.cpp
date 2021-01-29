/*
This file is used to get the path of the USB drive. Once it gets the path, it passes the path to the function responsible for creating the folder
*/
#include "usb.h"
#include <vector>
using namespace std;


bool findLocation(string sample, char findIt)
{
    int count = 0;
    for(int i =0; i < sample.size(); i++)
        if(sample[i] == findIt)
            count++;

    if(count > 1){
      return true;
    }
    else{
      return false;
    }

}

std::string make_command() {
  // USB devices are listed in /media
  std::string command = "ls /media/"; //Command to list the user eg. /media/pi 
  std::string paths{};
  vector<int> characterLocations;
  paths = command + get_path(command); //paths: ls /media/pi/XXXX-YYYY
  if(findLocation(ls(paths),'\n')!=true){
    paths = paths + get_path(paths); //paths: ls /media/pi/XXXX-YYYY/folder_name_date_time
    paths = paths.substr(3); // Remove ls to get final absolute path
    return (create_folder(paths)); //Create folder at path
  }
  else{
    cout << "Multiple USB Devices Detected\n Write Name of the device\n";
    std::string device_name;
    cin >> device_name;
    paths = paths+device_name+"/";
    paths = paths.substr(3);
    return (create_folder(paths)); 
  }
  
}
