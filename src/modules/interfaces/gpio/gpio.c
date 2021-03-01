/*
This is a C code that lets us read the signal on a GPIO pin
*/
#include<stdio.h>
// Make sure wiringPi is installed on the Raspi
#include<wiringPi.h>

int main(void){
	// Considering the BCM GPIO pin no: 17
	int gpio_17 = 17;

	// Setup the GPIO Pins
	wiringPiSetupGpio();

	// Configure the pin number to read inputs
	pinMode(gpio_17,INPUT);
	while(1){
		// Read the signal on the pin number
		if(digitalRead(gpio_17)){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
return 1;
}
