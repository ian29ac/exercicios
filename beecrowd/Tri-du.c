#include <stdio.h>
#include <stdlib.h>

int max (int a, int b) {
    return (a+b+abs(a-b))/2;
}

int main ()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", max(a,b));
    
    return 0;
}