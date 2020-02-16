

int removeDuplicates(int *nums, int numsSize)
{
    int i = 0, j = 0, k = 0;
    if (numsSize == 0)
        return 0;
    else
    {
        for (; j <= numsSize - 1; j++)
        {
            if (nums[k] != nums[j])
            {
                i += 1;
                nums[i] = nums[j];
                k = j;
            }
        }
        return i + 1;
    }
}
