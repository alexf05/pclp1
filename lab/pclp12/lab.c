#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
typedef double (*fp)(double);

int gcd(int first, ...)
{
    if (first < 0) {
        printf("No numbers present (besides terminator)\n");
        return -1;
    }

    va_list args;
    va_start(args, first);
    int current = first;
    int a = current;
    current = va_arg(args, int);
    if (current < 0) {
        printf("nu ai 2 argumente \n");
        return -1;
    }
    while (current >= 0)
    {
        int b = current;
        int d = 0;
        while (b != 0) {
            d = a % b;
            a = b;
            b = d;
        }
        current = va_arg(args, int);
    }
    return a;
}

void listf(fp a[], double min, double max, double pas)
{
    double x,y;
    for (int i = 0; a[i]; i++) {
        for (x = min; x <= max; x = x + pas) {
            y=a[i](x); // apel functie de la adresa din "fp"
            printf("\n%20.10lf %20.10lf", x, y);
        }
        printf("\n");
    }
}

typedef int (*cmp_t)(const void*, const void*);

void swap(void *a, void *b, size_t size)
{
    void *tmp = malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}

void sort(void* v, size_t n, size_t size, cmp_t cmp)
{
    char *t = v;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if((*cmp)(t + i * size,t + j * size) > 0) {
                swap(t + i * size,t + j * size, size);
            }
        }
    }
}

int cmp_int(const void *a,const void *b)
{
    int m = *(int *)a;
    int n = *(int *)b;
    return m - n;
}

int cmp_char(const void *a, const void *b)
{
    char *m = (char *)a;
    char *n = (char *)b;
    return (strcmp(m,n));
}

void bprintf(FILE *out, char *format, ...)
{
    if (!format) {
        printf("esti prost");
        return;
    }
    va_list args;
    va_start(args, format);
    for (int i = 0 ; i < strlen(format); i++) {
        if (format[i] == '%') {
            switch (format[i + 1])
            {
            case 'c':
                char c = va_arg(args, char);
                fwrite(&c, sizeof(char), 1, out);
                break;
            case 'd':
                int d = va_arg(args, int);
                fwrite(&d, sizeof(int), 1, out);
                break;
            case 's':
                char *s = va_arg(args, char*);
                fwrite(s, sizeof(char), strlen(s) + 1, out);
                break;
            default:
                break;
            }
            i++;
        } else {
            fwrite(&format[i], sizeof(char), 1, out);
        }
    }
}

int main(void)
{
    // printf("%d\n", gcd(5, 10, -1));
    // printf("%d\n", gcd(5, 10, 2, 100, -1));
    // printf("%d\n", gcd(500, 10, 25, 75, -1));
    // printf("%d\n", gcd(1024, 48, 64, 256, 2048, -1));
    // int v[] = {0 , 5, -1, 2, 4, 5, 10};
    // int n = sizeof(v)/ sizeof(v[0]);
    sort(v, n, sizeof(int), cmp_int);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", v[i]);
    // }
    // printf("\n");

    FILE *out = fopen("gigle1.out", "wb");
    bprintf(out, "%d%c", 4, 'a');
    return 0;
}