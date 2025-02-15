#include <stdio.h>
#define NMAX 1000

int check_opt1(int i, int j, int wid, int len, int m)
{
	//expresia din if trece de 80 de coloane
	if (i >= 2 * wid + len && i < 2 * wid + 2 * len && j >= m - wid) {
		return 1;
	}
	return 0;
}

int check_opt2(int i, int wid, int len, int j)
{
	//expresia din if trece de 80 de coloane
	if (i >= 2 * wid + len && i < 2 * wid + 2 * len && j < wid) {
		return 1;
	}
	return 0;
}

int check_opt3(int i, int j, int m, int wid, int len)
{
	//expresia din if trece de 80 de coloane
	if (i >= wid + len && i < 2 * wid + len && j >= wid && j < m - wid) {
		return 1;
	}
	return 0;
}

void matrice(int n, int m, int len, char numar[][NMAX])
{
	int wid = len / 3;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i >= 0 && i < wid && j >= wid && j < m - wid) {
				numar[i][j] = 'a';
			} else if (i >= wid && i < wid + len && j >= m - wid) {
				numar[i][j] = 'b';
			} else if (check_opt1(i, j, wid, len, m)) {
				numar[i][j] = 'c';
			} else if (i >= 2 * wid + 2 * len && j >= wid && j < m - wid) {
				numar[i][j] = 'd';
			} else if (check_opt2(i, wid, len, j)) {
				numar[i][j] = 'e';
			} else if (i >= wid && i < wid + len && j < wid) {
				numar[i][j] = 'f';
			} else if (check_opt3(i, j, m, wid, len)) {
				numar[i][j] = 'g';
			} else {
				numar[i][j] = '0';
			}
		}
	}
}

void printf_mat(int n, int m, char numar[][NMAX])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", numar[i][j]);
		}
		printf("\n");
	}
}

