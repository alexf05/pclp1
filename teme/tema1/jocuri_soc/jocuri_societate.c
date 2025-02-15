#include <stdio.h>
#define NMAX 10000

void read_1(long *h, unsigned int *s, unsigned int *x)
{
	//*h este pointer catre variabila hp din main si va prealua valoarea
	//variabilei hp din funtie la final
	//*x pointer catre nr de shielduri
	long hp = 0;
	scanf("%ld", &hp);

	unsigned int n;//nr total de obiecte
	unsigned int sn = 0;//nr de shielduri
	scanf("%u", &n);
	// printf("%d", n);

	char tip;//tipul de obiect
	unsigned int val_ob;//valoarea obiectului

	scanf("%c", &tip); //citim new-line

	for (unsigned int i = 0; i < n; i++) {
		scanf("%c%u", &tip, &val_ob);

		if (tip == 'H') {
			hp += val_ob; //crestem direct hp perosnajului
		} else if (tip == 'S') {
			s[sn++] = val_ob; //retinem intr un vector valorile shieldurilor
		} else {
			printf("Invalid item type.\n");
		}

		scanf("%c", &tip); //citim new- line
	}
		*h = hp;
		*x = sn;
}

void sort_array(unsigned int n, unsigned int *v)
{
	for (unsigned int i = 0; i < n - 1; i++) {
		for (unsigned int j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				unsigned int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

void elim_array(unsigned int *v, unsigned int *sn, unsigned int pos)
{
	unsigned int n = *sn; //nr de elemente
	for (unsigned int i = pos; i < n - 1; i++) {
		v[i] = v[i + 1];
	}
	n--;
	*sn = n;
}

unsigned int sh(long bs, unsigned int *s, unsigned int *n)
{
//imi returneaza shieldul corespunzator si il sterge din vector
	unsigned int sn = *n;

	if (sn == 0) {
		return 0; //daca vectorul cu shileduri nu are elemente returnam 0
	}
	if (s[0] > bs) {
		unsigned int x = s[0];//retinem elementul pe care il eliminam
		elim_array(s, &sn, 0);
		*n = sn;//actualizam dimensiunea vectorului
		return x; // daca primul element e mai mare decat bs, il returnam
	}

	//facem cautare binara
	unsigned int st = 0, dr = sn - 1;
	while (st <= dr) {
		unsigned int mij = (st + dr) / 2;

		if (s[mij] == bs) {
			unsigned int x = s[mij];
			elim_array(s, &sn, mij);
			*n = sn;//actualizam dimensiunea vectorului
			return x;
		}

		if (s[mij] > bs) {
			dr =  mij - 1;
		} else {
			st = mij + 1;
		}
	}

	unsigned int x = s[dr];
	elim_array(s, &sn, dr);
	*n = sn; //actualizam dimensiunea vectorului
	return x;
}

void boss_fight(unsigned int bs, long *h, unsigned int *s,
				unsigned int *n, unsigned int *scut)
{
	//simulam o batalie
	long hp = *h;
	unsigned int sn = *n;

	unsigned int shield = sh(bs, s, &sn);
	unsigned int damage;

	if (bs > shield) {
		damage = bs - shield;
	} else {
		damage = 0;
	}
	//daca avem scut mai mare decat damage ul
	//valoarea variabilei va fi posiziva si o resetam cu 0, pentru ca nu putem
	// acumula hp, doar nu vom pierde

	hp -= damage;
	// printf("%u %u %u\n\n", bs, shield, damage);

	*scut = shield;
	*h = hp;
	*n = sn;
}

void read_2(long *h, unsigned int *n, unsigned int *s)
{
	long hp = *h;
	unsigned int sn = *n;

	long m; //nr de inamici
	scanf("%ld", &m);
	for (unsigned int i = 0; i < m; i++) {
		unsigned int bs; //valoarea unui boss fight
		unsigned int shield;
		scanf("%u", &bs);
		boss_fight(bs, &hp, s, &sn, &shield);
		if (hp < 0) {
			hp  = 0;
		}
		printf("%ld ", hp);
		//Health points after boss %d:    (Used Shield: %d)\n
		if (shield > 0) {
			printf("%u\n", shield);
		} else {
			printf("\n");
		}
		if (hp == 0) {
			break;
		}
	}

	*h = hp;
}

int main(void)
{
	long hp;
	unsigned int s[NMAX], sn;

	read_1(&hp, s, &sn);
	printf("Initial health points: %ld\n", hp);

	sort_array(sn, s);
	//sortam vectori cu shielduri crecator pentru a
	//gasi elementele corespunzatoare mai usor

	read_2(&hp, &sn, s);

	if (hp > 0) {
		printf("Foe Vanquished!\n");
	} else {
		printf("You died.\n");
	}
}
