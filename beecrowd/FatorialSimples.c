#include <stdio.h>

int fatorial (int n) {
    int aux = n-1;
    while (aux) {
        n *= aux;
        aux--;
    }

    return n;
}

int main ()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", fatorial(n));   
    
    return 0;
}