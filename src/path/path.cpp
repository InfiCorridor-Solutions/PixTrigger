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
  bool flag = true;
  paths = command + get_path(command); //paths: ls /media/pi/XXXX-YYYY
  if(findLocation(ls(paths),'\n')!=true){
    try{
      paths = paths + get_path(paths); //paths: ls /media/pi/XXXX-YYYY/folder_name_date_time
    paths = paths.substr(3); // Remove ls to get final absolute path
    return (create_folder(paths)); //Create folder at path
    throw 505;
    }
    catch(...){
      std::cout << "No USB Device detected\n"; // In the case when no USB device is detected at /media/pi
    }
  }
  else{
    cout << "Multiple USB Devices Detected\n";
    std::cout << ls(paths) << '\n'; // List the USB devices
    std::cout << "Enter the name of the USB Drive to save\n";
    std::string device_name,root_path;
    root_path = paths; // Hold the root path incase incorrect input from user
    while(flag){
      cin >> device_name;
      paths = root_path+device_name;
      if(ls(paths)!="ERR"){ // this function returns an error when the ls command fails to return an output ie when the USB device does not exist
        paths = paths+"/";
        paths = paths.substr(3);
        flag = false;
        return (create_folder(paths)); 
      }
      else{
          std::cout << "Wrong device name. Please try again\n"; // The user can input the name again
      }
    }
  }
}
