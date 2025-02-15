#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void free_linear2(int k, celula **a)
{
	for (int i = 0; i < k; i++) {
		free(a[i]);
		a[i] = NULL;
	}
	free(a);
	a = NULL;
}

celula **resize_k(int n, int m, celula **mat, int k)
{
	n = n * 4;
	m = m * 4;
	celula **a = (celula **)malloc(n * sizeof(celula *));
	if (!a) {
		printf("Programul a crapat! :(\n");
		free_linear2(0, a);
		free_linear2(0, mat);
	}
	for (int i = 0; i < n; i++) {
		if (i < n / k) {
			a[i] = (celula *)realloc(mat[i], m * sizeof(celula));
		} else {
			a[i] = (celula *)malloc(m * sizeof(celula));
		}
		if (!a[i]) {
			printf("Programul a crapat! :(\n");
			free_linear2(i, a);
			free_linear2(i, mat);
		}
	}
	free(mat);
	return a;
}

void cpy(celula *x, celula y)
{
	x->b = y.b;
	x->g = y.g;
	x->r = y.r;
}

void resize(int *n, int *m, celula ***mat)
{
	*mat = resize_k(*n, *m, *mat, 4);
	*n *= 4;
	*m *= 4;
	for (int i = *n - 1; i >= 0; i--) {
		for (int j = *m - 1; j >= 0; j--) {
			cpy(&((*mat)[i][j]), (*mat)[i / 4][j / 4]);
		}
	}
	printf("Imagine redimensionata cu succes [%d-%d]\n", *n, *m);
}
