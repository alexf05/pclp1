#include <stdio.h>
#include <string.h>
#define SET_SIZE 4
typedef unsigned char SET[SET_SIZE];

int is_even(int n)
{
    int mask = (1 << 0);
    return !(n & mask);
}

int pow2(int n)
{
    return (1 << n);
}

int flip_bits(unsigned int n)
{
    return (~n);
}

void print_bits(int n)
{
    int mask;
    for(int i = 31; i >= 0; i--) {
        mask = (1 << i);
        printf("%d", (n & mask) ? 1 : 0);
    }
    printf("\n");
}

int is_power2(int n)
{
    return !((n - 1) & n);
    // int nr = 0;
    // while(n){
    //     if(n & 1) {
    //         nr ++;
    //     }
    //     n >>= 1;
    // }
    // return (nr == 1);
}

void insert_in_set(SET s, unsigned int n)
{
    int k = n / 8, r = n % 8;
    int mask = 1 << r;
    s[k] = (s[k] | mask);
}

void delete_from_set(SET s, unsigned int n)
{
    int k = n / 8, r = n % 8;
    int mask = ~(1 << r);
    s[k] = (s[k] & mask);
}

void print_bits_char(unsigned char c)
{
    int mask;
    for(int i = 7; i >= 0; i--) {
        mask = (1 << i);
        printf("%d", (c & mask) ? 1 : 0);
    }
}

void print_s(SET s)
{
    for(int i = SET_SIZE - 1; i >= 0; i--) {
        print_bits_char(s[i]);
    }
    printf("\n");
}

int is_in_set(SET s, unsigned int n)
{
    int k = n / 8, r = n % 8;
    int mask = 1 << r;
    return (s[k] & mask) ? 1 : 0;
}

void delete_all_from_set(SET s)
{
    memset(s, 0, SET_SIZE);
}

int card_set(SET s)
{
    int mask, nr = 0;
    for(int i = 0; i < SET_SIZE; i++) {
        for(int j = 0; j < 8; j++){
            mask = 1 << j;
            if(mask & s[i]){
                nr++;
            }
        }
    }
    return nr;
}

int is_empty_set(SET s)
{
    return card_set(s) ? 1 : 0;
}

int read_set(SET s)
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert_in_set(s, x);
    }
    return n;
}

void print_set(SET s)
{
    unsigned int max = (~0U);
    for(unsigned int i = 0; i < max; i++) {
        if( is_in_set(s, i)){
            // printf("%d ", i);
        }
    }
    printf("%u ", max);

}

int main(void)
{
    // int x;
    // scanf("%d", &x);
    // printf("%d\n", flip_bits(x));
    // // print_bits(x);
    SET s;
    delete_all_from_set(s);
    insert_in_set(s, 2);
    insert_in_set(s, 3);
    // delete_from_set(s, 2);
    // print_s(s);
    // printf("%d\n", is_empty_set(s));
    print_set(s);
    return 0;
}