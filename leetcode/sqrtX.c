#include <stdio.h>

int mySqrt(int x) {
    if (x < 2) return x;

    int raiz = 1;
    while(1) {
        if ((raiz+1)*(raiz+1)>x) return raiz;
        raiz++;
    }

    return raiz;
}