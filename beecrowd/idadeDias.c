#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    int anos = n/365;
    n %= 365;
    
    int meses = n/30;
    n %= 30;

    int dias = n % 30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
    
    return 0;
}