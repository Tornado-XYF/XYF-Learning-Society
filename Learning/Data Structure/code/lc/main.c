#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// int sumOf(int *nums , int n) {
//     int hash[101];
//     int i,sum =0;
//     memset(hash,0,sizeof(hash));//这个函数是将内存块中的每个字节设置为特定的值
//     //这里指在hash数组中，将sizeof（hash）个字节中填充值为0
//     for (i = 0;i < n;i++) {
//         ++hash[nums[i]];
//     }
// }

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int x;
    int hash[1000];
    memset(hash,0,sizeof(hash));
    hash[nums[0]] = 0;
    for(int i=0;i < numsSize;i++)
    {
        x = target - nums[i];
        if(hash(x) != 0) {
            int *ret = malloc(sizeof(int)*2);
            ret[0] = hash(x);
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        else {
            hash[nums[i]] = i;
        }
    }
    *returnSize = 0;
    return NULL;
}