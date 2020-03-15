
int missingNumber(int *nums, int numsSize)
{
    int ans = 0, sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    ans = ((1 + numsSize) * numsSize) / 2;
    return ans - sum;
}