import os
import subprocess
import sys
import gphoto2 as gp
from datetime import datetime as dt


def capture_image(directory,name):
    # callback_obj = gp.check_result(gp.use_python_logging())
    camera = gp.Camera()
    camera.init()
    file_path = camera.capture(gp.GP_CAPTURE_IMAGE)
    # print(file_path.name)
    # print('Camera file path: {0}/{1}'.format(file_path.folder, file_path.name))
    # target = os.path.join('/home/christo/Desktop', file_path.name)
    # print('Copying image to', target)
    camera_file = camera.file_get(file_path.folder, file_path.name, gp.GP_FILE_TYPE_NORMAL)
    target = directory+"/"+name
    camera_file.save(target)
    camera.exit()
    return target
