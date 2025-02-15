#ifndef img_d
#define img_d
typedef struct {
	int width, height;
	int color;
	//1- black and white, 2- greyscale, 3- rgb
	unsigned char **grey;
	unsigned char **rgb[3];
	//r-0, g-1, b-2
	int max_value;
	int xi, xf, yi, yf;
	//the selected portion of the matrix
} img_t;
#endif
