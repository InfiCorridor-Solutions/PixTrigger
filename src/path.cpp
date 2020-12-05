#include "usb.h"

using namespace std;

std::string make_command() {
  std::string command = "ls /media/";
  std::string outp{};
  std::string path;
  std::string imagename;
  outp = command + get_path(command);
  outp = outp + get_path(outp);
  outp = outp.substr(3);
  return (create_folder(outp));
}
