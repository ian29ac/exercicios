#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int pessoas;
    int consumo;
    int consumoMedio;
} Imovel;

void merge (Imovel * vet, int inicio, int meio, int fim)
{
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;

    Imovel *aux1 = malloc(tam1 * sizeof(Imovel));
    Imovel *aux2 = malloc(tam2 * sizeof(Imovel));

    for (int i=0; i<tam1; i++) {
        aux1[i] = vet[inicio+i];
    }
    
    for (int i=0; i<tam2; i++) {
        aux2[i] = vet[meio+i+1];
    }
    
    int i=0, j=0, k=inicio;

    while (i<tam1 && j<tam2) vet[k++] = aux1[i].consumoMedio<aux2[j].consumoMedio ? aux1[i++] : aux2[j++];

    while (i<tam1) vet[k++] = aux1[i++];
    while (j<tam2) vet[k++] = aux2[j++];

    free(aux1);
    free(aux2);
}

void mergeSort (Imovel * vet, int inicio, int fim)
{
    if (inicio>=fim) return;

    int meio = inicio + (fim-inicio)/2;

    mergeSort(vet, inicio, meio);
    mergeSort(vet, meio+1, fim);

    merge(vet, inicio, meio, fim);
}


int main() {
    int numImoveis, cid = 1;

    while (scanf("%d", &numImoveis) && numImoveis) {

        if (cid != 1) puts("");

        Imovel * imoveis = malloc(numImoveis * sizeof(Imovel));

        double consMedio = 0;
        int pessoas = 0;

        for (int i = 0; i < numImoveis; i++) {
            scanf("%d %d", &imoveis[i].pessoas, &imoveis[i].consumo);
            consMedio += imoveis[i].consumo;
            pessoas += imoveis[i].pessoas;
            imoveis[i].consumoMedio = imoveis[i].consumo / imoveis[i].pessoas;
        }

        mergeSort(imoveis, 0, numImoveis - 1);

        for (int i=0; i<numImoveis-1; i++) {
            if (imoveis[i].consumoMedio == imoveis[i+1].consumoMedio) {
                imoveis[i+1].pessoas += imoveis[i].pessoas;
                imoveis[i].pessoas = 0;
            }
        }



        printf("Cidade# %d:\n", cid);

        for (int i = 0; i < numImoveis; i++) {
            if (!imoveis[i].pessoas) continue;

            printf("%d-%d%c", imoveis[i].pessoas, imoveis[i].consumoMedio, " \n"[i == numImoveis - 1]);
        }

        consMedio /= pessoas;
        consMedio = floor(consMedio * 100) / 100.0;

        printf("Consumo medio: %.2lf m3.\n", consMedio);

        free(imoveis);
        cid++;
    }

    return 0;
}