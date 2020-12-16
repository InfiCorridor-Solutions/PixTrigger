/*
This code creates a folder on the USB device, capture one image and geotags it.
*/
// #include "headers/capture.h"
#include "exif/exif.h"
// #include "headers/path.h"
// #include "headers/usb.h"
#include <iostream>
#include <chrono>
#include <cstdint>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <thread>

using namespace mavsdk;
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

#define ERROR_CONSOLE_TEXT "\033[31m" // Turn text on console red
#define TELEMETRY_CONSOLE_TEXT "\033[34m" // Turn text on console blue
#define NORMAL_CONSOLE_TEXT "\033[0m" // Restore normal console colour

void usage(std::string bin_name)
{
    std::cout << NORMAL_CONSOLE_TEXT << "Usage : " << bin_name << " <connection_url>" << std::endl
              << "Connection URL format should be :" << std::endl
              << " For TCP : tcp://[server_host][:server_port]" << std::endl
              << " For UDP : udp://[bind_host][:bind_port]" << std::endl
              << " For Serial : serial:///path/to/serial/dev[:baudrate]" << std::endl
              << "For example, to connect to the simulator use URL: udp://:14540" << std::endl;
}

void component_discovered(ComponentType component_type)
{
    std::cout << NORMAL_CONSOLE_TEXT << "Discovered a component with type "
              << unsigned(component_type) << std::endl;
}

int main(int argc, char** argv){

	Mavsdk mavsdk;
    std::string connection_url;
    ConnectionResult connection_result;

    bool discovered_system = false;
    if (argc == 2) {
        connection_url = argv[1];
        connection_result = mavsdk.add_any_connection(connection_url);
    } else {
        usage(argv[0]);
        return 1;
    }

    if (connection_result != ConnectionResult::Success) {
        std::cout << ERROR_CONSOLE_TEXT << "Connection failed: " << connection_result
                  << NORMAL_CONSOLE_TEXT << std::endl;
        return 1;
    }

    std::cout << "Waiting to discover system..." << std::endl;
    mavsdk.subscribe_on_new_system([&mavsdk, &discovered_system]() {
        const auto system = mavsdk.systems().at(0);

        if (system->is_connected()) {
            std::cout << "Discovered system" << std::endl;
            discovered_system = true;
        }
    });

    // We usually receive heartbeats at 1Hz, therefore we should find a system after around 2
    // seconds.
    sleep_for(seconds(2));

    if (!discovered_system) {
        std::cout << ERROR_CONSOLE_TEXT << "No system found, exiting." << NORMAL_CONSOLE_TEXT
                  << std::endl;
        return 1;
    }

    const auto system1 = mavsdk.systems().at(0);

    // Register a callback so we get told when components (camera, gimbal) etc
    // are found.
    system1->register_component_discovered_callback(component_discovered);

    auto telemetry = std::make_shared<Telemetry>(system1);

	// We want to listen to the altitude of the drone at 1 Hz.
    const Telemetry::Result set_rate_result = telemetry->set_rate_position(1.0);
    if (set_rate_result != Telemetry::Result::Success) {
        std::cout << ERROR_CONSOLE_TEXT << "Setting rate failed:" << set_rate_result
                  << NORMAL_CONSOLE_TEXT << std::endl;
        return 1;
    }
	Telemetry::Position pose;
	telemetry->subscribe_position([&pose](Telemetry::Position position) {
		pose = position;
	});

	sleep_for(seconds(1));

	std::cout << TELEMETRY_CONSOLE_TEXT 
			  << "Latitude: " << pose.latitude_deg 
			  << " Longitude: " << pose.longitude_deg
			  << " Altitude: " << pose.relative_altitude_m << " m"
			  << NORMAL_CONSOLE_TEXT
			  << std::endl;

	// std::string path; // Path of the folder where the image will be saved
	std::string image_path; //Path of the image. This is fed to the geotagging function
// 	path = make_command();
// 	cout << path << "\n";
	image_path = "/Users/yashomdighe/Developer/PixTrigger/resources/test_images/sample_1.JPG";//capture_image(path, "foo"); //foo here is the image name. Replace it with suitable name
// 	cout << image_path << "\n";
// 	string command =
//       "exiftool -overwrite_original " 
//       + image_path
//       +" -gpslatitude='"+ to_string(pose.latitude_deg)+"'" 
//       + " -gpslongitude='" + to_string(pose.longitude_deg)+"'"
//       + " -gpsaltitude='" + to_string(pose.relative_altitude_m) +"'";
//   // auto start = chrono::steady_clock::now();
// 	std::cout << command << std::endl;
//   	system(command.c_str());
	tag_exif(image_path, pose.latitude_deg, pose.longitude_deg, pose.relative_altitude_m);
	return 0;
}