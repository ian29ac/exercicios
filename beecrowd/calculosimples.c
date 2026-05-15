#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int num;
    float valor;
} Peca;

int main ()
{
    Peca * peca1 = malloc(sizeof(Peca));
    Peca * peca2 = malloc(sizeof(Peca));

    scanf("%d %d %f", &peca1->codigo, &peca1->num, &peca1->valor);
    scanf("%d %d %f", &peca2->codigo, &peca2->num, &peca2->valor);

    float pagar = peca1->num*peca1->valor + peca2->num*peca2->valor;
    
    printf("VALOR A PAGAR: R$ %.2f\n", pagar);
    
    return 0;
}