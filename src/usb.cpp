//https://stackoverflow.com/questions/5919622/how-to-store-the-system-command-output-in-a-variable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

std::string ls(std::string command){
    const char* func_command = command.c_str();
    FILE *fpipe;
    char c = 0;
    std::string output{};
    fpipe = (FILE*)popen(func_command, "r");
    while(fread(&c,sizeof c,1,fpipe)){
        output+=c;
    }
    pclose(fpipe);
    return output;
}

std::string get_path(std::string command){
    const char* func_command = command.c_str();
    FILE *fpipe;
    char c = 0;
    int pos{};
    std::string output{};
    std::string slash = "/";
    fpipe = (FILE*)popen(func_command, "r");
    while(fread(&c,sizeof c,1,fpipe)){
        output+=c;
    }
    pos = output.find('\n');
    output.erase(pos);
    output.append(slash);
    pclose(fpipe);
    return output;
}

void create_folder(std::string folder_path){
    std::string name{};
    std::string command;
    std::string datetime;
auto end = std::chrono::system_clock::now();
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
datetime = static_cast<std::string>(ctime(&end_time));
replace(datetime.begin(),datetime.end(),':','_');
replace(datetime.begin(),datetime.end(),' ','_');
    cout << "Enter name of folder\n";
    cin >> name;
    command = "mkdir " + folder_path+name+"_"+datetime;
    system(command.c_str());
    
}

// int main(){
//     std::string command = "ls /media/";
//     std::string user{};
//     std::string device_id{};

//     user =  command + get_path(command);
//     device_id = user + get_path(user);
//     create_folder(device_id.substr(3));
//     return EXIT_SUCCESS;
// }