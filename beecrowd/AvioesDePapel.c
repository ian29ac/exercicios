#include <stdio.h>

int main ()
{
    int comp, folhas, qtd;
    scanf("%d %d %d", &comp, &folhas, &qtd);

    if (comp*qtd > folhas) {
        puts("N");
        return 0;
    }
    puts("S");
    
    return 0;
}