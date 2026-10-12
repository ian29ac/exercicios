#include <stdio.h>

int main ()
{
    unsigned int a, b;
    while (scanf("%u %u", &a, &b) != EOF) {
        unsigned int soma = a ^ b;

        printf("%u\n", soma);
    }
    
    return 0;
}