#include <stdio.h>

int main ()
{
    int nota1, media;
    scanf("%d %d", &nota1, &media);

    int nota2 = 2*media - nota1;
    printf("%d\n", nota2);    
    
    return 0;
}