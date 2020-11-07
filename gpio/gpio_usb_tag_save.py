import RPi.GPIO as GPIO
import time
import geotagging as gt
import usb_query as uq
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
destination = uq.create_project()

# TODO image_name = get_image_name()
# Replace sample_1.JPG with the actual image name or the image path
try:
    while True:
        op = str(GPIO.input(17))
        if op == "1":
            gt.geo_tag("~/Downloads/sample_1.JPG",destination,"rx0")
            #print(count)
except:
    print(count)
    
    #time.sleep(0.05)
