#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    int horas = n/3600;
    n %= 3600;

    int minutos = n/60;
    n %= 60;

    int segundos = n%60;

    printf("%d:%d:%d\n", horas, minutos, segundos);
    
    return 0;
}