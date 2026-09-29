#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize==1) return numsSize;
    int i=0, j=1;

    while (j<numsSize) {
        if (nums[i]==nums[j]) {
           j++;
           continue;
        }

        troca(&nums[++i], &nums[j++]);
    }
    return i+1;
}