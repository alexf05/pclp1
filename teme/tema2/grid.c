#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void free_linear3(int k, int ***a)
{
	for (int i = 0; i < k; i++) {
		free((*a)[i]);
		(*a)[i] = NULL;
	}
	free(*a);
	*a = NULL;
}

int **alloc_matrix_int(int n, int m)
{
	//alocam o matrice dinamica de init
	//alocam +1 ca avem nevoie de inca una pt marching
	n = n / 4 + 1;
	m = m / 4 + 1;
	int **a = (int **)malloc(n * sizeof(int *));
	if (!a) {
		free_linear3(0, &a);
	}
	for (int i = 0; i < n; i++) {
		a[i] = (int *)calloc(m, sizeof(int));
		if (!a[i]) {
			free_linear3(i, &a);
		}
	}
	return a;
}

int sum_cel(celula a)
{
	//facem suma pe celula
	return a.r + a.g + a.b;
}

int corect_nod(int i, int j, int n, int m)
{
	//verificam daca elemtul este in matrice
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return 0;
	}
	return 1;
}

int valoare(celula **mat, int i, int j, int n, int m)
{
	//pentru fiecare dintre cele 5 noduri:
	//centru, NE, NV, SV, SE
	//facem intai media r,g,b si dupa imaprtim la nr de lemente adaugate
	int val = 0;
	int cnt = 0;
	int i1, j1;
	i1 = 4 * i;
	j1 = 4 * j;
	if (corect_nod(i1, j1, n, m)) {
		int valx = sum_cel(mat[i1][j1]) / 3;
		val += valx;
		cnt++;
	}
	i1 = 4 * i - 1;
	j1 = 4 * j - 1;
	if (corect_nod(i1, j1, n, m)) {
		int valx = sum_cel(mat[i1][j1]) / 3;
		val += valx;
		cnt++;
	}
	i1 = 4 * i - 1;
	j1 = 4 * j + 1;
	if (corect_nod(i1, j1, n, m)) {
		int valx = sum_cel(mat[i1][j1]) / 3;
		val += valx;
		cnt++;
	}
	i1 = 4 * i + 1;
	j1 = 4 * j - 1;
	if (corect_nod(i1, j1, n, m)) {
		int valx = sum_cel(mat[i1][j1]) / 3;
		val += valx;
		cnt++;
	}
	i1 = 4 * i + 1;
	j1 = 4 * j + 1;
	if (corect_nod(i1, j1, n, m)) {
		int valx = sum_cel(mat[i1][j1]) / 3;
		val += valx;
		cnt++;
	}
	val /= cnt;
	return val;
}

int **grid(int *n, int *m, celula **mat)
{
	int **a = alloc_matrix_int(*n, *m);

	for (int i = 0; i <= *n / 4 ; i++) {
		for (int j = 0; j <= *m / 4 ; j++) {
			int val = valoare(mat, i, j, *n, *m);
			int alfa = 200;
			if (val > alfa) {
				a[i][j] = 0;
			} else {
				a[i][j] = 1;
			}
		}
	}
	*n = *n / 4;
	*m = *m / 4;
	return a;
}

void print_grid(int n, int m, int **a)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
