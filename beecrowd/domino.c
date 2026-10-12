#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    int duploN = ((n+1) * (n+2)) / 2;
    printf("%d\n", duploN);
    
    return 0;
}