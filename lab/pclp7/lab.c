#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NMAX 100

int is_polidrome(char s[])
{
	int n = strlen(s) - 1;
	for (int i = 0; i < n / 2; i++) {
		if(tolower(s[i]) != tolower(s[n - i - 1])) {
			// printf("%c %c \n", s[i], s[n - i - 1]);
			return 0;
		}
	}
	return 1;
}

void sort_strings(int n, char **v)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(v[i], v[j]) > 0) {
				char *s;
				s = (char*) malloc(NMAX);
				s = v[i];
				v[i] = v[j];
				v[j] = s;
			}
		}
	}
}

int count_occurences(char *s, char *words)
{
	int nr = 0;
	char *p;
	p = strstr(s, words);
	while (p) {
		nr++;
		p = strstr(p + 1, words);
	}
	return nr;
}

int main(void)
{
	
	// 1
	// char s[NMAX];
	// fgets(s, NMAX, stdin);
	// int lg = strlen(s);
	// // printf("%d\n", lg);
	// for (int i = 0; i < strlen(s); i++) {
	// 	if(s[i] == ' ') {
	// 		char aux[NMAX];
	// 		strcpy(aux, s + i + 1);
	// 		// fputs(aux, stdout);
	// 		strcpy(s + i, aux);
	// 		// s[strlen(s) - 2] = '\n';
	// 	}
	// }
	// // fputs(s, stdout);
	// if (is_polidrome(s)) {
	// 	printf("is palindorme\n");
	// } else {
	// 	printf("is not \n");
	// }

	//2
	// char **p;
	// int n;
	// scanf("%d", &n);
	// p = (char**) malloc(n * sizeof(char *));
	// for (int i = 0 ; i < n; i++) {
	// 	p[i] = malloc(NMAX);
	// }
	// for (int i = 0; i < n; i++) {
	// 	scanf("%s", p[i]);
	// }
	// sort_strings(n, p);
	// for (int i = 0; i < n; i++) {
	// 	printf("%s\n", p[i]);
	// }

	//3
	// char *s;
	// s = malloc(NMAX);
	// fgets(s, NMAX, stdin);
	// char *p;
	// int nr = 0;
	// p = strtok(s, " \t\n.;,?!");
	// while (p) {
	// 	// printf("%s\n", p);
	// 	int ok = 1;
	// 	for (int i = 0; i < strlen(p) && ok; i++) {
	// 		if(!isalpha(p[i])) {
	// 			ok = 0;
	// 		}
	// 	}
	// 	if (ok) {
	// 		nr++;
	// 	}
	// 	p = strtok(NULL, " \t\n.;,?!");
	// }
	// printf("#words = %d\n", nr);

	//4
	char *s, *word;
	s = malloc(NMAX);
	word = malloc(NMAX);
	fgets(s, NMAX, stdin);
	scanf("%s", word);
	// fputs(s, stdout);
	// printf("%s\n", word);
	printf("%d\n", count_occurences(s, word));
}