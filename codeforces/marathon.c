#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a, b, c, d, n;

    scanf("%d", &n);

    while (n--) {

        int cont = 0;

        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        scanf("%d", &d);

        if(a<b) cont++;
        if(a<c) cont++;
        if(a<d) cont++;

        printf("%d\n", cont);

    }
    
    
    return 0;
}