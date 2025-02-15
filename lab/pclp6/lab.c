#include <stdio.h>
#include <stdlib.h>

void read_vect(int *n, int **v)
{
	scanf("%d", n);
	*v =(int *) malloc(*n * sizeof(int));
	// int *a = *v;
	for (int i = 0; i < *n; i++) {
		scanf("%d", &(*v)[i]);//&a[i]
	}
}

void print_vect(int n, int *v)
{
   for (int i = 0; i < n; i++) {
	printf("%d ", v[i]);
   }
   printf("\n");

}

void read_dim_matrix(int *n, int *m)
{
	scanf("%d%d", n, m);
}

int **alloc_matrix(int n, int m)
{
	int **a = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		a[i] = calloc(m, sizeof(int));
	}
	return a;
}

void read_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void print_matrix(int n, int m, int **a)
{
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(int n, int **a)
{
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}

int **allonc_matrix_varlen(int n, int *nr_col)
{
	int **a = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		a[i] = calloc(nr_col[i], sizeof(int));
	}
	return a;
}

void free_matrix_varlen(int n, int **a)
{
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}

void printf_matrix_varlen(int n, int *nr_col, int **a)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < nr_col[i]; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void init_matrix_varlen(int n, int *nr_col, int **a)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < nr_col[i]; j++) {
			a[i][j] = ++cnt;
		}
	}	
}

int main(void)
{
	// int n;
	// scanf("%d", &n);
	// int *nr_col = malloc(n * sizeof(int));
	// int **a;
	// for (int i = 0; i < n; i++) {
	// 	scanf("%d", &nr_col[i]);
	// }
	// a = allonc_matrix_varlen(n, nr_col);
	// init_matrix_varlen(n, nr_col, a);
	// printf_matrix_varlen(n, nr_col, a);
	// free_matrix_varlen(n, a);
	int a[10][10];
	for(int i = 0; i < 9; i++) {
		int dif = (int) (&a[i][9] - &a[i+1][0]);
		printf("%d\n", dif);
	}
	return 0;
}