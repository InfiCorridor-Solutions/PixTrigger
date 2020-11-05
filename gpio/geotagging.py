# https://piexif.readthedocs.io/en/latest/functions.html
# https://stackoverflow.com/questions/53543549/change-exif-data-on-jpeg-without-altering-picture
# https://stackoverflow.com/questions/44636152/how-to-modify-exif-data-in-python
# https://exiftool.org/TagNames/GPS.html

# Standard Tags which i dont know will change or not
GPSVersionID = (2,2,0,0)
GPSDOP = (10,1) # This is 10% error
RX0_GPSProcessingMethod = b'ASCII\x00\x00\x00HYBRID-FIX'
GPSProcessingMethod = b'ASCII\x00\x00\x00fused'
GPSMapDatum = b'WGS-84'

import piexif
from PIL import Image
import datetime as dt
from fractions import Fraction
import sys
# import time

# start = time.time()
# file_name = sys.argv[1]

# try:
#     if(sys.argv[2]):
#         camera_make = str(sys.argv[-1]).lower()
# except IndexError:
#     camera_make = None

#Dummy data, add the reading of the data from here
def generate_data():
    latitude = 19.198858
    longitude = 72.838109
    altitude = 400.56
    timestamp = dt.datetime.now()
    return (latitude,longitude,altitude,timestamp)

#Takes a floating number and returns rational fractions
def rationalize(number):
    rational = Fraction(str(number))
    rationals = str(rational).split('/')
    numerator,denominator = int(rationals[0]),int(rationals[1])
    return (numerator,denominator)

#Takes input as datetimestamp ie 'yyyy-mm-dd hh:mn:ss.sss' and splits into datestamp and timestamp
def clean_datetime(datetimestamp):
    date = str(datetimestamp).split(' ')[0]
    temp_date = date.split('-')
    yyyy,mm,dd = temp_date[0],temp_date[1],temp_date[2]
    time = str(datetimestamp).split(' ')[1]
    temp_time = time.split(':')
    hh,mn,ss = int(temp_time[0]),int(temp_time[1]),temp_time[2]
    #Seconds is received as floating and must be rationalized
    ss = rationalize(ss)
    datestamp = (yyyy,mm,dd)
    timestamp = (hh,mn,ss)
    return (datestamp,timestamp)

# https://stackoverflow.com/questions/2579535/convert-dd-decimal-degrees-to-dms-degrees-minutes-seconds-in-python
#Converting decimal latlongs to degree,min,sec format
def decdeg_to_dms(dd):
   is_positive = dd >= 0
   dd = abs(dd)
   minutes,seconds = divmod(dd*3600,60)
   degrees,minutes = divmod(minutes,60)
   degrees = degrees if is_positive else -degrees
   seconds_num,seconds_denom = rationalize(round(seconds,3))
   return ((int(degrees),1),(int(minutes),1),(seconds_num,seconds_denom))

#Data inputted into the exif needs to be in a particular format
def clean_data(dec_latitude,dec_longitude,dec_altitude,datetimestamp):
    latitude_tuple = decdeg_to_dms(dec_latitude)
    longitude_tuple = decdeg_to_dms(dec_longitude)
    altitude_tuple = rationalize(dec_altitude)
    date_stamp,time_stamp = clean_datetime(datetimestamp)
    date = date_stamp[0]+":"+date_stamp[1]+":"+date_stamp[2]
    date = bytes(date,'utf-8')
    time = ((time_stamp[0],1),(time_stamp[1],1),(time_stamp[2][0],time_stamp[2][1]))
    return (latitude_tuple,longitude_tuple,altitude_tuple,date,time)

def custom_exif(original_exif,make):
    camera_make = make
    #Standard GPS EXIF Format
    # https://exiftool.org/TagNames/GPS.html
    # exif_format = {0: (2, 2, 0, 0), 1: b'N', 2: ((0, 1), (0, 1), (0, 1)), 3: b'E', 4: ((0, 1), (0, 1), (2149, 125)), 5: 0, 6: (0, 1), 7: ((0,1),(0,1),(0,1)), 11: (10000, 1000), 27: b'ASCII\x00\x00\x00fused', 29: b'2018:08:22'}
    
    # RX0 EXIF FORMAT
    # {0: (2, 2, 0, 0), 1: b'N', 2: ((50, 1), (32, 1), (36, 1)), 3: b'E', 4: ((31, 1), (2, 1), (22, 1)), 5: 0, 6: (11500, 100), 18: b'WGS-84', 27: b'ASCII\x00\x00\x00HYBRID-FIX'}
    
    #Capturing dummy data
    latitude,longitude,altitude,datetimestamp = generate_data()

    #Cleaned and formatted data
    latitude,longitude,altitude,date_stamp,time_stamp = clean_data(latitude,longitude,altitude,datetimestamp)
    #TODO CHECK N/E notation signs
    # standard_exif_format = {0: GPSVersionID, 1: b'N', 2: latitude, 3: b'E', 4: longitude, 5: 0, 6: altitude, 7: time_stamp, 11: GPSDOP, 27: GPSProcessingMethod, 29: date_stamp}

    #RX0 exif
    if camera_make == "rx0":
        exif_format = {0: GPSVersionID, 1: b'N', 2: latitude, 3: b'E', 4: longitude, 5: 0, 6: altitude, 18:GPSMapDatum, 27: RX0_GPSProcessingMethod}
    else:
        exif_format = {0: GPSVersionID, 1: b'N', 2: latitude, 3: b'E', 4: longitude, 5: 0, 6: altitude, 7: time_stamp, 11: GPSDOP, 27: GPSProcessingMethod, 29: date_stamp}

    new_exif = exif_format
    return new_exif

def geo_tag(file_name,cam_type="rx0"):
    print(file_name)
    img = Image.open(file_name)

    #Read the exif data
    exif_dict = piexif.load(img.info['exif'])


    # "0th", "GPS", "Exif", "1st" are possible keys for exif_dict
    print(exif_dict["GPS"])

    # New EXIF data function
    exif_dict["GPS"] = custom_exif(exif_dict["GPS"],cam_type)

    print(exif_dict["GPS"])

    #Dump the data into the image
    exif_bytes = piexif.dump(exif_dict)

    #Dump in the same image
    # piexif.insert(exif_bytes, "tag2.jpg")

    #Dump in another image that is already present. here tag2_modified is already present before running the code
    final_img_name = file_name[:-4]+"_updated.jpg"
    img = img.save(final_img_name,quality=100)
    piexif.insert(exif_bytes, final_img_name)

    # end = time.time()

    # Current = 0.49111151695251465s
    # print(end-start)