#include <iostream>
#include <iomanip>
#include <math.h>
#include <typeinfo>
using namespace std;

std::string Rationalize_DD(float degrees, float minutes, float seconds){
    std::string str_degree = std::to_string(int(degrees))+"/1";
    std::string str_minutes = std::to_string(int(minutes))+"/1";
    float temp_seconds,temp_numerator;
    temp_seconds = roundf(seconds * 1000) / 1000.0;
    // float is always 12.345 format
    temp_numerator = temp_seconds*1000;
    std::string str_seconds = std::to_string(int(temp_numerator))+"/1000";
    return str_degree+' '+str_minutes+' '+str_seconds;
}

std::string Altitude_convert(float altitude){
    float temp_alt;
    std::string op{};
    temp_alt = roundf(altitude * 1000) / 1000.0;
    return std::to_string(int(temp_alt*1000))+"/1000";
}

std::string convert_DD_to_Rational_DMS(double decimal_degrees){
    std::string rationalcoords{};
    float f_seconds,f_mins,f_degrees;
    f_seconds = (fmod(decimal_degrees*3600,60));
    f_mins = floor((decimal_degrees*3600)/60);
    f_degrees = floor(f_mins/60);
    f_mins = fmod(f_mins,60);
    rationalcoords = Rationalize_DD(f_degrees,f_mins,f_seconds);
    return rationalcoords;
    
}
