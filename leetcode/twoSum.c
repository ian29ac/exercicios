#include <stdbool.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int * vet = malloc(sizeof(int)*2);
    bool achou = false;

    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i]+nums[j] == target) {
                vet[0] = i;
                vet[1] = j;
                achou = true;
                break;
            }
        }
        if (achou) break;
    }

    return vet;
}
