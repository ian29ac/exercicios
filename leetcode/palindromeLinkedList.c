#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} No;

typedef struct Pilha {
    int * cont;
    int qtde;
    int cap;
} Pilha;

Pilha * criarPilha(int reserva);
bool estaVazia(Pilha * pilha);
bool estaCheia(Pilha * pilha);
void _reserve(Pilha * pilha);
void push(Pilha * pilha, int valor);
int pop(Pilha * pilha);

Pilha * criarPilha(int reserva) {
    Pilha * p = (Pilha*)malloc(sizeof(Pilha));
    p->cont = (int*)malloc(sizeof(int) * reserva);
    p->cap = reserva;
    p->qtde = 0;
    return p;
}

bool estaVazia(Pilha * pilha) {
    return !pilha->qtde;
}

bool estaCheia(Pilha * pilha) {
    return pilha->qtde == pilha->cap;
}

void _reserve(Pilha * pilha) {
    pilha->cap *= 2;
    pilha->cont = realloc(pilha->cont, sizeof(int) * pilha->cap);
}

void push(Pilha * pilha, int valor) {
    if(estaCheia(pilha)) _reserve(pilha);

    pilha->cont[pilha->qtde++] = valor;
}

int pop(Pilha * pilha) {
    if(estaVazia(pilha)) return 0;
    return pilha->cont[--pilha->qtde];
}

bool isPalindrome(struct ListNode* head) {
    if (head->next == NULL) return true;

    struct ListNode * no = head;
    Pilha * p = criarPilha(100);

    while(no!=NULL) {
        push(p, no->val);
        no = no->next;
    }
    while(head!=NULL) {
        if(head->val==pop(p)) {
            head = head->next;
            continue;
        }
        return false;
    }
    return true;
}