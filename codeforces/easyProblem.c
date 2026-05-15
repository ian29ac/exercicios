#include <stdio.h>

int main ()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int i;
        scanf("%d", &i);
        
        printf("%d\n", i-1);
    }
    
    
    return 0;
}