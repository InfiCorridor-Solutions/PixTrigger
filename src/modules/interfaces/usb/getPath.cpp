/*
This file is used to get the path of the USB drive. Once it gets the path, it passes the path to the function responsible for creating the folder
*/
#include "usb.h"

using namespace std;

std::string make_command() {
  // USB devices are listed in /media
  std::string command = "ls /media/"; //Command to list the user eg. /media/pi 
  std::string paths{};
  paths = command + get_path(command); //paths: ls /media/pi/XXXX-YYYY
  paths = paths + get_path(paths); //paths: ls /media/pi/XXXX-YYYY/folder_name_date_time
  paths = paths.substr(3); // Remove ls to get final absolute path
  return (create_folder(paths)); //Create folder at path
}
