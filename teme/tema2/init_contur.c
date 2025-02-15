#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void contur_1(int x, int a[4][4])
{
	//primele 8 cazuri
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			switch (x) {
			case 0:
				a[i][j] = 0;
				break;
			case 1:
				if (i == 3 && j == 0) {
					a[i][j] = 180;
				} else if ((i == 2 && j == 0) || (i == 3 && j == 1)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 0;
				}
				break;
			case 2:
				if (i == 3 && j == 3) {
					a[i][j] = 180;
				} else if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 0;
				}
				break;
			case 3:
				if (i == 2) {
					a[i][j] = 255;
				} else if (i == 3) {
					a[i][j] = 180;
				} else {
					a[i][j] = 0;
				}
				break;
			case 4:
				if (i == 0 && j == 3) {
					a[i][j] = 180;
				} else if ((i == 1 && j == 3) || (i == 0 && j == 2)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 0;
				}
				break;
			case 5:
				if ((i == 0 && j == 3) || (i == 3 && j == 0)) {
					a[i][j] = 180;
				} else if ((i == 1 && j == 3) || (i == 0 && j == 2) ||
						   (i == 2 && j == 0) || (i == 3 && j == 1)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 0;
				}
				break;
			case 6:
				if (j == 2) {
					a[i][j] = 255;
				} else if (j == 3) {
					a[i][j] = 180;
				} else {
					a[i][j] = 0;
				}
				break;
			case 7:
				if (i == 0 && j == 0) {
					a[i][j] = 0;
				} else if ((i == 1 && j == 0) || (i == 0 && j == 1)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 180;
				}
				break;
			}
		}
	}
}

void contur_2(int x, int a[4][4])
{
	//urmatoarele 8 cazuri
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			switch (x) {
			case 8:
				if (i == 0 && j == 0) {
					a[i][j] = 180;
				} else if ((i == 1 && j == 0) || (i == 0 && j == 1)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 0;
				}
				break;
			case 9:
				if (j == 1) {
					a[i][j] = 255;
				} else if (j == 0) {
					a[i][j] = 180;
				} else {
					a[i][j] = 0;
				}
				break;
			case 10:
				if ((i == 0 && j == 0) || (i == 3 && j == 3)) {
					a[i][j] = 180;
				} else if ((i == 1 && j == 0) || (i == 0 && j == 1) ||
						   (i == 2 && j == 3) || (i == 3 && j == 2)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 0;
				}
				break;
			case 11:
				if (i == 0 && j == 3) {
					a[i][j] = 0;
				} else if ((i == 1 && j == 3) || (i == 0 && j == 2)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 180;
				}
				break;
			case 12:
				if (i == 1) {
					a[i][j] = 255;
				} else if (i == 0) {
					a[i][j] = 180;
				} else {
					a[i][j] = 0;
				}
				break;
			case 13:
				if (i == 3 && j == 3) {
					a[i][j] = 0;
				} else if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 180;
				}
				break;
			case 14:
				if (i == 3 && j == 0) {
					a[i][j] = 0;
				} else if ((i == 2 && j == 0) || (i == 3 && j == 1)) {
					a[i][j] = 255;
				} else {
					a[i][j] = 180;
				}
				break;
			case 15:
				a[i][j] = 255;
				break;
			default:
				break;
			}
		}
	}
}

void print_contur(int mat[4][4])
{
	printf("P3\n4 4\n255\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d %d %d\n", mat[i][j], mat[i][j], mat[i][j]);
		}
	}
}
