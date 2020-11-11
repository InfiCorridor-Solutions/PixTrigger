import subprocess as sp
import datetime as dt
import os
# https://stackoverflow.com/questions/23272184/how-do-you-search-subprocess-output-in-python-for-a-specific-word
# https://askubuntu.com/questions/311772/how-do-i-know-the-device-path-to-an-usb-stick
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

def create_project():
    project_name = input("Enter project name: ")
    datetimestamp = str(dt.datetime.now()).split()
    # Filenames cannot have : so we replace : with _
    datetimestamp = datetimestamp[0]+"_"+datetimestamp[1].replace(":","_")
    final_project_name = project_name+"_"+str(datetimestamp)
    path_to_usb = get_usb_path()
    if path_to_usb is not None:
    # "mkdir /media/xxxx/xxx/project_name_datetimestamp"
        final_path = path_to_usb+"/"+final_project_name
        os.system("mkdir "+final_path)
        return final_path
    else:
        pass


