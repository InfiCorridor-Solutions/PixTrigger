#include<stdio.h>
#include<wiringPi.h>

int main(void){
int gpio_17 = 17;
int stray_count = 0;
wiringPiSetupGpio();
pinMode(gpio_17,INPUT);
while(1){
	if(digitalRead(gpio_17)){
	stray_count+=1;
	printf("%d\n",&stray_count);
}

}

return 1;
}
