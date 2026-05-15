#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    
    if (x<0) return false;

    int contrario = 0;
    int pedaco = x;
    int digito;

    while ( pedaco > 0 ) {

        digito = pedaco % 10;
        contrario = contrario * 10 + digito;
        pedaco /= 10;

    }

    return (contrario==x);
}

int main ()
{
    printf("%d\n", isPalindrome(872));
    printf("%d\n", isPalindrome(-1221));
    
    
    return 0;
}