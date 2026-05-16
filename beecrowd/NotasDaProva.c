#include <stdio.h>

int main ()
{
    int nota;
    scanf("%d", &nota);

    if (!nota) {
        puts("E");
        return 0;
    }
    if (nota<=35) {
        puts("D");
        return 0;
    }
    if (nota<=60) {
        puts("C");
        return 0;
    }
    if (nota<=85) {
        puts("B");
        return 0;
    }
    puts("A");

    return 0;
}