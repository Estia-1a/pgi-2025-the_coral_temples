#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    tenth_pixel(configuration.filenames[0]);
  }
  /*
   * TO COMPLETE
   */
  
   
   if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.filenames[0]);
}
  
  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    dimension(configuration.filenames[0]);
}
  if ( strncmp( configuration.command, "max_component", 13 ) == 0 ) {
    char component = argv[5][0];
    max_component(configuration.filenames[0], component);
  }

  if ( strncmp( configuration.command, "min_component", 13 ) == 0 ) {
    char component = argv[5][0];
    min_component(configuration.filenames[0], component);
  }

  if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    /* min_pixel() function is defined in feature.h and implemented in feature.c */
    min_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "max_pixel", 9 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    max_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    color_red(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_green", 11 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    color_green(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_blue", 10 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    color_blue(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "rotate_cw", 9 ) == 0 ) {
    /* rotate_cw() function is defined in feature.h and implemented in feature.c */
    rotate_cw(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "rotate_acw", 10 ) == 0 ) {
    /* rotate_cw() function is defined in feature.h and implemented in feature.c */
    rotate_acw(configuration.filenames[0]);
  }
  
  if ( strncmp( configuration.command, "color_gray", 10 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    color_gray(configuration.filenames[0]);
  }
 
  if ( strncmp( configuration.command, "color_gray_luminance", 20 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    color_gray_luminance(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_invert", 12 ) == 0 ) {
    /* color_invert() function is defined in feature.h and implemented in feature.c */
    color_invert(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "mirror_horizontal", 17 ) == 0 ) {
    /* miror_horizontal() function is defined in feature.h and implemented in feature.c */
    mirror_horizontal(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_desaturate", 16 ) == 0 ) {
    /* color_desaturatet() function is defined in feature.h and implemented in feature.c */
    color_desaturate(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "mirror_vertical", 15 ) == 0 ) {
    /* miror_vertical() function is defined in feature.h and implemented in feature.c */
    mirror_vertical(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "mirror_total", 12 ) == 0 ) {
    /* mirror_total() function is defined in feature.h and implemented in feature.c */
    mirror_total(configuration.filenames[0]);
  }
  
  if (strncmp(configuration.command, "scale_crop", 10) == 0) {
    if (argc < 9) {
        printf("Plase use with: freud.exe -f image.jpeg -c scale_crop center_x center_y width height\n");
    } 
    else {
      int center_x = atoi(argv[5]);
      int center_y = atoi(argv[6]);
      int crop_width = atoi(argv[7]);
      int crop_height = atoi(argv[8]);

      scale_crop(configuration.filenames[0], center_x, center_y, crop_width, crop_height);
      }
  }

  if (strncmp(configuration.command, "scale_nearest", 13) == 0) {
    if (argc >= 6) {
      float scale = atof(argv[5]);
      scale_nearest(configuration.filenames[0], scale);
    } 
    else {
      printf("Please used wit: freud.exe -f image.jpeg -c scale_nearest X\n");
    }
  }

  if (strncmp(configuration.command, "scale_bilinear", 14) == 0) {
    if (argc >= 6) {
      float scale = atof(argv[5]);
      scale_bilinear(configuration.filenames[0], scale);
    } 
    else {
      printf("Please use with: freud.exe -f image.jpeg -c scale_bilinear X\n");
    }
  }

  if (strncmp(configuration.command, "second_line", 11) == 0) {
    second_line(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "print_pixel", 11) == 0) {
    if (argc >= 7) {
      int x = atoi(argv[5]);
      int y = atoi(argv[6]);
      print_pixel(configuration.filenames[0], x, y);
    } 
    else {
      printf("Usage: freud.exe -f image.jpeg -c print_pixel x y\n");
    }
  }

  return 0;

}
