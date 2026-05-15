#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        int pares = n/2;
        int * sobras = calloc(31, sizeof(int));

        while (n--) {
            int numero;
            char lado;
            scanf("%d %c", &numero, &lado);
            
            if (lado=='E') {
                sobras[numero-30]--;
                continue;
            }
            sobras[numero-30]++;
        }

        int solteiras = 0;
        for (int i=0; i<31; i++) {
            solteiras += abs(sobras[i]);
        }

        pares -= solteiras/2;
        printf("%d\n", pares);
    }

    return 0;
}