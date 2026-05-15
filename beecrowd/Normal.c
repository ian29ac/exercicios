#include <stdio.h>
#include <string.h>

void inverterString (char * texto) {
    int i=0; int j=(int)strlen(texto)-1;
    char aux;

    while (i<j) {
        aux = texto[i];
        texto[i] = texto[j];
        texto[j] = aux;
        i++; j--;
    }
}

int main ()
{
    int t;
    scanf("%d", &t);

    char texto[101];

    while (t--) {
        scanf("%s", texto);

        inverterString(texto);

        for (int i=0; i<(int)strlen(texto); i++) {

            switch (texto[i]) {
                case ('p'): {
                    texto[i] = 'q';
                    break;
                }
                case('q'): {
                    texto[i] = 'p';
                    break;
                }
            }

            

        }
        printf("%s\n", texto);

    }
    
    
    return 0;
}