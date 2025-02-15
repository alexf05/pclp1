#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "init_contur.h"

void free_linear4(int k, celula **a)
{
	for (int i = 0; i < k; i++) {
		free(a[i]);
	}
	free(a);
}

celula **alloc_matrix2(int n, int m)
{
	n *= 4;
	m *= 4;
	celula **a = (celula **)malloc(n * sizeof(celula *));
	if (!a) {
		free_linear4(0, a);
	}
	for (int i = 0; i < n; i++) {
		a[i] = (celula *)malloc(m * sizeof(celula));
		if (!a[i]) {
			free_linear4(i, a);
		}
	}
	return a;
}

int binar(int i, int j, int **a)
{
	int b = 0;
	b = 8 * a[i][j] + 4 * a[i][j + 1] + 2 * a[i + 1][j + 1] + a[i + 1][j];
	return b;
}

celula **march(int *n, int *m, int **mat)
{
	celula **a = alloc_matrix2(*n, *m);
	// printf("\n");
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			int m[4][4];
			int k = binar(i, j, mat);
			if (k < 8) {
				contur_1(k, m);
			} else {
				contur_2(k, m);
			}
			for (int i1 = 0; i1 < 4; i1++) {
				for (int j1 = 0; j1 < 4; j1++) {
					int i2 = i * 4 + i1;
					int j2 = j * 4 + j1;
					a[i2][j2].r = m[i1][j1];
					a[i2][j2].g = m[i1][j1];
					a[i2][j2].b = m[i1][j1];
				}
			}
		}
	}
	*n *= 4;
	*m *= 4;
	return a;
}
