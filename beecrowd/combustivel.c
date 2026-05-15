#include <stdio.h>
#define CONSUMO 12
 
int main() {
 
    int tempo, vel;
    scanf("%d %d", &tempo, &vel);
    
    float comb = tempo*vel/12.0;
    
    printf("%.3f\n", comb);
 
    return 0;
}