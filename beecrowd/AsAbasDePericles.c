#include <stdio.h>

int main ()
{
    int abas, acoes;
    scanf("%d %d", &abas, &acoes);

    while (acoes--) {
        char acao[7];
        scanf("%s", acao);

        if (acao[0] == 'f') {
            abas++;
            continue;
        }
        abas--;
    }

    printf("%d\n", abas);    
    
    return 0;
}