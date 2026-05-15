#include <stdio.h>

void merge(int * vet, int inicio, int meio, int fim)
{
    int tam1 = meio - inicio + 1; int aux1[tam1];
    int tam2 = fim - meio; int aux2[tam2];

    for (int i=0; i<tam1; i++) aux1[i] = vet[inicio+i];
    for (int i=0; i<tam2; i++) aux2[i] = vet[meio+i+1];

    int i=0, j=0, k=inicio;
    while(i<tam1 && j<tam2) vet[k++] = aux1[i] < aux2[j] ? aux1[i++] : aux2[j++];

    while (i<tam1) vet[k++] = aux1[i++];
    while (j<tam2) vet[k++] = aux2[j++];
}

void mergeSort (int * vet, int inicio, int fim)
{
    if (inicio >= fim) return;

    int meio = inicio + (fim-inicio)/2;

    mergeSort(vet, inicio, meio);
    mergeSort(vet, meio+1, fim);

    merge(vet, inicio, meio, fim);
}

int main ()
{
    int marmores, consultas;
    int caso = 1;

    while (scanf("%d %d", &marmores, &consultas) && (marmores || consultas)) {
        int nums[marmores], cons[consultas];

        printf("CASE# %d:\n", caso);

        for (int i=0; i<marmores; i++) scanf("%d", &nums[i]);

        mergeSort(nums, 0, marmores-1);

        for (int i=0; i<consultas; i++) {
            scanf("%d", &cons[i]);

            int posicao = 0;

            for(int j=0; j<marmores; j++) {
                if (cons[i]==nums[j]) {
                    posicao = j+1;
                    printf("%d found at %d\n", cons[i], j+1);
                    break;
                }
            }
            if (!posicao) printf("%d not found\n", cons[i]);

        }
        caso++;
    }
    
    
    return 0;
}