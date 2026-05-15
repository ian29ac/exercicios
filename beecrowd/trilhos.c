#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pilha {
    int * cont;
    int qtd;
    int cap;
} Pilha;

Pilha * criarPilha (int reserva) {
    Pilha * p = (Pilha*)malloc(sizeof(Pilha));
    p->cont = (int*)malloc(sizeof(int) * reserva);
    p->cap = reserva;
    p->qtd = 0;
    return p;
}

bool estaVazia (Pilha * pilha) {
    return !pilha->qtd;
}

bool estaCheia (Pilha * pilha) {
    return pilha->qtd == pilha->cap;
}

void _reserve (Pilha * pilha) {
    pilha->cap *= 2;
    pilha->cont = realloc(pilha->cont, sizeof(int) * pilha->cap);
}

void push (Pilha * pilha, int valor) {
    if(estaCheia(pilha)) _reserve(pilha);

    pilha->cont[pilha->qtd++] = valor;
}

int pop (Pilha * pilha) {
    if(estaVazia(pilha)) return 0;
    return pilha->cont[--pilha->qtd];
}

int peek (Pilha * pilha) {
    if(estaVazia(pilha)) return 0;
    return pilha->cont[pilha->qtd-1];
}

int main ()
{
    int qtd;

    while(scanf("%d", &qtd) && qtd) {
        bool acabou = false;

        while (!acabou) {
            int entrada[qtd];
            int saida[qtd];

            for (int i=0; i<qtd; i++) {
                entrada[i] = i+1;
            }
            for (int i=0; i<qtd; i++) {
                scanf("%d", &saida[i]);
                if (!saida[i]) {
                    acabou = true;
                    puts("");
                    break;
                }
            }
            if (acabou) break;

            Pilha * p = criarPilha(100);
            int i=0, j=0;

            while(j<qtd) {
                if (i>=qtd) {
                    if(pop(p)==saida[j++]) {
                        continue;
                    }
                    break;
                }
                if (entrada[i]==saida[j]) {
                    i++, j++;
                    continue;
                }
                if (peek(p)==saida[j]) {
                    j++;
                    pop(p);
                    continue;
                }
                push(p, entrada[i++]);
            }

            if(!estaVazia(p)) {
                puts("No");
                continue;
            }
            puts("Yes");
        }
    }
    return 0;
}