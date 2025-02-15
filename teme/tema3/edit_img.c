#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img.h"
#include "read.h"

void swap_int(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

img_t select_img(char command[], img_t img)
{
	img_t image = img;
	char save[6];
	save[0] = '\0';
	int xi = 0, xf = 0, yi = 0, yf = 0;
	if (sscanf(command, "%s%d%d%d%d", save, &xi, &yi, &xf, &yf) != 5) {
		printf("Invalid command\n");
		return image;
	}
	if (xi > xf) {
		swap_int(&xi, &xf);
	}
	if (yi > yf) {
		swap_int(&yi, &yf);
	}
	if (xi < 0 || yi < 0 || xf > image.width || yf > image.height ||
		xi == xf || yi == yf) {
		printf("Invalid set of coordinates\n");
		return image;
	}
	image.xi = xi; image.yi = yi;
	image.xf = xf; image.yf = yf;
	printf("Selected %d %d %d %d\n", xi, yi, xf, yf);
	return image;
}

void copy_img(img_t *image, img_t img)
{
	image->color = img.color;
	image->height = img.height;
	image->width = img.width;
	image->max_value = img.max_value;
	image->xf = img.xf;
	image->yf = img.yf;
	image->xi = img.xi;
	image->yi = img.yi;
}

void crop(img_t *img)
{
	for (int i = 0; i < img->yf - img->yi; i++) {
		for (int j = 0; j < img->xf - img->xi; j++) {
			if (img->color == 1 || img->color == 2) {
				img->grey[i][j] = img->grey[i + img->yi][j + img->xi];
			} else if (img->color == 3) {
				for (int k = 0; k < 3; k++) {
					img->rgb[k][i][j] = img->rgb[k][i + img->yi][j + img->xi];
				}
			}
		}
	}

	if (img->color == 1 || img->color == 2) {
		for (int i = img->yf - img->yi; i < img->height; i++) {
			free(img->grey[i]);
		}
		for (int i = 0; i < img->yf - img->yi; i++) {
			img->grey[i] = realloc(img->grey[i], (img->xf - img->xi)
								   * sizeof(unsigned char));
		}
		img->grey = realloc(img->grey, (img->yf - img->yi)
							* sizeof(unsigned char *));
	} else if (img->color == 3) {
		for (int k = 0; k < 3; k++) {
			for (int i = img->yf - img->yi; i < img->height; i++) {
				free(img->rgb[k][i]);
			}
			for (int i = 0; i < img->yf - img->yi; i++) {
				img->rgb[k][i] = realloc(img->rgb[k][i], (img->xf - img->xi)
										 * sizeof(unsigned char));
			}
			img->rgb[k] = realloc(img->rgb[k], (img->yf - img->yi)
								  * sizeof(unsigned char *));
		}
	}

	img->height = img->yf - img->yi;
	img->width = img->xf - img->xi;
	img->xi = 0;
	img->yi = 0;
	img->xf = img->width;
	img->yf = img->height;

	printf("Image cropped\n");
}

int angle_rotate(char str[])
{
	str[strlen(str) - 1] = '\0';
	if (!strcmp(str, "+90") || !strcmp(str, "90"))
		return 90;
	if (!strcmp(str, "+180") || !strcmp(str, "180"))
		return 180;
	if (!strcmp(str, "+270") || !strcmp(str, "270"))
		return 270;
	if (!strcmp(str, "+360") || !strcmp(str, "360"))
		return 0;
	if (!strcmp(str, "-360"))
		return 0;
	if (!strcmp(str, "0"))
		return 0;
	if (!strcmp(str, "-270"))
		return 90;
	if (!strcmp(str, "-180"))
		return 180;
	if (!strcmp(str, "-90"))
		return 270;
	return -1;
}

img_t rotate_switch(int angle, img_t img, img_t tmp)
{
	img_t image = img;
	if (img.xi == 0 && img.yi == 0 && img.xf == img.width &&
		img.yf == img.height && (angle == 270 || angle == 90)) {
		free_img(image);
		if (img.color == 1 || img.color == 2) {
			image = img_grey(tmp.height, tmp.width, img.color);
		} else if (img.color == 3) {
			image = img_rgb(tmp.height, tmp.width);
		}
		if (image.color == 2 || image.color == 3) {
			image.max_value = img.max_value;
		}
	}
	switch (angle) {
	case 90:
		for (int i = 0; i < image.yf - image.yi; i++) {
			for (int j = 0; j < image.xf - image.xi; j++) {
				if (image.color == 1 || image.color == 2) {
					image.grey[i + image.yi][j + image.xi] =
					tmp.grey[tmp.height - j - 1][i];
				} else {
					for (int k = 0; k < 3; k++) {
						image.rgb[k][i + image.yi][j + image.xi] =
						tmp.rgb[k][tmp.height - j - 1][i];
					}
				}
			}
		}
		break;
	case 180:
		for (int i = 0; i < image.yf - image.yi; i++) {
			for (int j = 0; j < image.xf - image.xi; j++) {
				if (image.color == 1 || image.color == 2) {
					image.grey[i + image.yi][j + image.xi] =
					tmp.grey[tmp.height - i - 1][tmp.width - 1 - j];
				} else {
					for (int k = 0; k < 3; k++) {
						image.rgb[k][i + image.yi][j + image.xi] =
						tmp.rgb[k][tmp.height - i - 1][tmp.width - 1 - j];
					}
				}
			}
		}
		break;
	case 270:
		for (int i = 0; i < image.yf - image.yi; i++) {
			for (int j = 0; j < image.xf - image.xi; j++) {
				if (image.color == 1 || image.color == 2) {
					image.grey[i + image.yi][j + image.xi] =
					tmp.grey[j][tmp.width - 1 - i];
				} else {
					for (int k = 0; k < 3; k++) {
						image.rgb[k][i + image.yi][j + image.xi] =
						tmp.rgb[k][j][tmp.width - 1 - i];
					}
				}
			}
		}
		break;
	default:
		break;
	}
	free_img(tmp);
	return image;
}

img_t rotate(img_t img, char command[])
{
	char t[101];
	strcpy(t, command + 7);
	int angle = angle_rotate(t);

	if (angle == -1) {
		printf("Unsupported rotation angle\n");
		return img;
	}
	if ((img.xi != 0 || img.yi != 0 || img.xf != img.width ||
	     img.yf != img.height) && img.xf - img.xi != img.yf - img.yi) {
		printf("The selection must be square\n");
		return img;
	}

	img_t tmp = init_img();
	//copy the matrix
	if (img.color == 1 || img.color == 2) {
		tmp = img_grey(img.xf - img.xi, img.yf - img.yi, img.color);
		for (int i = 0; i < tmp.height; i++) {
			for (int j = 0; j < tmp.width; j++) {
				tmp.grey[i][j] = img.grey[i + img.yi][j + img.xi];
			}
		}
	} else if (img.color == 3) {
		tmp = img_rgb(img.xf - img.xi, img.yf - img.yi);
		for (int i = 0; i < tmp.height; i++) {
			for (int j = 0; j < tmp.width; j++) {
				for (int k = 0; k < 3; k++) {
					tmp.rgb[k][i][j] = img.rgb[k][i + img.yi][j + img.xi];
				}
			}
		}
	}
	printf("Rotated %s\n", t);
	return rotate_switch(angle, img, tmp);
}
