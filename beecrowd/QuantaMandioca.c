#include <stdio.h>

int main ()
{
    int porcoes[] = {300,1500,600,1000,150};
    int mandioca = 225;

    for (int i=0; i<5; i++) {
        int qtd;
        scanf("%d", &qtd);

        mandioca += qtd * porcoes[i];
    }

    printf("%d\n", mandioca);
    
    return 0;
}