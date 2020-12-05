/*
 * This code released into the public domain 21 July 2008
 *
 * This program does the equivalent of:
 * gphoto2 --shell
 *   > set-config capture=1
 *   > capture-image-and-download
 * compile with gcc -Wall -o canon-capture -lgphoto2 canon-capture.c
 *
 * Taken from:
 * http://credentiality2.blogspot.com/2008/07/linux-libgphoto2-image-capture-from.html
 *
 * and condensed into simple capture sample
 */

/*
 g++ sample-capture.c autodetect.c config.c context.c -lgphoto2 -lgphoto2_port
*/
#include "defines.h"
#include <fcntl.h>
#include <gphoto2/gphoto2.h>
#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
static void errordumper(GPLogLevel level, const char *domain, const char *str,
                        void *data) {
  fprintf(stdout, "%s\n", str);
}

static void capture_to_file(Camera *camera, GPContext *context, char *fn) {
  int fd, retval;
  CameraFile *file;
  CameraFilePath camera_file_path;

  printf("Capturing.\n");

  /* NOP: This gets overridden in the library to /capt0000.jpg */
  strcpy(camera_file_path.folder, "/");
  strcpy(camera_file_path.name, "foo.jpg");

  retval =
      gp_camera_capture(camera, GP_CAPTURE_IMAGE, &camera_file_path, context);
  printf("  Retval: %d\n", retval);

  printf("Pathname on the camera: %s/%s\n", camera_file_path.folder,
         camera_file_path.name);

  fd = open(fn, O_CREAT | O_WRONLY | O_BINARY, 0644);
  retval = gp_file_new_from_fd(&file, fd);
  printf("  Retval: %d\n", retval);
  retval =
      gp_camera_file_get(camera, camera_file_path.folder, camera_file_path.name,
                         GP_FILE_TYPE_NORMAL, file, context);
  printf("  Retval: %d\n", retval);

  gp_file_free(file);

  printf("Deleting.\n");
  retval = gp_camera_file_delete(camera, camera_file_path.folder,
                                 camera_file_path.name, context);
  printf("  Retval: %d\n", retval);
}

std::string capture_image(std::string path, std::string imagename) {
  Camera *camera;
  int retval;
  GPContext *context = sample_create_context();
  FILE *f;
  char *data;
  unsigned long size;

  //~ gp_log_add_func(GP_LOG_ERROR, errordumper, NULL);
  gp_camera_new(&camera);

  /* When I set GP_LOG_DEBUG instead of GP_LOG_ERROR above, I noticed that the
   * init function seems to traverse the entire filesystem on the camera.  This
   * is partly why it takes so long.
   * (Marcus: the ptp2 driver does this by default currently.)
   */
  printf("Camera init.  Takes about 10 seconds.\n");
  retval = gp_camera_init(camera, context);
  if (retval != GP_OK) {
    printf("  Retval of capture_to_file: %d\n", retval);
    exit(1);
  }

  clock_t begin, end;
  begin = clock();
  //~ std::cout << path << std::endl;
  std::string temp = path + "/" + imagename + ".jpg";
  std::cout << temp;
  char *fpath = new char[temp.length() + 1];
  strcpy(fpath, temp.c_str());
  //~ std::cout << "FINAL PATH IS: " << std::endl;
  capture_to_file(camera, context, fpath);
  // capture_to_memory(camera, context, (const char**)&data, &size);
  end = clock();
  double time = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time taken is %f\n", time);
  /*f = fopen("foo2.jpg", "wb");
  if (f) {
          retval = fwrite (data, size, 1, f);
          if (retval != (int)size) {
                  printf("  fwrite size %ld, written %d\n", size, retval);
          }
          fclose(f);
  } else
          printf("  fopen foo2.jpg failed.\n"); */
  gp_camera_exit(camera, context);
  return temp;
}
