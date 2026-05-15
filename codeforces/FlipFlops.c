#include <stdio.h>
#include <stdlib.h>

void mataGeral (long long * poder, int * pwr, int monstros, int * chinelos)
{
    for (int i=0; i<monstros; i++) {
        if (pwr[i]==-1 || pwr[i]>*poder) {
            continue;
        }
            
        *chinelos > (*poder-pwr[i]) ? ( *chinelos -= (*poder-pwr[i]), *poder *= 2 ) : ( *poder += pwr[i]+*chinelos , *chinelos = 0 );
        pwr[i] = -1;

        mataGeral(poder, pwr, i, chinelos);
    }
    
}

int main ()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int monstros, chinelos;
        long long poder;
        scanf("%d %lld %d", &monstros, &poder, &chinelos);

        int pwr[monstros];

        for(int i=0; i<monstros; i++) {
            scanf("%d", &pwr[i]);
        }

        mataGeral(&poder, pwr, monstros, &chinelos);

        printf("%lld\n", poder);
    }
    
    return 0;
}
