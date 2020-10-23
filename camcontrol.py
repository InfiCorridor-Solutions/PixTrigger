import subprocess
import time
import sys
import datetime as dt


def checkCam(flag):        
    res = subprocess.check_output(["gphoto2", "--auto-detect"])

    flag_cam_check = False
    for line in res.splitlines():
        result = line.find('USB PTP Class Camera')
        if result == 0:
            flag_cam_check = True

    if flag == 1:
        if flag_cam_check == True:
            print "Camera Found!"
        elif flag_cam_check == False:
            print ("Camera not found")
            print ("Reconnect and re-run program")
    elif flag == 0:
        return flag_cam_check

def getClaim():
    print ("Trying to get claim , Please wait")
    command = ["bash","psgp.sh"]
    try:
        proc = subprocess.check_output(command)
        for line in proc.splitlines():
            words = line.split()
            proc_id = words[1]
            ret = subprocess.check_output(["kill",proc_id])
            print ret
    except subprocess.CalledProcessError:
        print "Claimed USB device"

def downloadAll():
    checkCam(1)
    if checkCam(0):
        #if checkClaim():
        getClaim()
        print ("Downloading...")
        nowstr = folderMaster()
        get_files = subprocess.check_output(["gphoto2" , "-P"],cwd=nowstr)
        print ("Downloaded")
        f = open("keeper.txt","w+")
        f.write("done downloading")
        f.close()
        #reboot()

def trigger():
    checkCam(1)
    if checkCam(0):
        #if checkClaim():
        getClaim()
        subprocess.check_output(["gphoto2" ,"--trigger-capture"])
        

def reboot(delay=1):
    #pass seconds to change speed
    print ("rebooting")
    time.sleep(delay)
    subprocess.call(["reboot"])

def halt(delay=5):
    #pass seconds to change speed
    print ("shutting down")
    time.sleep(delay)
    subprocess.call(["init","0"])

def folderMaster():
    now = dt.datetime.now()
    frmt = '%Y.%m.%d.%H.%M'
    nowstr = now.strftime(frmt)
    try:
        output = subprocess.check_output(["mkdir",nowstr])
    except subprocess.CalledProcessError:
        print ("Error")
    return nowstr

def formatAll():
    print ("Formatting all files")
    path = "/run/user/1000/gvfs/"
    frmt = subprocess.check_output(["ls"], cwd=path)
    path_one = "".join([path,frmt])
    path_one = path_one.rstrip()
    path_one = "".join([path_one,"/"])
    frmt2 = subprocess.check_output(["ls"] , cwd=path_one)
    frmt2 = frmt2[0:4]
    path_two = "".join([path_one,frmt2])
    path_two = "".join([path_two,"/"])
    frmt3 = subprocess.check_output(["ls"] , cwd=path_two)
    frmt3 = frmt3[0:8]
    final_path = "".join([path_two,frmt3])
    contents = subprocess.check_output(["ls"] , cwd=final_path)
    print contents
    if contents:
        print ("Files located")
        try:
            for line in contents.splitlines():
                output = subprocess.check_output(["rm" , line], cwd=final_path)
        except subprocess.CalledProcessError:
            print ("Return 0")
        print ("Card Formatted")
        f = open("keeper.txt","w")
        f.write("done formatting")
        f.close()
        halt()
