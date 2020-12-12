import os
import subprocess
import sys
import gphoto2 as gp
from datetime import datetime as dt
from random import randint as rd
from time import time as t

def cam_init():
    camera = gp.Camera()
    camera.init()
    return camera

def capture_image(cam,directory,name):
    camera = cam
    file_path = camera.capture(gp.GP_CAPTURE_IMAGE)
    camera_file = camera.file_get(file_path.folder, file_path.name, gp.GP_FILE_TYPE_NORMAL)
    target = directory+name
    # print(target)
    camera_file.save(target)
    return 0

if __name__ == "__main__":
    cam = cam_init()
    ans = 'y'
    while ans == 'y':
        start = t()
        capture_image(cam,'/home/christo/Desktop/',str(rd(1,10)))
        end = t()
        print(end-start)
        ans = input('ans:?')