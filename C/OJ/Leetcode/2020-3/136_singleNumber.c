//result Time 20ms 40%, Memory 5.3mb 100%
//2x1 loop unrolling, but it is 2times slower... I don't know why.
int singleNumber(int *nums, int numsSize)
{
    int ans = nums[0], i;
    for (i = 1; i < numsSize; i += 2)
    {
        ans ^= nums[i];
        ans ^= nums[i + 1];
    }
    if (i != numsSize)
        ans ^= nums[i + 1];
    return ans;
}

//oringinal Ver.
///result Time 8ms 99%, Memory 6.6mb 100%
int singleNumber2(int *nums, int numsSize)
{
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}