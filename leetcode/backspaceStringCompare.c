#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char * cont;
    int capacidade;
    int qtd;
} Pilha;

bool pilhaVazia (Pilha * p) {
    return !p->qtd;
}

bool pilhaCheia (Pilha * p) {
    return (p->qtd == p->capacidade);
}

Pilha * criarPilha (int capacidade) {
    Pilha * pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->cont = (char*)malloc(sizeof(char)*capacidade);
    pilha->capacidade = capacidade;
    pilha->qtd = 0;

    return pilha;
}

void _reservePilha (Pilha * p) {
    p->capacidade *= 2;
    p->cont = realloc(p->cont, sizeof(char) * p->capacidade);
}

void push (Pilha * p, char val) {
    if (pilhaCheia(p)) _reservePilha(p);
    p->cont[p->qtd++] = val;
}

char pop (Pilha * p) {
    if (pilhaVazia(p)) return '^';
    return p->cont[--p->qtd];
}



bool backspaceCompare(char* s, char* t) {
    Pilha * pilha_s = criarPilha(200);
    Pilha * pilha_t = criarPilha(200);

    while(*s) {
        if (*s>='a' && *s<='z') {
            push(pilha_s, *s);
            s++;
            continue;
        }
        pop(pilha_s);
        s++;
    }
    while(*t) {
        if (*t>='a' && *t<='z') {
            push(pilha_t, *t);
            t++;
            continue;
        }
        pop(pilha_t);
        t++;
    }

    if (pilha_s->qtd != pilha_t->qtd) return false;

    while (pilha_s->qtd) {
        if (pop(pilha_s) != pop(pilha_t)) return false;
    }

    return true;

}

int main ()
{
    char s[] = "ab#c", t[] = "ad#c";
    char s1[] = "ab##", t1[] = "c#d#";
    char s2[] = "a#c", t2[] = "b";

    printf("%d\n", backspaceCompare(s,t));
    printf("%d\n", backspaceCompare(s1,t1));
    printf("%d\n", backspaceCompare(s2,t2));
    
    return 0;
}