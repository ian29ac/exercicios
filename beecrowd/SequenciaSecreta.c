#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    int seq[n];

    scanf("%d", &seq[0]);

    int cont = 1;

    for (int i=1; i<n; i++) {
        scanf("%d", &seq[i]);
        if (seq[i]==seq[i-1]) continue;
        cont++;
    }

    printf("%d\n", cont);
    
    return 0;
}