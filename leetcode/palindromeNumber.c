#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    
    if (x<0) return false;

    long contrario = 0;
    long pedaco = x;
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