#include <stdio.h>
#include <string.h>

void desloca3 (char * texto, int tam)
{
    for(int i=0; i<tam; i++) {
        if (texto[i] < 'A' || (texto[i]> 'Z' && texto[i]<'a') || texto[i]>'z') continue;
        texto[i] += 3;
    }
}

void inverte (char * texto, int tam)
{
    int i=0, j=tam-1;
    char aux;
    while (i<j) {
        aux = texto[i];
        texto[i] = texto[j];
        texto[j] = aux;
        i++;
        j--;
    }
}

void deslocaMetade (char * texto, int tam)
{
    for (int i=tam/2; i<tam; i++) {
        texto[i] -= 1;
    }
}


int main ()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        getchar();
        char texto[1001];
        scanf("%[^\n]", texto);
        int tam = strlen(texto);

        desloca3(texto, tam);
        inverte(texto, tam);
        deslocaMetade(texto, tam);
        
        printf("%s\n", texto);
    }
    
    
    return 0;
}