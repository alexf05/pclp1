#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img.h"
#include "read.h"
#include "edit_img.h"

int clamp(float x, img_t img)
{
	if (x > img.max_value) {
		return img.max_value;
	}
	if (x < 0) {
		return 0;
	}
	return (int)x;
}

img_t filter(img_t img, int filter)
{
	float coeff[4][9] = {
		{-1.0, -1.0, -1.0, -1.0, 8.0, -1.0, -1.0, -1.0, -1.0},
		{0.0, -1.0, 0.0, -1.0, 5.0, -1.0, 0.0, -1.0, 0.0},
		{1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9,
		1.0 / 9, 1.0 / 9, 1.0 / 9},
		{1.0 / 16, 2.0 / 16, 1.0 / 16, 2.0 / 16, 4.0 / 16, 2.0 / 16,
		1.0 / 16, 2.0 / 16, 1.0 / 16}
	};
	int index[2][9] = {
		{-1, -1, -1, 0, 0, 0, 1, 1, 1},
		{-1, 0, 1, -1, 0, 1, -1, 0, 1}
	};
	img_t image;
	image = img_rgb(img.width, img.height);
	copy_img(&image, img);

	float value;
	for (int i = 0; i < image.height; i++) {
		for (int j = 0; j < image.width; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == 0 || j == 0 || i == image.height - 1 ||
					j == image.width - 1 || i < image.yi || i >= image.yf ||
				j < image.xi || j >= image.xf) {
					image.rgb[k][i][j] = img.rgb[k][i][j];
				} else {
					value = 0;
					for (int t = 0; t < 9; t++) {
						value += coeff[filter][t] * (float)
								img.rgb[k][i + index[0][t]][j + index[1][t]];
					}
					image.rgb[k][i][j] = clamp(value, img);
				}
			}
		}
	}
	free_img(img);
	return image;
}
