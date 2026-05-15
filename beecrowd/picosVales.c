#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    
    int val[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &val[i]);
    }

    int anteriorVale;

    if (val[0]==val[1]) {
        puts("0");
        return 0;
    }

    anteriorVale = val[0] < val[1];

    for (int i=1; i<n-1; i++) {
        int atPico = val[i] > val[i+1];
        if ( (val[i]==val[i+1]) || (!anteriorVale && atPico) || (anteriorVale && !atPico)) {
            puts("0");
            return 0;
        }
        anteriorVale = !anteriorVale;
    }

    puts("1");

    return 0;
}