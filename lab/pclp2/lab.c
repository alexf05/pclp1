#include<stdio.h>
int main () {
    /*verificare paritate
    int n;
    scanf ( "%d", &n);
    if( n % 2 == 0) printf( "par");
        else printf( "impar");
    printf("\n");
    if ( n&1) printf("impar");
        else printf("par");*/
    /*verificare triunghi
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    if ( (a+b) > c && (a + c) > b && (b + c) > a) printf( "DA");
        else printf( "NU");
    printf("\n");*/
    /*size of 
    printf("%lu\n", sizeof(long int) );
    int x;
    printf("%lu\n", sizeof( x));*/
    /*afisare stelute
    int n;
    scanf ( "%d", &n);
    for ( int i =0; i < n; i ++){
        for ( int j = 0; j < n-i; j ++) printf( "*");
        printf("\n");
    }*/
    /*factorial
    int n, p=1;
    scanf( "%d", &n);
    for( int i = 1; i <= n; i ++){
        p *= i;
    }
    printf( "%d\n", p);*/
    /*palindorm
    int n, in = 0, cn;
    scanf( "%d", &n);
    cn = n;
    while ( n){
        int p = n % 10;
        in = in * 10 + p;
        n /= 10;
    }
    // printf( "%d\n", in);
    if( cn == in) printf( "palindrom");
        else printf( "nu e palindrom");
    printf( "\n");*/
    /*divizori si nr prime
    int x, nr = 0;
    scanf( "%d", &x);
    while( x > 0){
        int p = 1;
        for( int i = 2; i <= x/2; i ++){
            if( x % i == 0){
                p = 0;
                printf( "%d ", i);
            }
        }
        if( p == 1){
            nr ++;
            printf( "PRIM");
        } 
        printf( "\n");
        scanf("%d", &x);
    }
    printf( "nr de nr prime este %d \n", nr);*/
    /* extra #1
    int n, m = 0, r = 1, p = 1;
    scanf( "%d", &n);
    while ( n){
        int c = n % 10;
        if( r % 2 == 0){
            m = p * c +m;
            p *= 10;
        } 
        r ++;
        n /= 10;
    }
    printf( "%d\n", m);*/
    /* cmmmdd - euclid
    int a, b;
    scanf( " %d %d", &a, &b);
    while( a != b){
        if( a > b) a -= b;
        else b -= a;
    }
    printf( "%d\n", a);*/
    /*cmmdc ul a n numere
    int n, x,y ;
    scanf( " %d", &n);
    scanf( "%d", &x);
    for( int i = 1; i < n; i++){
        scanf( "%d", &y);
        int r = 0;
        while( y != 0){
            r = x % y;
            x = y;
            y = r;
        }
    }
    printf( "cmmdc-ul numerelor citite este %d \n", x);*/
    /*x1^3+x2^3+x3^3=0
    for( int i = -50; i <= 50; i++){
        for( int j = -50; j <=50; j++){
            for( int k = -50; k <=50; k++)
                if( i*i*i + j*j*j + k*k*k == 0) 
                    printf( "o solutie a ecuatiei este: %d %d %d \n", i, j, k); 
        }
    }
    printf( "\n");*/
    return 0;
}