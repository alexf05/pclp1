#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    int n;
    char c1, c;
    char a1;
    scanf("%d", &n);
    scanf("%c", &c);//citim new-line
    scanf("%c", &c1);//citim primul caracter
    int lg = 1, lgmax = 1, i = 0, imax = 0;
    //i ->inceputul secventei
    //imax -> cea mai buna swcventa
    for (int k = 1; k < n; k++) {
        scanf("%c", a1);
        if (a1 == c1) {
            //inseamna ca vom continua secventa
            lg ++;
        } else {
            //secventa se termina
            if (lg > lgmax) {
                lgmax = lg;
            }
            c1 = a1;
        }
    }
    return 0;
}