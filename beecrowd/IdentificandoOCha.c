#include <stdio.h>

int main ()
{
    int tipo;
    scanf("%d", &tipo);

    int respostas[5];
    int qtd = 0;
    for (int i=0; i<5; i++) {
        scanf("%d", &respostas[i]);
        if (respostas[i]==tipo) qtd++;
    }
    
    printf("%d\n", qtd);
    
    return 0;
}