// https://stackoverflow.com/questions/5919622/how-to-store-the-system-command-output-in-a-variable
/*
This code is responsible for getting the paths of the USB devices and creating folders in them
*/
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
This function just lists the files present at a location. Equivalent to ls
*/
std::string ls(std::string command) {
  const char *func_command = command.c_str();
  FILE *fpipe;
  char c = 0;
  std::string output{};
  fpipe = (FILE *)popen(func_command, "r");
  while (fread(&c, sizeof c, 1, fpipe)) {
    output += c;
  }
  pclose(fpipe);
  return output;
}

/*
Returns the path to a subfolder within a path. 
param command: First '/media' and then '/media/xyz'
returns output: Path of the folder
*/
std::string get_path(std::string command) {
  const char *func_command = command.c_str();
  FILE *fpipe; // Initializing FILE pointer to get the contents of the pipe
  char c = 0; // Character for reading output
  int pos{}; // Used to find the location of the newline character. popen() adds a '\n' to the end which needs to be removed
  std::string output{}; // Output of each path
  std::string slash = "/"; // '/' needs to be appended at the end instead of a '\n'
  fpipe = (FILE *)popen(func_command, "r"); //Read the output pipe of the command
  while (fread(&c, sizeof c, 1, fpipe)) {
    output += c;
  }
  pos = output.find('\n');
  output.erase(pos);
  output.append(slash);
  pclose(fpipe);
  return output;
}

/*
Runs a mkdir command to create folder at specific paths
param folder_path: Path to the USB Driver where folder must be made
returns fin: Absolute path of the folder, used for saving the captured image
*/
std::string create_folder(std::string folder_path) {
  std::string name{};
  std::string command;
  std::string datetime;
  std::string fin;
  auto end = std::chrono::system_clock::now();
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  datetime = static_cast<std::string>(ctime(&end_time));
  int pos = datetime.find('\n');
  datetime.erase(pos);
  replace(datetime.begin(), datetime.end(), ':', '_');
  replace(datetime.begin(), datetime.end(), ' ', '_');
  cout << "Enter name of folder\n";
  cin >> name;
  command = "mkdir " + folder_path + name + "_" + datetime;
  system(command.c_str());
  fin = folder_path + name + "_" + datetime;
  return fin;
}
