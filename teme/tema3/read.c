#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img.h"

#define NMAX 100000

void free_img(img_t img)
{
	img_t image = img;
	if (image.color == 1 || image.color == 2) {
		for (int i = 0; i < image.height; i++) {
			free(image.grey[i]);
		}
		free(image.grey);
	} else if (image.color == 3) {
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < image.height; i++) {
				free(image.rgb[k][i]);
			}
			free(image.rgb[k]);
		}
	}
}

img_t init_img(void)
{
	img_t img;
	img.color = -1;
	img.height = -1;
	img.width = -1;
	img.max_value = -1;
	img.rgb[0] = NULL;
	img.rgb[1] = NULL;
	img.rgb[2] = NULL;
	img.grey = NULL;
	img.xi = -1;
	img.xf = -1;
	img.yi = -1;
	img.yf = -1;
	return img;
}

img_t img_grey(int width, int height, int color)
{
	img_t image = init_img();
	image.height = height;
	image.width = width;
	image.color = color;
	image.xi = 0;
	image.yi = 0;
	image.xf = image.width;
	image.yf = image.height;
	image.grey = malloc(height * sizeof(unsigned char *));
	for (int i = 0; i < height; i++) {
		image.grey[i] = calloc(width, sizeof(unsigned char));
	}
	return image;
}

img_t img_rgb(int width, int height)
{
	img_t image = init_img();
	image.height = height;
	image.width = width;
	image.color = 3;
	image.xi = 0;
	image.yi = 0;
	image.xf = image.width;
	image.yf = image.height;
	for (int k = 0; k < 3; k++) {
		image.rgb[k] = malloc(height * sizeof(unsigned char *));
		for (int i = 0; i < height; i++) {
			image.rgb[k][i] = calloc(width, sizeof(unsigned char));
		}
	}
	return image;
}

void grey_images(char *line, img_t *image, int *n)
{
	char *t = strtok(line, " \t");
	while (t) {
		if (strchr("0123456789", t[0])) {
			if (sscanf(t, "%hhu", &image->grey[(*n) / image->width]
											  [(*n) % image->width]) != 1) {
				printf("Something isn't right\n");
				return;
			}
			(*n)++;
		}
		t = strtok(NULL, " \t");
	}
}

void rgb_images(char *line, img_t *image, int *k, int *n)
{
	char *t = strtok(line, " \t");
	while (t) {
		if (strchr("0123456789", t[0])) {
			if (sscanf(t, "%hhu", &image->rgb[*k][(*n) / image->width]
					[(*n) % image->width]) != 1) {
				printf("Something isn't right\n");
				return;
			}
			(*k)++;
			if (*k == 3) {
				(*n)++;
				*k = 0;
			}
		}
		t = strtok(NULL, " \t");
	}
}

img_t read_ascii(FILE *in)
{
	img_t image;
	fseek(in, 0, SEEK_SET);
	char type_image[5];
	fgets(type_image, 3, in);
	char *line = malloc(NMAX * sizeof(char));
	fgets(line, NMAX, in);

	do {
		fgets(line, NMAX, in);
	} while (line[0] == '#');

	if (sscanf(line, "%d%d", &image.width, &image.height) != 2) {
		printf("Something isn't right\n");
		return init_img();
	}

	if (strchr(type_image, '1')) {
		image = img_grey(image.width, image.height, 1);
	} else if (strchr(type_image, '2')) {
		image = img_grey(image.width, image.height, 2);
	} else if (strchr(type_image, '3')) {
		image = img_rgb(image.width, image.height);
	} else {
		printf("nu este imagine corespunzatoare\n");
	}

	if (image.color == 2 || image.color == 3) {
		do {
			fgets(line, NMAX, in);
		} while (line[0] == '#');
		if (sscanf(line, "%d", &image.max_value) != 1) {
			printf("Something isn't right\n");
			return init_img();
		}
	}

	int n = 0; //how many elements we read
	int k = 0; //for rgb

	while (fgets(line, NMAX, in)) {
		if (!strchr(line, '#')) {
			if (image.color == 1 || image.color == 2) {
				grey_images(line, &image, &n);
			} else if (image.color == 3) {
				rgb_images(line, &image, &k, &n);
			}
		}
	}
	free(line);
	fclose(in);
	return image;
}

img_t read_binary(FILE *in)
{
	img_t image;
	fseek(in, 0, SEEK_SET);
	char type_image[5];
	fgets(type_image, 3, in);
	char *line = malloc(NMAX * sizeof(char));
	fgets(line, NMAX, in);

	do {
		fgets(line, NMAX, in);
	} while (line[0] == '#');

	if (sscanf(line, "%d%d", &image.width, &image.height) != 2) {
		printf("Something isn't right\n");
		return init_img();
	}

	if (strchr(type_image, '4')) {
		image = img_grey(image.width, image.height, 1);
	} else if (strchr(type_image, '5')) {
		image = img_grey(image.width, image.height, 2);
	} else if (strchr(type_image, '6')) {
		image = img_rgb(image.width, image.height);
	} else {
		printf("nu este imagine corespunzatoare\n");
	}

	if (image.color == 2 || image.color == 3) {
		do {
			fgets(line, NMAX, in);
		} while (line[0] == '#');
		if (sscanf(line, "%d", &image.max_value) != 1) {
			printf("Something isn't right\n");
			return init_img();
		}
	}

	if (image.color == 1 || image.color == 2) {
		for (int i = 0; i < image.height; i++) {
			fread(image.grey[i], sizeof(unsigned char), image.width, in);
		}
	} else if (image.color == 3) {
		for (int i = 0; i < image.height; i++) {
			for (int j = 0; j < image.width; j++) {
				for (int k = 0; k < 3; k++) {
					fread(&image.rgb[k][i][j], sizeof(unsigned char), 1, in);
				}
			}
		}
	}
	fclose(in);
	free(line);
	return image;
}

img_t type_file(char command[])
{
	FILE *in;
	char type_image[5];
	char file_input[101];
	strcpy(file_input, command + 5);
	file_input[strlen(file_input) - 1] = '\0';

	img_t image = init_img();
	in = fopen(file_input, "rt");
	if (!in) {
		printf("Failed to load %s\n", file_input);
		return image;
	}
	if (fscanf(in, "%s", type_image) == 1 && strchr("123", type_image[1])) {
		printf("Loaded %s\n", file_input);
		return read_ascii(in);
	}
	fclose(in);
	in = fopen(file_input, "rb");
	if (!in) {
		printf("Failed to load %s\n", file_input);
		return image;
	}
	if (fscanf(in, "%s", type_image) == 1 && strchr("456", type_image[1])) {
		printf("Loaded %s\n", file_input);
		return read_binary(in);
	}
	printf("Failed to load %s\n", file_input);
	fclose(in);
	return image;
}
