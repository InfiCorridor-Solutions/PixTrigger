#include<iostream>
using namespace std; 
#include <chrono>

int main (int argc, char* argv[]) 
{
    string command = "exiftool " + string(argv[1])+" -gpslatitude='72.156' -gpslongitude='48.1651' -gpsaltitude='50'"; 
    // auto start = chrono::steady_clock::now();
    system(command.c_str());
    // auto end = chrono::steady_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();
    // std::cout << duration << "\n";
    return 0; 
} 