/*
This C code runs an infinite loop and checks for interrupts that occur on the
defined GPIO pins
*/
#include "headers/capture.h"
#include "headers/exif.h"
#include "headers/path.h"
#include "headers/usb.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
// The wiringPi library uses different number for the pins
// http://wiringpi.com/wp-content/uploads/2013/03/gpio1.png
std::string path;
int i = 0;
#define BUTTON_PIN_1 0 // Board Pin no:11, BCM GPIO Pin no:17
#define BUTTON_PIN_2 2 // Board Pin no:13, BCM GPIO Pin no:27
#define BUTTON_PIN_3 3 // Board Pin no:15, BCM GPIO Pin no:22
#define BUTTON_PIN_4 1 // Board Pin no:12, BCM GPIO Pin no:18
#define BUTTON_PIN_5 4 // Board Pin no:16, BCM GPIO Pin no:23
#define BUTTON_PIN_6 5 // Board Pin no:18, BCM GPIO Pin no:24

// myInterrupt:  called every time an event occurs
void myInterrupt(void) {
  std::string image_path;
  printf("Interrupted\n");
 std::string sample_img_path = "../resources/test_images/";
  image_path = sample_img_path+std::to_string(i)+".jpg";
i++;
  tag_exif(image_path);
  //  Replace this section for whatever is needed while interrupt has occured
}

int main(void) {

  //~ Initialise the file structure needed to save
  path = make_command();

  // sets up the wiringPi library
  if (wiringPiSetup() < 0) {
    fprintf(stderr, "Unable to setup wiringPi: %s\n", strerror(errno));
    return 1;
  }

  // set Pin 17/0 generate an interrupt on low-to-high transitions
  // and attach myInterrupt() to the interrupt
  if (wiringPiISR(BUTTON_PIN_5, INT_EDGE_RISING, &myInterrupt) < 0) {
    fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
    return 1;
  }

  // This should be the main loop running that detects interrupts on the GPIO
  // Pins
  while (1) {
    /*
      Run any piece of code here. If a rising edge is detected, the ISR will handle halt this and attend to the callback defined.
    */
  }

  return 0;
}