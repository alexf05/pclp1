#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char *nume;
    double medie;
}studenti_t;

void copiere_stud(studenti_t *b, studenti_t *a)
{
    b->medie = a->medie;
    strcpy(b->nume, a->nume);
}

int main(void)
{
    // int n;
    // studenti_t a[100];
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     a[i].nume = malloc(30);
    //     scanf("%s", a[i].nume);
    //     scanf("%lf", &a[i].medie);
    // }
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (strcmp(a[i].nume, a[j].nume) > 0) {
    //             studenti_t aux;
    //             aux.nume = malloc(30);
    //             aux.medie = a[i].medie;
    //             strcpy(aux.nume, a[i].nume);
    //             a[i].medie = a[j].medie;
    //             strcpy(a[i].nume, a[j].nume);
    //             a[j].medie = aux.medie;
    //             strcpy(a[j].nume, aux.nume);
    //             free(aux.nume);
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     printf("%s\t", a[i].nume);
    //     printf("%lf\n", a[i].medie);
    //     free(a[i].nume);
    // }
    studenti_t std1, std2;
    std1.nume = malloc(30);
    std2.nume = malloc(30);
    scanf("%s", std1.nume);
    scanf("%lf", &std1.medie);
    // scanf("%s", std2.nume);
    // scanf("%lf", &std2.medie);

    copiere_stud(&std2, &std1);

    strcpy(std2.nume, "maria");

    printf("%s\t", std1.nume);
    printf("%lf\n", std1.medie);
    printf("%s\t", std2.nume);
    printf("%lf\n", std2.medie);
    free(std1.nume);
    free(std2.nume);
}