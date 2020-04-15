

int totalHammingDistance(int *nums, int numsSize)
{
    register int sum = 0;
    for (size_t i = 0; i < 32; i++)
    {
        int count1 = 0;
        for (size_t j = 0; j < numsSize; j++)
        {
            count1 += ((nums[j] >> i) & 1);
        }
        sum += (numsSize - count1) * count1;
    }
    return sum;
}