#include <stdio.h>

int main ()
{
    int dist, tam;
    scanf("%d %d", &dist, &tam);

    printf("%d\n", dist%tam);
    
    return 0;
}