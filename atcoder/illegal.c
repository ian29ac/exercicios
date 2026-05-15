#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char estringue[11];
    scanf("%s", estringue);


    int i=0;
    while ( estringue[i] != '\0' ) {
        i++;
    }

    if ( i%5 == 0 ) {
        puts("Yes");
        return 0;
    }

    puts("No");

    return 0;
}