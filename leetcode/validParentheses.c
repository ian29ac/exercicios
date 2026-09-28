#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha {
    char * cont;
    int cap;
    int qtd;
} Pilha;

Pilha * criarPilha(int tam)
{
    Pilha * p = (Pilha*)malloc(sizeof(Pilha));
    p->cont = (char*)malloc(sizeof(char)*tam);
    p->cap = tam;
    p->qtd = 0;

    return p;
}

void push(Pilha * p, char val)
{
    p->cont[p->qtd++] = val;
}

char pop(Pilha * p)
{
    return p->cont[--p->qtd];
}

bool isValid(char* s)
{

    Pilha * p = criarPilha(10000);

    while (*s) {

        if (*s == '(' || *s == '[' || *s == '{') {
            push(p,*s);
            s++;
            continue;
        }

        if (!p->qtd) return false;

        switch (*s) {
            case (')'): {
                if (pop(p) != '(') {
                    return false;
                }
                break;
            }
            case (']'): {
                if (pop(p) != '[') {
                    return false;
                }
                break;
            }
            case ('}'): {
                if (pop(p) != '{') {
                    return false;
                }
                break;
            }
        }
        s++;
    }

    if(p->qtd) return false;
    return true;
}

int main ()
{
    char s[] = "({{[]}})";

    printf("%d\n", isValid(s));
    
    
    return 0;
}