#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int nPes, nDep;
    scanf("%d", &nPes);
    scanf("%d", &nDep);

    int matPes[nPes][2];

    for(int i=0; i<nPes; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &matPes[i][j]);
        }
    }

    int matDep[2][nDep];

    for(int i=0; i<2; i++) {
        for (int j=0; j<nDep; j++) {
            matDep[i][j] = 0;
        }
    }


    for(int i=0; i<2; i++) {

        for (int j=0; j<nDep; j++) {
            
            for (int k=0; k<nPes; k++) {

                if ( matPes[k][i]==j+1 ) {

                    matDep[i][j]++;
                }

            }
            
        }

    }

    int vetFinal[nDep];

    for (int i=0; i<nDep; i++) {
        vetFinal[i] = matDep[1][i] - matDep[0][i];
        printf("%d\n", vetFinal[i]);
    }

    return 0;
}