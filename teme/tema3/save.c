#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img.h"

void save_ascii(char file_name[], img_t image)
{
	FILE *out = fopen(file_name, "wt");
	if (image.color == -1) {
		printf("No image loaded\n");
	} else {
		fprintf(out, "P%d\n", image.color);
		fprintf(out, "%d %d\n", image.width, image.height);
		if (image.color == 2 || image.color == 3) {
			fprintf(out, "%d\n", image.max_value);
		}
		for (int i = 0 ; i < image.height; i++) {
			for (int j = 0; j < image.width; j++) {
				if (image.color == 2 || image.color == 1) {
					fprintf(out, "%d ", image.grey[i][j]);
				} else if (image.color == 3) {
					for (int k = 0; k < 3; k++) {
						fprintf(out, "%d ", image.rgb[k][i][j]);
					}
				}
			}
			fprintf(out, "\n");
		}
		printf("Saved %s\n", file_name);
	}
	fclose(out);
}

void print_ascii(img_t image)
{
	if (image.color == -1) {
		printf("No image loaded\n");
	} else {
		printf("P%d\n", image.color);
		printf("%d %d\n", image.width, image.height);
		if (image.color == 2 || image.color == 3) {
			printf("%d\n", image.max_value);
		}
		for (int i = 0 ; i < image.height; i++) {
			for (int j = 0; j < image.width; j++) {
				if (image.color == 2 || image.color == 1) {
					printf("%d %d\n", i, j);
				} else if (image.color == 3) {
					for (int k = 0; k < 3; k++) {
						printf("%d %d %d\n", i, j, k);
					}
				}
			}
		}
	}
}

void save_binary(char file_name[], img_t image)
{
	FILE *out = fopen(file_name, "wb");
	if (image.color == -1) {
		printf("No image loaded\n");
	} else {
		fprintf(out, "P%d\n", image.color + 3);
		fprintf(out, "%d %d\n", image.width, image.height);
		if (image.color == 2 || image.color == 3) {
			fprintf(out, "%d\n", image.max_value);
		}
		for (int i = 0 ; i < image.height; i++) {
			if (image.color == 2 || image.color == 1) {
				fwrite(image.grey[i], sizeof(unsigned char), image.width, out);
			} else if (image.color == 3) {
				for (int j = 0; j < image.width; j++) {
					for (int k = 0; k < 3; k++) {
						fwrite(&image.rgb[k][i][j], sizeof(unsigned char),
							   1, out);
					}
				}
			}
		}
		printf("Saved %s\n", file_name);
	}
	fclose(out);
}
