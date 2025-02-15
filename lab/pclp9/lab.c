#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nr(FILE *in)
{
    int nr = 0;
    int x;
    while (!feof(in)) {
        fscanf(in, "%d", &x);
        nr++;
    }
    return nr;
}

int *vec(FILE *in, int n)
{
    fseek(in, 0, 0);
    int *v = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &v[i]);
    }
    return v;
}

void print_file(FILE *out, int n, int *v)
{
    fprintf(out, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d ", v[i]);
    }
    fprintf(out, "\n");
}

int nr_b(FILE *in)
{
    int nr = 0;
    int x;
    while (fread(&x, sizeof(int), 1, in)) {
        nr++;
    }
    return nr;
}

int *vec_b(FILE *in, int n)
{
    fseek(in, 0, 0);
    int *v = calloc(n, sizeof(int));
    fread(v, sizeof(int), n, in);
    return v;
}

void print_file_b(FILE *out, int *n, int *v)
{
    fwrite(n, sizeof(int), 1, out);
    fwrite(v, sizeof(int), *n, out);
}

int main(void)
{
    // FILE *in = fopen("input.txt", "rt");
    // FILE *out = fopen("output.txt", "wt");
    // char s[31];
    // int v;
    // scanf("%s%d", s, &v);
    // fprintf(out, "%s %d", s, v);
    // fclose(out);

    // FILE *out = fopen("output.txt", "wb");
    // char s[31] = {0};
    // int v;
    // scanf("%s%d", s, &v);
    // fwrite(s, sizeof(char), strlen(s) + 1, out);
    // fwrite(&v, sizeof(int), 1, out);
    // fclose(out);

    // int n, v[100];
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &v[i]);
    // }
    // FILE *out = fopen("output.txt", "wt");
    // for (int i = 0; i < n; i++) {
    //     fprintf(out, "%d ", v[i]);
    // }
    // fclose(out);
    
    // int n1, v1[100];
    // scanf("%d", &n1);
    // for (int i = 0; i < n1; i++) {
    //     scanf("%d", &v1[i]);
    // }
    // FILE *out1 = fopen("input_3", "wb");
    // fwrite(v1, sizeof(int), n1, out1);
    // fclose(out1);

    /*FILE *in = fopen("input.txt", "rt");
    FILE *out = fopen("output.txt", "wt");

    int n = nr(in);
    int *v = vec(in, n);
    print_file(out, n, v);

    free(v);
    fclose(in);
    fclose(out);*/

    /*FILE *in = fopen("input_3", "rb");
    FILE *out = fopen("output", "w");

    int n = nr_b(in);
    int *v = vec_b(in, n);
    print_file(out, n, v);

    free(v);
    fclose(in);
    fclose(out);*/

    char s[1001];
    scanf("%s", s);
    FILE *in = fopen(s, "rb");
    if(!in) {
        printf("Nu exista fisierul!\n");
        return 0;
    }
    fseek(in, 0, 2);
    
    long long size = ftell(in);

    fclose(in);

    printf("%lld\n", size);

    return 0;
}