int seg_digit(int digit, char celula)
{
	int ok = 0;
	if (digit == 0) {
		if (celula == 'a' || celula == 'b' || celula == 'c' ||
			celula == 'd' || celula == 'e' || celula == 'f') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 1) {
		if (celula == 'b' || celula == 'c') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 2) {
		if (celula == 'a' || celula == 'b' || celula == 'd' ||
			celula == 'e' || celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 3) {
		if (celula == 'a' || celula == 'b' || celula == 'c' ||
			celula == 'd' || celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 4) {
		if (celula == 'b' || celula == 'c' || celula == 'f' ||
			celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 5) {
		if (celula == 'a' || celula == 'c' || celula == 'd' ||
			celula == 'f' || celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 6) {
		if (celula == 'a' || celula == 'c' || celula == 'd' ||
			celula == 'e' || celula == 'f' || celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 7) {
		if (celula == 'a' || celula == 'b' || celula == 'c') {
			ok = 1;
			} else {
				ok = 0;
			}
	} else if (digit == 8) {
		if (celula == 'a' || celula == 'b' || celula == 'c' ||
			celula == 'd' || celula == 'e' || celula == 'f' ||
			celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	} else if (digit == 9) {
		if (celula == 'a' || celula == 'b' || celula == 'c' ||
			celula == 'd' || celula == 'f' || celula == 'g') {
			ok = 1;
		} else {
			ok = 0;
		}
	}
	return ok;
}

void digit_mat(int digit, int n, int m, char numar[][NMAX])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char celula = numar[i][j];
			if (seg_digit(digit, celula)) {
				numar[i][j] = '^';
			} else {
				numar[i][j] = ' ';
			}
		}
	}
}

void transl_jos(int n, int m, char numar[][NMAX], int val_transl)
{
	for (int j = 0; j < m; j++) {
		char tmp[NMAX];
		for (int i = n - val_transl; i < n; i++) {
			tmp[i] = numar[i][j];
		}
		for (int i = n - 1; i >= val_transl; i--) {
			numar[i][j] = numar[i - val_transl][j];
		}
		for (int i = 0; i < val_transl; i++) {
			numar[i][j] = tmp[i + n - val_transl];
			//i - n + val_transl ~= numerotarea de la 0
		}
	}
}

void transl_sus(int n, int m, char numar[][NMAX], int val_transl)
{
	for (int j = 0; j < m; j++) {
		char tmp[NMAX];
		for (int i = 0; i < val_transl; i++) {
			tmp[i] = numar[i][j];
		}
		for (int i = 0; i < n - val_transl; i++) {
			numar[i][j] = numar[i + val_transl][j];
		}
		for (int i = n - val_transl; i < n; i++) {
			numar[i][j] = tmp[i - n + val_transl];
			//i - n + val_transl ~= numerotarea de la 0
		}
	}
}

void transl_stanga(int n, int m, char numar[][NMAX], int val_transl)
{
	for (int i = 0; i < n; i++) {
		char tmp[NMAX];
		for (int j = 0; j < val_transl; j++) {
			tmp[j] = numar[i][j];
		}
		for (int j = 0; j < n - val_transl; j++) {
			numar[i][j] = numar[i][j + val_transl];
		}
		for (int j = m - val_transl; j < m; j++) {
			numar[i][j] = tmp[j - m + val_transl];
			//i - n + val_transl ~= numerotarea de la 0
		}
	}
}

void transl_dreapta(int n, int m, char numar[][NMAX], int val_transl)
{
	for (int i = 0; i < n; i++) {
		char tmp[NMAX];
		for (int j = m - val_transl; j < m; j++) {
			tmp[j] = numar[i][j];
		}
		for (int j = m - 1; j >= val_transl; j--) {
			numar[i][j] = numar[i][j - val_transl];
		}
		for (int j = 0; j < val_transl; j++) {
			numar[i][j] = tmp[j + m - val_transl];
			//i - n + val_transl ~= numerotarea de la 0
		}
	}
}

void read(int *in_dim_linie, int *in_dim_col, int *marine, char numar[][NMAX])
{
	int n, m, len;
	char cer;
	long long val_transl;

	scanf("%d%d%d", &n, &m, &len);
	scanf("%c", &cer);//citeste new line
	scanf("%c", &cer);

	while (cer != 'Q') {
		int ok = 1;
		if (cer == 'F') {
			int digit;
			scanf("%d", &digit);

			if (digit < 0 || digit > 9) {
				printf("The input given is not a digit.\n");
				// ok = 0;
			} else {
				matrice(n, m, len, numar);
				digit_mat(digit, n, m, numar);
				// ok = 1;
			}

		} else if (cer == 'P') {
			printf_mat(n, m, numar);
			printf("\n");
		} else if (cer == 'W') {
			scanf("%lld", &val_transl);

			val_transl = val_transl % n;
			//daca translatam matricea de mai mult de nr de linii
			//o translatam de fapt de modulul la nr de linii

			transl_sus(n, m, numar, val_transl);
		} else if (cer == 'D') {

			scanf("%lld", &val_transl);

			val_transl = val_transl % m;
			//daca translatam matricea de mai mult de nr de coloane
			//o translatam de fapt de modulul la nr de coloane

			transl_dreapta(n, m, numar, val_transl);
		} else if (cer == 'S') {
			scanf("%lld", &val_transl);

			val_transl = val_transl % n;
			//daca translatam matricea de mai mult de nr de linii
			//o translatam de fapt de modulul la nr de linii

			transl_jos(n, m, numar, val_transl);
		} else if (cer == 'A') {
			scanf("%lld", &val_transl);

			val_transl = val_transl % m;
			//daca translatam matricea de mai mult de nr de coloane
			//o translatam de fapt de modulul la nr de coloane
			transl_stanga(n, m, numar, val_transl);
		} else {
			char tmp;
			scanf("%c", &tmp);
			while (tmp != '\n') {
				scanf("%c", &tmp);
			}
			ok = 0;
			printf("Invalid command.\n");
		}
		if (ok) {
			scanf("%c", &cer);//citeste new line
		}
		scanf("%c", &cer);
	}

	*in_dim_linie = n;
	*in_dim_col = m;
	*marine = len;
}

int main(void)
{
	int n, m, len;
	char numar[NMAX][NMAX];

	read(&n, &m, &len, numar);
	// printf_mat(n, m, numar);
}
