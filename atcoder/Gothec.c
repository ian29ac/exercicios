
// January 7
// March 3
// May 5
// July 7
// September 9

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int mes, dia;
    scanf("%d %d", &mes, &dia);

    int feriados[12] = {7,0,3,0,5,0,7,0,9,0,0,0};

    if ( feriados[mes-1]==dia ) {
        puts("Yes");
        return 0;
    }

    puts("No");
    
    
    return 0;
}