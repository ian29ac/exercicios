#include <stdio.h>
#include <stdlib.h>

int somaDigitos (int num)
{
    if(num<10) {
        return num;
    }
    return num%10 + somaDigitos(num/10);

}

int addDigits(int num) {
    if ( num<10 ) {
        return num;
    }
    return addDigits(somaDigitos(num));
}

int main ()
{
    printf("%d\n", addDigits(472));
    
    
    return 0;
}