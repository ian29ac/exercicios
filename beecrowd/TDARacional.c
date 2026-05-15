#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b)
{
    while (b) {
        int resto = a % b;
        a = b;
        b = resto;
    }

    return abs(a);
}

typedef struct fracao {
    int num;
    int den;
} Fracao;

Fracao simplificada (Fracao frac)
{
    int m = mdc(frac.num, frac.den);
    frac.num /= m; frac.den /= m;

    return frac;
}


int main ()
{
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        char op;
        Fracao f1, f2, fRes;


        scanf("%d / %d %c %d / %d", &f1.num, &f1.den, &op, &f2.num, &f2.den);
        
        switch (op) {
            case ('+'): {
                fRes.num = f1.num*f2.den + f2.num*f1.den;
                fRes.den = f1.den * f2.den;

                break;
            }
            case ('-'): {
                fRes.num = f1.num*f2.den - f2.num*f1.den;
                fRes.den = f1.den * f2.den;

                break;
            }
            case('*'): {
                fRes.num = f1.num * f2.num;
                fRes.den = f1.den * f2.den;

                break;
            }
            case ('/'): {

                int aux = f2.num;
                f2.num = f2.den;
                f2.den = aux;

                fRes.num = f1.num * f2.num;
                fRes.den = f1.den * f2.den;

                break;
            }
        }

        printf("%d/%d = %d/%d\n", fRes.num, fRes.den, simplificada(fRes).num, simplificada(fRes).den);

    }

    return 0;
}