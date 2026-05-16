#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    int tempo, vel, dist = 0;
    while (n--) {
        scanf("%d %d", &tempo, &vel);
        dist += tempo * vel;
    }

    printf("%d\n", dist);    
    
    return 0;
}