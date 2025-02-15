#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(SORT_ASC) && !defined(SORT_DESC)
#error "Please define SORT_ASC or SORT_DESC"
#endif

typedef struct
{
    char s[50];
} lab;


#ifdef SORT_ASC
int compare(const void *a, const void *b)
{
    return (*(unsigned int*)a - *(unsigned int*)b);
}
#endif

#ifdef SORT_DESC
int compare(const void *a, const void *b)
{
    return (*(unsigned int*)b - *(unsigned int*)a);
}
#endif


#define SWAP(a, b) do { \
    char *tmp = malloc(sizeof(a)); \
    memcpy(tmp, &a, sizeof(a)); \
    memcpy(&a, &b, sizeof(b)); \
    memcpy(&b, tmp, sizeof(a)); \
    free(tmp); \
} while(0);


void swap_i(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void test(char **c, char *v[]) {
    printf("%c %c\n", c[0][0], v[0][0]);
}

int main (int argc, char *argv[])
{
    // if (strcmp(argv[0], "./gigel")) {
    //     return 1;
    // }
    // if(argc < 2) {
    //     fprintf(stderr, "Gigele, cel putin doua!\n");
    //     return 1;
    // }
    // for (int i = 1; i < argc; i++) {
    //     for (int j = 0; argv[i][j]; j++) {
    //         if (argv[i][j] <'0' || argv[i][j] > '9') {
    //             fprintf(stderr, "Gigele, da-mi numere naturale!\n");
    //             return 1;
    //         }
    //     }
    // }
    // unsigned int *v= malloc(sizeof(unsigned int) * (argc - 1));
    // for (int i = 0; i < argc - 1; i++) {
    //     v[i] = atoi(argv[i + 1]);
    // }
    // qsort(v, argc - 1, sizeof(unsigned int), compare);
    // for (int i = 0; i < argc - 1; i++) {
    //    printf("%d ", v[i]);
    // }
    // printf("\n");
    // int a = 2, b = 3;
    // SWAP(a, b);
    // printf("%d %d\n", a, b);
    // char c = 'c', d = 'f';
    // SWAP(c, d);
    // printf("%c %c\n", c, d);
    // char p[12][101];
    // scanf("%s", p[1]);
    // printf("%s\n", p[1]);
    // char **cuv = malloc(2 * sizeof(char *));
    // cuv[0]=malloc(25);
    // cuv[1]=malloc(25);
    // strcpy(cuv[0], "mama");
    // strcpy(cuv[1], "tata");
    // char c[15][15];
    // strcpy(c[0], "mama");
    // test(cuv, cuv);
    // test(c, c);
    char *a = malloc(2);
    a[0] = '0';
    a[1] = '1';
    a = realloc(a, 1);
    // for(int i = 0; i < 3; i++) {
        printf("%c\n", a[0]);
    // }
    return 0;
}