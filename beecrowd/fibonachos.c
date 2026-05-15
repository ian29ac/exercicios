#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    long long fibo[61];
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i=2; i< 61; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    while (n--) {
        int i;
        scanf("%d", &i);

        printf("Fib(%d) = %lld\n", i, fibo[i]);
    }
    
    return 0;
}