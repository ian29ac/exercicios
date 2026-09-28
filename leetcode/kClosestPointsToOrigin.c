#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    double dist;
} Ponto;

typedef struct {
    Ponto * cont;
    int qtde;
    int cap;
} FilaPrioridade;

FilaPrioridade * criaPQ(int cap) {
    FilaPrioridade * pq = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    pq->cap = cap;
    pq->qtde = 0;
    pq->cont = (Ponto*)malloc(sizeof(Ponto) * cap);
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
    pq->cont = realloc(pq->cont, sizeof(Ponto) * pq->cap);
}

void troca(Ponto * a, Ponto * b) {
    Ponto aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleUp(FilaPrioridade * pq, int fiote) {
    if(!fiote) return;

    int pai = (fiote - 1) / 2;

    if(pq->cont[pai].dist <= pq->cont[fiote].dist) return;

    troca(&pq->cont[pai], &pq->cont[fiote]);
    bubbleUp(pq, pai);
}

void bubbleDown(FilaPrioridade * pq, int pai) {
    int fio1 = pai * 2 + 1;
    int fio2 = pai * 2 + 2;
    int menor = pai;

    if(fio1 < pq->qtde && pq->cont[menor].dist > pq->cont[fio1].dist) menor = fio1;
    if(fio2 < pq->qtde && pq->cont[menor].dist > pq->cont[fio2].dist) menor = fio2;

    if(menor == pai) return;

    troca(&pq->cont[menor], &pq->cont[pai]);
    bubbleDown(pq, menor);
}

void push(FilaPrioridade * pq, Ponto valor) {
    if(estaCheia(pq)) reserve(pq);
    pq->cont[pq->qtde] = valor;
    bubbleUp(pq, pq->qtde++);
}

Ponto pop(FilaPrioridade * pq) {
    if(estaVazia(pq)) return (Ponto){.x=0, .y=0, .dist=0};
    Ponto valor = pq->cont[0];
    pq->cont[0] = pq->cont[--pq->qtde];
    bubbleDown(pq, 0);
    return valor;
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = k;
    *returnColumnSizes = pointsColSize;

    int ** mat = malloc(sizeof(int*)*k);
    for (int i=0; i<k; i++) {
        mat[i] = malloc(sizeof(int)*2);
    }

    FilaPrioridade * pq = criaPQ(100);

    for (int i=0; i<pointsSize; i++) {
        push(pq, (Ponto){.x=points[i][0], .y=points[i][1], .dist=sqrt(pow(points[i][0], 2) + pow(points[i][1], 2))});
    }

    for (int i=0; i<k; i++) {
        Ponto pontinho = pop(pq);
        mat[i][0] = pontinho.x;
        mat[i][1] = pontinho.y;
    }

    return mat;
}