#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void free_linear(int k, celula ***a)
{
	//facem free la memorie pana la linia K
	//la final se apeleaza cu n
	for (int i = 0; i < k; i++) {
		free((*a)[i]);
		(*a)[i] = NULL;
	}
	free(*a);
	*a = NULL;
}

celula **alloc_matrix(int n, int m)
{
	celula **a = (celula **)malloc(n * sizeof(celula *));
	if (!a) {
		free_linear(0, &a);
	}
	for (int i = 0; i < n; i++) {
		a[i] = (celula *)malloc(m * sizeof(celula));
		if (!a[i]) {
			free_linear(i, &a);
		}
	}
	return a;
}

int read(int *val_max_pix, int *lin, int *col, celula ***a)
{
	char trash;
	scanf("%c", &trash); //citim new line
	int n, m;

	char s[3];
	scanf("%s", s);
	if (strcmp(s, "P3")) {
		printf("Eroare: trebuie sa fie P3\n");
		return 1;
	}
	scanf("%c", &trash); //citim new line

	scanf("%d%d", &n, &m);
	if (n <= 0 || m <= 0) {
		printf("Eroare: valoare pixel necorespunzatoare\n");
		return 1;
	}
	*lin = n;
	*col = m;
	scanf("%d", val_max_pix);
	*a = alloc_matrix(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int r, g, b;
			int x;
			//citim cate un numar separat ca sa verificam daca se citeste
			//aviz testul 2
			if (scanf("%d", &x) == 1) {
				r = x;
			} else {
				printf("Eroare: eroare citire pixeli\n");
				return 1;
			}
			if (scanf("%d", &x) == 1) {
				g = x;
			} else {
				printf("Eroare: eroare citire pixeli\n");
				return 1;
			}
			if (scanf("%d", &x) == 1) {
				b = x;
			} else {
				printf("Eroare: eroare citire pixeli\n");
				return 1;
			}
			if (r > *val_max_pix || g > *val_max_pix ||
				b > *val_max_pix || r < 0 || g < 0 || b < 0) {
				printf("Eroare: valoare pixel necorespunzatoare\n");
				return 1;
				}
			(*a)[i][j].r = r;
			(*a)[i][j].g = g;
			(*a)[i][j].b = b;
		}
	}
	printf("Imagine citita cu succes [%d-%d]\n", *lin, *col);
	return 0;
}

void write_matrix(int val_max_pix, int n, int m, celula **mat)
{
	printf("P3\n%d %d\n%d\n", n, m, val_max_pix);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d %d %d\n", mat[i][j].r, mat[i][j].g, mat[i][j].b);
		}
	}
}
