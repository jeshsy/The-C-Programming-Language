#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  const int x = 800, y = 600;
  int i, j;
  FILE *imageFile = fopen("P3.ppm", "w"); /* P3 NOT in binary mode */
  /* I do not understand the use of (void) here */
  // looks like this next line is the header bytes for a p3 file
  (void) fprintf(imageFile, "P3\n%d %d\n255\n", x, y);
  for (j = 0; j < y; ++j) {
    for (i = 0; i < x; ++i) {
      //int offset = floor(sqrt(pow(x,2) + pow(y, 2)));
      int offset = i + j;
      int red = (255 + offset) % 255;
      int green = (255 + 2 * offset) % 255;
      int blue = (255 + 3 * offset) % 255;
     // int red = fabs(floor((j * 255 / 1024 - 35)));
     // int green = fabs(floor((i * 255 / 1024 - 112)));
     // int blue = fabs(floor(((i) * 255 / 1024 - 92)));
      fprintf(imageFile, "%d %d %d  ", red, green, blue);
    }
  }
  /* I do not understand the use of (void) here */
  (void) fclose(imageFile);
  return EXIT_SUCCESS;
}
