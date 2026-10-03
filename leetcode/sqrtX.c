#include <stdio.h>

int mySqrt(int x) {
    if (x < 2) return x;

    long raiz = 1;
    while (raiz*raiz < x) {
        if ( (raiz+1) * (raiz+1) > x) return raiz;
        raiz++;
    }

    return raiz;
}