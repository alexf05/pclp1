//FECHET Alex-Ciprian, 314CA
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_write_celula.h"
#include "resize.h"
#include "grid.h"
#include "init_contur.h"
#include "march.h"
#define NMAX 100

int main(void)
{
	char s[20];
	scanf("%s", s);

	int n_celula, m_celula, val_max_pix;
	int n_grid, m_grid;
	//n_celula,m_celula- dimensiunile de la matricea tip celula
	//n_grid, m_grid- dimensiunile celei de a doua matrice, de tip int
	celula **mat_celula = NULL;
	int **mat_grid = NULL;
	int cont[4][4];
	//matricea care retine contururile
	int ok = 0;

	while (!(strncmp(s, "EXIT", 4) == 0) && !ok) {
		if (!strcmp(s, "READ")) {
			if (mat_grid) {
				free_linear3(n_grid + 1, &mat_grid);
			}
			if (mat_celula) {
				free_linear(n_celula, &mat_celula);
			}
			//incepem o noua sesiune si eliberam eventualele matrici folosite
			//pana atunci
			n_celula = 0;
			m_celula = 0;
			ok = read(&val_max_pix, &n_celula, &m_celula, &mat_celula);
			n_grid = n_celula;
			m_grid = m_celula;
			//intializam dimensiunile matricei grid cu n_celula si m_celula
		} else if (!strcmp(s, "WRITE")) {
			write_matrix(val_max_pix, n_celula, m_celula, mat_celula);
		} else if (!strcmp(s, "MARCH")) {
			//daca nu am avut comanda GRID inainte, o simulam acum
			if (!mat_grid) {
				n_grid = n_celula;
				m_grid = m_celula;
				mat_grid = grid(&n_grid, &m_grid, mat_celula);
			}
			free_linear(n_celula, &mat_celula);
			n_celula = n_grid;
			m_celula = m_grid;
			mat_celula = march(&n_celula, &m_celula, mat_grid);
			if (mat_grid) {
				free_linear3(n_grid + 1, &mat_grid);
			}
            printf("Marching Squares aplicat cu succes ");
            printf("[%d-%d]\n", n_celula, m_celula);
		} else if (!strcmp(s, "INIT_CONTUR")) {
			for (int i = 0; i < 16; i++) {
				if (i < 8) {
					contur_1(i, cont);
				} else {
					contur_2(i, cont);
				}
				print_contur(cont);
			}
		} else if (!strcmp(s, "GRID")) {
			//initializam n_grid si m_celula cu valorile matricei mari
			n_grid = n_celula;
			m_grid = m_celula;
			mat_grid = grid(&n_grid, &m_grid, mat_celula);
			printf("Grid calculat cu succes [%d-%d]\n", n_grid, m_grid);
			print_grid(n_grid, m_grid, mat_grid);
		} else if (!strcmp(s, "RESIZE")) {
			resize(&n_celula, &m_celula, &mat_celula);
		}
		scanf("%s", s);
	}
	if (strncmp(s, "EXIT", 4) == 0) {
		printf("Gigel a terminat\n");
	}
	if (mat_grid) {
		free_linear3(n_grid + 1, &mat_grid);
	}
	if (mat_celula) {
		free_linear(n_celula, &mat_celula);
	}
	//eliberam memoria
	return 0;
}
