#include <stdio.h>

int main ()
{
    char texto[50] = "AMO FAZER EXERCICIO NO URI";

    printf("<%s>\n", texto);
    printf("<%30s>\n", texto);
    printf("<%.20s>\n", texto);
    printf("<%-20s>\n", texto);
    printf("<%-30s>\n", texto);
    printf("<%.30s>\n", texto);
    printf("<%30.20s>\n", texto);
    printf("<%-30.20s>\n", texto);

    return 0;
}