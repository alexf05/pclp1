#include <stdio.h>

void write_p(int l, int u)
{
	if (u % 90) {//inseamna ca unghiul e 45
		int cont = 0;//prima linie are o *
		int n = 2 * l - 1;//nr de linii/coloane al pseudomatricei rezultate
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j >= (n / 2 - cont) && j <= (n / 2 + cont)) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			if (i < n / 2) {
				cont++;
			} else {
				cont--;
			}
			if (i != (n - 1)) {
				printf("\n");
			}
		}
	} else {//afisam un patrat normal
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				printf("*");
			}
			if (i != (l - 1)) {
				printf("\n");
			}
		}
	}
	// printf("\n");
}

void write_d(int l1, int l2)
{
	for (int i = 0; i < l2; i++) {
		for (int j = 0; j < l1; j++) {
			printf("*");
		}
		if (i != (l2 - 1)) {
			printf("\n");
			};
	}
	// printf("\n");
}

void write_c(int l, int u)
{
	if (u % 90) {
		//roteste 45 de grade->diagonalele unui patrat
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if (i == j || (i + j + 1) == l) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			if (i != (l - 1)) {
				printf("\n");
			}
		}
	} else {//cruce normala
		int mij = l / 2;
		for (int i = 0; i < l; i++) {
			if (i == mij) {
				for (int j = 0; j < l; j++) {
					printf("*");
				}
			} else {
				for (int j = 0; j < l; j++) {
					if (j == mij) {
						printf("*");
					} else {
						printf(" ");
					}
				}
			}
			if (i != (l - 1)) {
				printf("\n");
			}
		}
	}
	// printf("\n");
}

void write_t(int l, int u)
{
	switch (u) {
	case 0:{
		/* sub diagonala principala
		*
		**
		***
		*/
		for (int i = 0 ; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if (j <= i) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			if (i != (l - 1)) {
				printf("\n");
			}
		}
		break;
	}
	case 90:{
		/* deasupra diagonalei secundare
		***
		**
		*
		*/
		for (int i = 0 ; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if ((i + j) < l) {
					printf("*");
				} else {
					printf(" ");
				}}
			if (i != (l - 1)) {
				printf("\n");
			}
		}
		break;
	}
	case 180:{
		/* deasupra diagonalei principale
		***
		 **
		  *
		*/
		for (int i = 0 ; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if (i <= j) {
					printf("*");
				} else {
					printf(" ");
				}}
			if (i != (l - 1)) {
				printf("\n");
			}
		}
		break;
	}
	case 270:{
		/*sub diagonala secundara
		  *
		 **
		***
		*/
		for (int i = 0 ; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if ((i + j + 1) >= l) {
					printf("*");
				} else {
					printf(" ");
				}}
			if (i != (l - 1)) {
				printf("\n");
			}
		} break;
	}
	}
}

void write_f(int l)
{
	//chenarul unui patrat si
	//linia si coloana din mijloc
	int mij = l / 2;
	for (int i = 0; i < l; i++) {
		if (i == mij || i == 0 || i == l - 1) {
			for (int j = 0; j < l; j++) {
				printf("*");
			}
		} else {
			for (int j = 0; j < l; j++) {
				if (j == 0 || j == l - 1 || j == mij) {
					printf("*");
				} else {
					printf(" ");
				}
			}
		}
		if (i != (l - 1)) {
			printf("\n");
		}
	}
}

void read(void)
{
	char f;
	int l1, l2, u;
	scanf("%c", &f);
	scanf("%c", &f);
	switch (f) {
	case 'p':
		scanf("%d%d", &l1, &u);
		u = u % 360;//unghiul este periodic de perioada 360
		if (u < 0) {
			u = 360 + u;
		} //unghiul este periodic de perioada 360 si vrem sa lucram cu val poz
		if (l1 <= 0) {
			printf("Unsupported size to display shape");
			break;
		}
		if (u % 45) {
			printf("Unsupported angle to display shape");
			break;
		}
		write_p(l1, u);
		break;

	case 'd':
		scanf("%d%d", &l1, &l2);
		if (l1 <= 0 || l2 <= 0) {
			printf("Unsupported size to display shape");
			break;
		}
		write_d(l1, l2);
		break;

	case 't':
		scanf("%d%d", &l1, &u);
		u = u % 360;//unghiul este periodic de perioada 360
		if (u < 0) {
			u = 360 + u;
		} //unghiul este periodic de perioada 360 si vrem sa lucram cu val poz
		if (l1 <= 0) {
			printf("Unsupported size to display shape");
			break;
		}
		if (u % 90) {
			printf("Unsupported angle to display shape");
			break;
		}
		write_t(l1, u);
		break;

	case 'c':
		scanf("%d%d", &l1, &u);
		u = u % 360;//unghiul este periodic de perioada 360
		if (u < 0) {
			u = 360 + u;
		} //unghiul este periodic de perioada 360 si vrem sa lucram cu val poz
		if (l1 <= 0 || l1 % 2 == 0) {
			printf("Unsupported size to display shape");
			break;
		}
		if (u % 45) {
			printf("Unsupported angle to display shape");
			break;
		}
		write_c(l1, u);
		break;

	case 'f':
		scanf("%d", &l1);
		if (l1 <= 0 || l1 % 2 == 0) {
			printf("Unsupported size to display shape");
			break;
		}
		write_f(l1);
		break;

	default:
		break;

	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		read();//citire cerintinta pentru fiecare forma
		if (i != (n - 1)) {
			printf("\n\n");
		}
	}
}
