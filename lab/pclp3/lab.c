#include <stdio.h>

/*pow
int power1( int n, int k){
    int p = 1;
    for( int i = 1; i <= k; i ++){
        p *= n;
    }
    return p;
}

int power2( int n, int k){
    return k ? n * power2( n, k-1) : 1;
}*/

int power3( int n, int k){
    if( k == 0) return 1;
    int x = power3( n, k/2);
    if( k %2 ==1) return n * x * x;
    return x * x;
}

int count_digits( int n){
    return (n <= 9 ) ? 1 : 1+ count_digits( n/10);
}

/*reverse number
int reverse_number( int r, int n){
    if( r== 0) return reverse_number( n%10, n/10);
    return n ? reverse_number( r *10 + n%10 , n/10) : r;
}*/

int reverse_number2( int r, int n){
    // printf("%d %d\n", r, n);
    return n ? reverse_number2( r+ (n%10) * power3( 10, count_digits( n)-1 ) , n/10) : r;
}

int is_palindrome( int n){
    return n == reverse_number2(0, n);
}

int next_palindrome( int n){
    for( int i = n; i <= 2147483647; i ++){
        if ( is_palindrome(i ))return i;
    }
}

int is_prime( int n){
    if( n <= 1) return 0;
    if( n==2) return 1;
    for( long i = 2; i*i <= n; i += 2){
        if(n % i == 0) return 0;
        // printf("%d\n", i);
    }
    return 1;
}


int main( void){
    /*pow
    int n, k;
    scanf( "%d%d", &n, &k);
    printf( "%d \n", power1( n, k) );
    printf( "%d \n", power2( n, k) );*/
    /*nr de cifre
    int n;
    scanf( "%d", &n);
    printf( "%d \n", count_digits( n) );*/

    int n;
    scanf( "%d", &n);
    printf( "%d\n", is_prime(n) );
    return 0;
}