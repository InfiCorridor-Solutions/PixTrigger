"""
This script is used in the gpio_usb_tag_save python script and is responsible for creating a folder on a USB Drive and providing a string path to the created folder
"""
import subprocess as sp
import datetime as dt
import os


# https://stackoverflow.com/questions/23272184/how-do-you-search-subprocess-output-in-python-for-a-specific-word
# https://askubuntu.com/questions/311772/how-do-i-know-the-device-path-to-an-usb-stick
"""
This function searches the device for a USB Drive. If it finds one, it returns a path to the USB Drives directory.
"""
def get_usb_path():
    variable = sp.Popen(["lsblk"], stdout=sp.PIPE)
    # Only need the stdout and not stderr
    stdout= variable.communicate()[0]
    # Conversion of bytes to string
    stdout = stdout.decode("utf-8").split()
    # Find the pattern '/media' in the subprocess output
    # https://www.geeksforgeeks.org/python-finding-strings-with-given-substring-in-list/
    try:
        path = str(list(filter(lambda x: "/media" in x, stdout))[0])
        return path
    except IndexError:
        print("No USB media found")
        return None

"""
This function creates a folder in the USB Drive using the path supplied with the get_usb_path() function. It takes user input for the base name of the project and appends
the date and time of the creation of the folder.
"""
def create_project():
    project_name = input("Enter project name: ")

    # Split the datetimestamp into date and time stamps
    datetimestamp = str(dt.datetime.now()).split()
    
    # Filenames cannot have : so we replace : with _
    datetimestamp = datetimestamp[0]+"_"+datetimestamp[1].replace(":","_")
    
    # Create the name of the final project folder
    final_project_name = project_name+"_"+str(datetimestamp)
    
    # Get the path to the USB Drive that is connected
    path_to_usb = get_usb_path()
    
    if path_to_usb is not None:
    # "mkdir /media/xxxx/xxx/project_name_datetimestamp"
        final_path = path_to_usb+"/"+final_project_name

        # System command to make directories
        os.system("mkdir "+final_path)
        
        return final_path
    else:
        pass


