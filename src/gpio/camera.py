"""
This script is used to capture image from the camera and store it on the USB Device.
"""
import os
import subprocess
import sys
import gphoto2 as gp
from datetime import datetime as dt

"""
This function is used to initialize the attached camera. 
Returns the camera object that contains capturing functions
"""
def cam_init():
    camera = gp.Camera()
    camera.init()
    return camera


"""
This function is called in the GPIO script. Uses the gphoto2 library (a wrapper for the libgphoto2) to capture the image and save it in a specified location.
Returns the location of the saved image
:param cam:       Camera object with the relevant functions
:param directory: Location of the diretory where the captured image is to be stored
:param name:      Name of the image that will be stored
"""
def capture_image_and_download(cam,directory,name):
    # Create the camera object
    camera = cam

    # Capture Image
    file_path = camera.capture(gp.GP_CAPTURE_IMAGE)

    # Retrieves the file object from the camera. file_path.folder is '/' and name is 'captXXXX'. We take this file object and re-store it with a new name
    # as per convenience
    camera_file = camera.file_get(file_path.folder, file_path.name, gp.GP_FILE_TYPE_NORMAL)

    # Final location of the image
    target = directory+"/"+name

    # Save the image from the file object to the desired location
    camera_file.save(target)

    # Close camera connection
    #camera.exit()

    # Target is the final path of the image. It is used in 
    return target


"""
This is a simple function that captures images and saves it on the device itself, without downloading. Functionally similar to the previous function.
"""
def capture_image_and_save(cam):
    camera = cam
    file_path = camera.capture(gp.GP_CAPTURE_IMAGE)