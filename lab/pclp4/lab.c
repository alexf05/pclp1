#include<stdio.h>
#define NMAX 100

int read_array(int v[]){
    int n;
    scanf( "%d", &n);
    for( int i = 0; i < n; i ++)
        scanf( "%d", &v[i]);
    return n;
}

void print_array(int n, int v[]){
    for(int i = 0; i < n; i ++)
        printf( "%d ", v[i]);
    printf( "\n");
}

int sum_array( int n, int v[]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    return sum;
}

int min_array( int n, int v[]){
    int min = v[0];
    for(int i = 1; i < n; i++){
        if( v[i]< min) min = v[i];
    }
    return min;
}

int pos_max( int n, int v[]){
    int pos = 0, max = v[0];
    for( int i = 1; i < n; i++){
        if( v[i] > max){
            max = v[i];
            pos = i;
        }
    }
    return pos;
}

float avg_array( int n, int v[]){
    float sum = 1.0 * sum_array( n, v);
    float avg = sum / n;
    return avg;
}

int find_array( int n, int v[], int x){
    for( int i = 0; i < n; i++){
        if( v[i] == x) return i;
    }
    return -1;
}

void sort_array( int n, int v[]){
    for( int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (v[i] > v[j]){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

void multiply_matrix( int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]){
    for( int i = 0; i < n; i++){
        for( int j = 0; j < p; j++){
            int sum = 0;
            for(int k = 0; k < m; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

void cop_matrix(int n, int m, int a[][NMAX], int b[][NMAX]){
    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            b[i][j] = a[i][j];
        }
    }
}


void read_matrix( int n, int m, int a[][NMAX]){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void print_matrix(int n, int m, int a[][NMAX]){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", a[i][j] );
        }
        printf("\n");
    }
}
void power_matrix(int n, int a[][NMAX], int k, int b[][NMAX]){
    cop_matrix(n,n,a,b);
    for(int i = 2; i <= k; i++){
        int c[NMAX][NMAX] = {0};
        multiply_matrix(n,n,n,a,b,c);
        cop_matrix(n,n,c,b);
    }
}

int main(void){
    int a[NMAX][NMAX], b[NMAX][NMAX];
    int n;
    scanf(" %d", &n);
    read_matrix(n,n,a);
    // cop_matrix(n,n,a,b);
    // multiply_matrix(n,n,n,a,b,c);
    // print_matrix(n,n,c);
    power_matrix(n,a,10,b);
    print_matrix(n,n,b);
    return 0;
}