#include "img.h"
img_t type_file(char command[]);
img_t init_img(void);
void free_img(img_t image);
img_t img_grey(int width, int height, int color);
img_t img_rgb(int width, int height);
