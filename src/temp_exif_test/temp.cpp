#include <iostream>
#include "exif_api.h"
using namespace std;

int main(){
    std::string path = "/home/christo/Desktop/sample_1.JPG";
    exif_api_tag(path);
    return 0;
}