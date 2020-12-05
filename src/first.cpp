#include "capture.h"
#include "usb.h"
using namespace std;

int main() {
  std::string command = "ls /media/";
  std::string outp{};
  std::string path;
  std::string imagename;
  outp = command + get_path(command);
  outp = outp + get_path(outp);
  outp = outp.substr(3);
  path = create_folder(outp);
  cout << "Enter image name: ";
  cin >> imagename;
  capture_image(path, imagename);
  return EXIT_SUCCESS;
}
