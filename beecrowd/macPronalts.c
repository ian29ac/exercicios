#include <stdio.h>

int main ()
{
    float precos[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int n; scanf("%d", &n);
    float preco = 0;

    while(n--) {
        int produto, qtd;
        scanf("%d %d", &produto, &qtd);

        preco += precos[produto-1001] * qtd;
    }

    printf("%.2f\n", preco);
    
    return 0;
}