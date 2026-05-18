#include <stdio.h>

int main ()
{
    int p1, c1, p2, c2;
    scanf("%d %d %d %d", &p1, &c1, &p2, &c2);

    int g1 = p1*c1, g2=p2*c2;
    if (g1<g2) {
        puts("1");
        return 0;
    }
    if (g1>g2) {
        puts("-1");
        return 0;
    }
    puts("0");    
    
    return 0;
}