import RPi.GPIO as GPIO
import time
import geotagging as gt
import usb_query as uq
gpio_pin_17 = 17
#gpio_pin_27 = 27
#gpio_pin_12 = 12
#gpio_pin_13 = 13
GPIO.setmode(GPIO.BCM)
GPIO.setup(gpio_pin_17,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)
#GPIO.setup(gpio_pin_27,GPIO.IN)
#GPIO.setup(gpio_pin_12,GPIO.IN)
#GPIO.setup(gpio_pin_13,GPIO.IN)

# Create a folder in the USB media and return the path of the folder
destination = uq.create_project()

# TODO image_name = get_image_name()
# Replace sample_1.JPG with the actual image name or the image path
try:
    while True:
        op = str(GPIO.input(gpio_pin_17))
        if op == "1":
            gt.geo_tag("sample_1.JPG",destination,"rx0")
            #print(count)
except:
    pass
    
    #time.sleep(0.05)
