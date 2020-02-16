#include <stdio.h>
int *twoSum(int *nums, int numsSize, int target, int *returnSize);
int main(void)
{
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i = 0, j, len, *arr;
    len = sizeof(nums) - 1;
    for (; i < len; i++)
    {
        for (j = i + 1; j <= len; j++)
        {
            if (nums[i] + nums[j] == target)
                break;
        }
    }
    arr = malloc(2 * sizeof(int));
    arr[0] = i;
    arr[1] = j;
    return arr;
}