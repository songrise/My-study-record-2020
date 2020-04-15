/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * 2);
    int a = 1;
    for (size_t i = 1; i < numsSize; i++)
    {
        a ^= i;
    }
    int b = nums[0];
    for (size_t i = 1; i < numsSize; i++)
    {
        b ^= nums[i];
    }
    ans[0] = b ^ a;
    ans[1] = b ^ a;
    return ans;
}