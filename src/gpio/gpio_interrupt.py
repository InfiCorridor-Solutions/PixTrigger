import RPi.GPIO as GPIO 
import time 
import geotagging as gt 
import usb_query as uq 
import camera as cam 
from datetime import datetime as dt 
from random import randint as rd

# Create a folder in the USB media and return the path of the folder
destination = uq.create_project()

# Create a camera object that will be used for capturing and downloading the image
camera = cam.cam_init()

# Global variable for naming the file
image_counter = 0

"""
This is a callback function that is called by the Interrupt Service Routine.
:param channel: Standard ISR channel number. DON'T CHANGE IT
"""
def my_callback(channel):
    # Global variable for image naming
    global image_counter
    # print("TRIGGERED")
    # Capture the image by passing the global camera object
    image_name = cam.capture_image_and_download(camera,destination,str(image_counter))
    # Geotag the image and save it at destination
    gt.geo_tag(image_name,destination,"rx0")
    image_counter+=1
    return

# We use the BCM GPIO Numbering for this script.
gpio_pin_23 = 23
#gpio_pin_27 = 27
#gpio_pin_12 = 12
#gpio_pin_13 = 13

#This sets the GPIO functions to read the BCM Pinout instead of actual numbers
GPIO.setmode(GPIO.BCM)

#Setup the pin so that it can read inputs. Also pull down intermediate values to account for stray non-high pulses.
GPIO.setup(gpio_pin_23,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)
#GPIO.add_event_detect(gpio_pin_17, GPIO.RISING, callback=my_callback, bouncetime=100)
#GPIO.setup(gpio_pin_27,GPIO.IN)
#GPIO.setup(gpio_pin_12,GPIO.IN)
#GPIO.setup(gpio_pin_13,GPIO.IN)


try:
    # Define the pin number on which ISR needs to be detect rising or falling edges.
    # bouncetime is the time in milliseconds where another edge detected is ignored
    GPIO.add_event_detect(gpio_pin_23,GPIO.RISING,callback=my_callback,bouncetime=100)

    while True:
        # ~ print("Waiting")
        pass
except:
    pass
    
    #time.sleep(0.05)
