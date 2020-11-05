import RPi.GPIO as GPIO
import time
#gpio_pin_1 = 17
#gpio_pin_2 = 27
#gpio_pin_3 = 12
#gpio_pin_4 = 13
GPIO.setmode(GPIO.BCM)
GPIO.setup(17,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)
#GPIO.setup(gpio_pin_2,GPIO.IN)
#GPIO.setup(gpio_pin_3,GPIO.IN)
#GPIO.setup(gpio_pin_4,GPIO.IN)
count = 0
try:
    while True:
        op = str(GPIO.input(17))
        print(op)
            
            #print(count)
except:
    print(count)
    
    #time.sleep(0.05)