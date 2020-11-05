#include<stdio.h>
#include<wiringPi.h>

int main(void){
int gpio_17 = 17;
wiringPiSetupGpio();
pinMode(gpio_17,INPUT);
while(1){
	if(digitalRead(gpio_17)){
	printf("True");
}
}
return 1;
}
