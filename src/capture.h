#include <fcntl.h>
#include <gphoto2/gphoto2.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "defines.h"
#include <time.h>

static void capture_to_file(Camera *camera, GPContext *context, char *fn);
std::string capture_image(std::string path, std::string imagename);
