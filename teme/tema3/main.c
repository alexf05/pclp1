#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "save.h"
#include "img.h"
#include "edit_img.h"
#include "equalize_histogram.h"
#include "filters.h"

img_t apply(char command[], img_t image)
{
	char tmp[101];
	tmp[0] = '\0';
	strcpy(tmp, command + 6);
	if (image.color == -1) {
		printf("No image loaded\n");
	} else if (tmp[0] == '\0') {
		printf("Invalid command\n");
	} else {
		if (strstr(command, "EDGE")) {
			if (image.color == 1 || image.color == 2) {
				printf("Easy, Charlie Chaplin\n");
			} else {
				image = filter(image, 0);
				printf("APPLY EDGE done\n");
			}
		} else if (strstr(command, "SHARPEN")) {
			if (image.color == 1 || image.color == 2) {
				printf("Easy, Charlie Chaplin\n");
			} else {
				image = filter(image, 1);
				printf("APPLY SHARPEN done\n");
			}
		} else if (strstr(command, "GAUSSIAN_BLUR")) {
			if (image.color == 1 || image.color == 2) {
				printf("Easy, Charlie Chaplin\n");
			} else {
				image = filter(image, 3);
				printf("APPLY GAUSSIAN_BLUR done\n");
			}
		} else if (strstr(command, "BLUR")) {
			if (image.color == 1 || image.color == 2) {
				printf("Easy, Charlie Chaplin\n");
			} else {
				image = filter(image, 2);
				printf("APPLY BLUR done\n");
			}
		} else {
			printf("APPLY parameter invalid\n");
		}
	}
	return image;
}

void save(char command[], img_t image)
{
	char file_name[101], isnotbinary[6], tmp[101];
	file_name[0] = '\0';
	isnotbinary[0] = '\0';
	tmp[0] = '\0';
	strcpy(tmp, command + 5);
	if (sscanf(tmp, "%s%s", file_name, isnotbinary) == 2) {
		save_ascii(file_name, image);
	} else {
		save_binary(file_name, image);
	}
}

int main(void)
{
	char command[201];
	command[0] = '\0';
	img_t image = init_img();
	while (fgets(command, sizeof(command), stdin)) {
		if (strstr(command, "LOAD")) {
			if (image.color != -1) {
				free_img(image);
			}
			image = type_file(command);
		} else if (strstr(command, "SAVE")) {
			save(command, image);
		} else if (strstr(command, "SELECT")) {
			if (image.color == -1) {
				printf("No image loaded\n");
			} else {
				if (strstr(command, "ALL")) {
					image.xi = 0;
					image.yi = 0;
					image.xf = image.width;
					image.yf = image.height;
					printf("Selected ALL\n");
				} else {
					image = select_img(command, image);
				}
			}
		} else if (strstr(command, "CROP")) {
			if (image.color == -1) {
				printf("No image loaded\n");
			} else {
				crop(&image);
			}
		} else if (strstr(command, "ROTATE")) {
			if (image.color == -1) {
				printf("No image loaded\n");
			} else {
				image = rotate(image, command);
			}
		} else if (strstr(command, "HISTOGRAM")) {
			char tmp[101];
			tmp[0] = '\0';
			int x = 0, y = 0, z = 0;
			strcpy(tmp, command + 10);
			if (image.color == -1) {
				printf("No image loaded\n");
			} else if (sscanf(tmp, "%d%d%d", &x, &y, &z) != 2) {
				printf("Invalid command\n");
			} else if (image.color == 1 || image.color == 3) {
				printf("Black and white image needed\n");
			} else {
				if (((y - 1) & y) || y > 256) {
					printf("Invalid set of parameters\n");
				} else {
					histogram(image, x, y);
				}
			}
		} else if (strstr(command, "EQUALIZE")) {
			if (image.color == -1) {
				printf("No image loaded\n");
			} else if (image.color == 1 || image.color == 3) {
				printf("Black and white image needed\n");
			} else {
				equalize(&image);
			}
		} else if (strstr(command, "APPLY")) {
			image = apply(command, image);
		} else if (strstr(command, "EXIT")) {
			if (image.color == -1) {
				printf("No image loaded\n");
			} else {
				free_img(image);
				return 0;
			}
		} else {
			printf("Invalid command\n");
		}
		strcpy(command, "\0");
	}
	return 0;
}
