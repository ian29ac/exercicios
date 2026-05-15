#include <stdio.h>
#include <math.h>

int main ()
{
    float n;
    scanf("%f", &n);
    int c = round(n*100);

    int centavos[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};


    puts("NOTAS:");
    for (int i=0; i< 6; i++) {
        int val = c/centavos[i];
        c %= centavos[i];
        printf("%d nota(s) de R$ %.2f\n", val, centavos[i]/100.0);

    }

    puts("MOEDAS:");
    for (int i=6; i< 12; i++) {
        int val = c/centavos[i];
        c %= centavos[i];
        printf("%d moeda(s) de R$ %.2f\n", val, centavos[i]/100.0);
    }

    return 0;
}