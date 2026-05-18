#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        int r1, r2;
        scanf("%d %d", &r1, &r2);
        printf("%d\n", r1+r2);
    }
    
    return 0;
}