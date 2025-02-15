#include <stdio.h>
#define NMAX 100

void read_array(int *n, int *v)
{
    int *p = n;

    scanf("%d", p);

    for(int i = 0; i < *n; i++){
        scanf( " %d", &v[i]);
    }
}

void print_array(int n, int *v)
{
    for( int i = 0; i < n; i++){
        printf( "%d ", v[i]);
    }
    printf("\n");
}

void swap_int (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_pointers(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

void my_memcpy(void *dst, const void *src, int num)
{
    for(int i = 0; i < num; i++){
        *(char*)(dst +i)  = *(char*)(src + i);
    }
}

int main(void)
{
    /* int *a = 0x00;
    // int *b = a;
    // ++a;
    // printf("%d\n", *a);

    // int n;
    // int v[100];
    // scanf("%d", &n);
    // for(int i = 0; i < n; i++){
    //     scanf("%d", &v[i]);
    // }
    // for(int i = 0; i < n; i++){
    //     printf("%d %p\n",v[i], &v[i]);
    // }

    // double a[NMAX][NMAX];
    // int n = 4, m = 5;
    // double *p;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < m; j++){
    //         a[i][j] = i * n + j;
    //     }
    // }

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < m; j++){
    //         printf("%f ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
     
    // p = *(a + 2) + 3;

    // *p = 100;

    // printf("%p %p\n", p, &a[2][3]);
    // printf("%f %f\n", *p , a[2][3]); 

    // int n, v[NMAX];

    // read_array( &n, v);
    // print_array( n, v);

    int a = 5, b = 6;
    int *p1 = &a, *p2 = &b;
    printf( "%p %p\n", p1, p2);
    swap_pointers( &p1, &p2);
    printf( "%p %p\n", p1, p2);
    // printf("%d %d\n", a, b); */

    char a = '1', b;
    my_memcpy( &b, &a, sizeof(char) );
    printf("%c\n", b);

    unsigned int x = 2;
    printf("%u\n", x);


    return 0;
}