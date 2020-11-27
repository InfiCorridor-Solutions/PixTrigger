#include "usb.h"
using namespace std;

int main(){
    std::string command = "ls /media/";
    std::string op{};
    op = command + get_path(command);
    op = op + get_path(op);
    op = op.substr(3);
    create_folder(op);
    return EXIT_SUCCESS;
}