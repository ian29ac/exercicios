#include <stdio.h>

int main ()
{
    int copos[4];
    for (int i=0; i<4; i++) {
        scanf("%d", &copos[i]);
        if (copos[i]) printf("%d\n", i+1);
    }
    
    return 0;
}