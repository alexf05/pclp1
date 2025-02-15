#include "img.h"
img_t select_img(char command[], img_t image);
void crop(img_t *image);
img_t rotate(img_t img, char commad[]);
void copy_img(img_t *image, img_t img);
