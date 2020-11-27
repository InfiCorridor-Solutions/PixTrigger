import RPi.GPIO as GPIO 
import time 
import geotagging as gt 
import usb_query as uq 
import camera as cam 
from datetime import datetime as dt 
from random import randint as rd

# Create a folder in the USB media and return the path of the folder
destination = uq.create_project()

camera = cam.cam_init()

image_counter = 0

def my_callback(channel):
    global image_counter
    print("TRIGGERED")
    image_name = cam.capture_image_and_download(camera,destination,str(image_counter))
    gt.geo_tag(image_name,destination,"rx0")
    image_counter+=1
    return

# We use the BCM GPIO Numbering for this script.
gpio_pin_17 = 17
#gpio_pin_27 = 27
#gpio_pin_12 = 12
#gpio_pin_13 = 13

#This sets the GPIO functions to read the BCM Pinout instead of actual numbers
GPIO.setmode(GPIO.BCM)

#Setup the pin so that it can read inputs. Also pull down intermediate values to account for stray non-high pulses.
GPIO.setup(gpio_pin_17,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)
#GPIO.add_event_detect(gpio_pin_17, GPIO.RISING, callback=my_callback, bouncetime=100)
#GPIO.setup(gpio_pin_27,GPIO.IN)
#GPIO.setup(gpio_pin_12,GPIO.IN)
#GPIO.setup(gpio_pin_13,GPIO.IN)


try:
    GPIO.add_event_detect(gpio_pin_17,GPIO.RISING,callback=my_callback,bouncetime=100)

    while True:
        #print("Waiting")
        pass
except:
    pass
    
    #time.sleep(0.05)
