#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int n;
    scanf("%d", &n);

    char string[n+1];

    scanf("%s", string);
    

    int i=0;
    while ( string[i]=='o' ) {
        i++;
    }

    char strRes[n-i+1];

    strncpy(strRes, string+i, n-i);
    strRes[n-i] = '\0';

    printf("%s\n", strRes);

    
    return 0;
}