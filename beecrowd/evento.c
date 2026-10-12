#include <stdio.h>

int main ()
{
    int n, m, exp;

    while (scanf("%d %d", &n, &m) && (n || m)) {
        exp = n * m;
        printf("%d\n", exp);
    }
    
    return 0;
}