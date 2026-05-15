#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int score;
    int posicao;
    int ordem;
} Atleta;

typedef struct {
    Atleta * cont;
    int qtde;
    int cap;
} FilaPrioridade;

FilaPrioridade * criaPQ(int cap) {
    FilaPrioridade * pq = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    pq->cap = cap;
    pq->qtde = 0;
    pq->cont = (Atleta*)malloc(sizeof(Atleta) * cap);
    return pq;
}

bool estaCheia(FilaPrioridade * pq) {
    return pq->qtde == pq->cap;
}

bool estaVazia(FilaPrioridade * pq) {
    return !pq->qtde;
}

void reserve(FilaPrioridade * pq) {
    pq->cap *= 2;
    pq->cont = realloc(pq->cont, sizeof(Atleta) * pq->cap);
}

void troca(Atleta * a, Atleta * b) {
    Atleta aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleUp(FilaPrioridade * pq, int fiote) {
    if(!fiote) return;

    int pai = (fiote - 1) / 2;

    if(pq->cont[pai].score > pq->cont[fiote].score) return;

    troca(&pq->cont[pai], &pq->cont[fiote]);
    bubbleUp(pq, pai);
}

void bubbleDown(FilaPrioridade * pq, int pai) {
    int fio1 = pai * 2 + 1;
    int fio2 = pai * 2 + 2;
    int maior = pai;

    if(fio1 < pq->qtde && pq->cont[maior].score < pq->cont[fio1].score) maior = fio1;
    if(fio2 < pq->qtde && pq->cont[maior].score < pq->cont[fio2].score) maior = fio2;

    if(maior == pai) return;

    troca(&pq->cont[maior], &pq->cont[pai]);
    bubbleDown(pq, maior);
}

void push(FilaPrioridade * pq, Atleta valor) {
    if(estaCheia(pq)) reserve(pq);
    pq->cont[pq->qtde] = valor;
    bubbleUp(pq, pq->qtde++);
}

Atleta pop(FilaPrioridade * pq) {
    if(estaVazia(pq)) return (Atleta){-1,-1};
    Atleta valor = pq->cont[0];
    pq->cont[0] = pq->cont[--pq->qtde];
    bubbleDown(pq, 0);
    return valor;
}

int divide (Atleta * vet, int low, int high) {
    Atleta pivo = vet[high];
    int amarelo = low-1;

    for (int verde=low; verde<high; verde++) {
        if (vet[verde].ordem >= pivo.ordem) continue;
        troca(&vet[verde], &vet[++amarelo]);
    }
    troca(&vet[++amarelo], &vet[high]);

    return amarelo;
}

void quickSort (Atleta * vet, int low, int high) {
    if (low >= high) return;
    int pivo = divide(vet, low, high);

    quickSort(vet, low, pivo-1);
    quickSort(vet, pivo+1, high);
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    char ** rel = (char**)malloc(sizeof(char*)*scoreSize);

    FilaPrioridade * pq = criaPQ(100);
    for (int i=0; i<scoreSize; i++) {
        push(pq, (Atleta){.score = score[i], .ordem = i+1});
    }

    Atleta * at = malloc(sizeof(Atleta)*(*returnSize));
    for (int i=0; i<scoreSize; i++) {
        at[i] = pop(pq);
        at[i].posicao = i+1;
    }

    quickSort(at, 0, scoreSize-1);

    for (int i=0; i< scoreSize; i++) {
        switch (at[i].posicao) {
            case 1:
            rel[i] = malloc(sizeof(char)*11);
            rel[i] = "Gold Medal";
            break;

            case 2:
            rel[i] = malloc(sizeof(char)*13);
            rel[i] = "Silver Medal";
            break;

            case 3:
            rel[i] = malloc(sizeof(char)*13);
            rel[i] = "Bronze Medal";
            break;

            default:
            rel[i] = malloc(sizeof(char)*5);
            sprintf(rel[i], "%d", at[i].posicao);
        }
    }
    return rel;
}