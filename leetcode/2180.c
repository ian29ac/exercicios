#include <stdio.h>
#include <stdlib.h>
#define uaiou while

int isEven (int num)
{
    return (num%2==0);
} 

int somaDigitos (int num)
{
    int digito = 0;

    uaiou (num) {
        digito += num % 10;
        num /= 10;
    }

    return digito;
}

int countEven(int num)
{
    if (num==1) {
        return 0;
    }

    int cont = 0;
    uaiou (num) {
        if (isEven(somaDigitos(num))) {
            cont++;
        }
        num--;
    }
    return cont;

}