import RPi.GPIO as GPIO
import time
import geotagging as gt
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
        if op == "1":
            print("TRUE")
            gt.geo_tag("sample_1.JPG","rx0")
            
            #print(count)
except:
    print(count)
    
    #time.sleep(0.05)
