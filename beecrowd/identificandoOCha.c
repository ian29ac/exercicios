#include <stdio.h>

int main ()
{
    int cha;
    scanf("%d", &cha);

    int respostas[5], corretas=0;
    for (int i=0; i<5; i++) {
        scanf("%d", &respostas[i]);

        if (respostas[i]==cha) corretas++;
    }

    printf("%d\n", corretas);
    
    return 0;
}