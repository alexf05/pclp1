#include <stdio.h>
#define NMAX 1001

void nod1(int n, int pos, double *in, double *ou, double cir[][NMAX], int *k)
{
	//vedem daca circuitul este deschis in nodul pos <=>
	//nu avem nicio intrare/ iesire din nods
	//input- output pentru prima lege
	int ok1 = 0, ok2 = 0;
	//daca intensitatea este negative pe n1 -> n2
	//o marchez ca si cum ar fi de pe n2 -> n1
	double input = 0, output = 0;
	for (int i = 1; i <= n; i++) {
		if (cir[pos][i]) {
			output += cir[pos][i];
		}
		if (cir[i][pos]) {
			input += cir[i][pos];
		}
		if (cir[pos][i] > 0 || cir[i][pos] < 0) {
			ok1 = 1;
		}
		if (cir[pos][i] < 0 || cir[i][pos] > 0) {
			ok2 = 1;
		}
		// printf("%lf\n", output);
	}
	*in = input;
	*ou = output;
	*k = ok1 && ok2;
}

void read1(int *a, int *b, double cir[][NMAX])
{
	int n, m;

	scanf("%d%d", &n, &m);
	*a = n;
	*b = m;

	for (int i = 0; i < m; i++) {
		int ni, nf;//nod initial, nod final
		double c;//curent

		scanf("%d%d%lf", &ni, &nf, &c);
		cir[ni][nf] += c;
	}

}

void ver1(int n, double cir[][NMAX])
{
	int ok = 1;
	//verificare circuitul este deschis
	for (int i = 1; i <= n && ok; i++) {
		double input, output;
		int k;
		nod1(n, i, &input, &output, cir, &k);
		if (k == 0) {
			printf("Circuitul este deschis in nodul %d.", i);
			ok = 0;
		}
	}

	//verificare daca internsitatea de input == output
	for (int i = 1; i <= n && ok; i++) {
		double input, output;
		int k;
		nod1(n, i, &input, &output, cir, &k);
		double dif = input - output;
		if (dif < 0) {
			dif = -dif;
		}
		if (dif > 0.00000001) {
			// lucram cu varibile foarte precise,
			//dar raspunsul nostru este acceptabil un delta < 10^8
			printf("Legea 1 a lui Kirchhoff nu se respecta pentru egalitatea ");
			printf("%.9fA = %.9fA in nodul %d.", input, output, i);
			ok = 0;
		}
	}

	if (ok) {
		printf("Legea 1 a lui Kirchhoff se respecta pentru circuitul dat.");
	}

}

void read2(double *t_in, double *t_out, int *k)
{
	int n, m;
	double vin = 0;
	double vout = 0;
	int ok = 1;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int ni, nf;//nod initial, nod final
		double c;//curent

		scanf("%d%d%lf", &ni, &nf, &c);

		int nrcomp;

		scanf("%d", &nrcomp);

		for (int i = 0; i < nrcomp && ok; i++) {
			char comp;
			double valoare;

			scanf("%c", &comp);
			scanf("%c%lf", &comp, &valoare);

			if (comp == 'R') {
				vout += valoare * c;
			} else if (comp == 'E') {
				if (valoare < 0) {
					printf("Sursa de tensiune nu poate fi negativa.");
					ok = 0;
				}
				vin += valoare;
			} else {
				printf("Componenta dorita nu exista.\n");
			}

			// printf("%c %lf\n ", comp, valoare);
		}
	}

	*t_in = vin;
	*t_out = vout;
	*k = ok;
	// ver2(n, cir);

}

int main(void)
{
	char c[3];

	scanf("%s", c);
	if (!c[1]) {
		double cir[NMAX][NMAX] = {0};
		//matricea grafului orientat asociata circuitului
		//inseamna ca pozitia 1 este libera
		int n, m;
		read1(&n, &m, cir);
		ver1(n, cir);
		double in, ou;
		int k;
		nod1(n, 1, &in, &ou, cir, &k);
		// printf("\n");
		// for(int i = 1; i < n; i++)
		// if(cir[1][i])printf("%lf ", cir[1][i]);

	} else if (!c[2]) {
		//inseamna ca pe poz a doua nu mai am caractere, deci am doar pe I si 2
		double vin, vout;
		double dif;
		int ok;

		read2(&vin, &vout, &ok);

		dif = vin - vout;
		if (dif < 0) {
			dif = -dif;
		}
		if (!ok) {

		} else if (dif < 0.000001) {
			printf("Legea a 2-a lui Kirchhoff se respecta ");
			printf("pentru circuitul dat.");
		} else {
			printf("Legea a 2-a lui Kirchhoff nu se respecta pentru ");
			printf("egalitatea %.9lfV = %.9lfV.", vout, vin);
		}
	} else {
		printf("Legile existente sunt doar Legea 1 si Legea a 2-a");
	}
	return 0;

}
