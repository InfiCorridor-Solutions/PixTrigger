#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <gphoto2/gphoto2.h>

#include "defines.h"
#include <time.h>

static void
capture_to_file(Camera *camera, GPContext *context, char *fn);
std::string capture_image(std::string path, std::string imagename);
