#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img.h"
#include "read.h"

void histogram(img_t img, int x, int y)
{
	int *v = calloc(y + 1, sizeof(int));
	int max = -1, tmp, dist = (img.max_value + 1) / y;
	for (int i = 0; i < img.height; i++) {
		for (int j = 0; j < img.width; j++) {
			tmp = img.grey[i][j] / dist;
			v[tmp]++;
			if (v[tmp] > max) {
				max = v[tmp];
			}
		}
	}
	for (int i = 0; i < y; i++) {
		tmp = v[i] * x / max;
		printf("%d\t|\t", tmp);
		for (int j = 0; j < tmp; j++) {
			printf("*");
		}
		printf("\n");
	}
	free(v);
}

void equalize(img_t *img)
{
	int *v = calloc(img->max_value + 1, sizeof(int));
	for (int i = 0; i < img->height; i++) {
		for (int j = 0; j < img->width; j++) {
			v[img->grey[i][j]]++;
		}
	}
	for (int i = 1; i <= img->max_value; i++) {
		v[i] = v[i - 1] + v[i];
	}
	int area = img->height * img->width;
	int x;
	for (int i = 0; i < img->height; i++) {
		for (int j = 0; j < img->width; j++) {
			x = 255 * v[img->grey[i][j]] / area;
			x > 255 ? x = 255 : 1;
			x < 0 ? x = 0 : 1;
			img->grey[i][j] = x;
		}
	}
	free(v);
	printf("Equalize done\n");
}
